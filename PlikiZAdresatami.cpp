#include "PlikiZAdresatami.h"


void PlikiZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {

    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system("pause");
}


string PlikiZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {

    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}


bool PlikiZAdresatami::czyPlikJestPusty(fstream &plikTekstowy) {

    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}


int PlikiZAdresatami::pobierzZPlikuIdOstatniegoAdresata() {

    idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return idOstatniegoAdresata;
}


int PlikiZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {

    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}


vector<Adresat> PlikiZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {

    Adresat adresat;
    vector<Adresat> adresaci;
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return adresaci;
    } else
        return adresaci;
}


Adresat PlikiZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {

    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}


int PlikiZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {

    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

/*
void PlikiZAdresatami::usuwanieAdresataZPliku(int idUsuwanegoAdresata) {

    fstream plikTekstowy;
    fstream pomocniczyPlikTekstowy;

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI, ios::in);
    pomocniczyPlikTekstowy.open(NAZWA_POMOCNICZEGO_PLIKU_Z_ADRESATAMI, ios::out);
    if (plikTekstowy.good() && pomocniczyPlikTekstowy.good()) {
        string wczytanaLinia;
        while (getline(plikTekstowy, wczytanaLinia)) {
            if (wczytanaLinia[0] - '0' == idUsuwanegoAdresata)
                continue;
            pomoc << wczytanaLinia << endl;
        }
    }
    plikTekstowy.close();
    plikTekstowy.clear();
    pomocniczyPlikTekstowy.close();
    pomocniczyPlikTekstowy.clear();
    remove(NAZWA_PLIKU_Z_ADRESATAMI.c_str());
    rename(NAZWA_POMOCNICZEGO_PLIKU_Z_ADRESATAMI.c_str(), NAZWA_PLIKU_Z_ADRESATAMI.c_str());
}
*/

void PlikiZAdresatami::usuwanieAdresataZPliku(int idUsuwanegoAdresata) {

    fstream plikTekstowy;
    fstream pomocniczyPlikTekstowy;

    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;
    int pobraneId = 0;
    int numerUsuwanejLinii = 0;

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    pomocniczyPlikTekstowy.open(NAZWA_POMOCNICZEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, wczytanaLinia))
        {
            pobraneId = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
            if (pobraneId != idUsuwanegoAdresata)
                idOstatniegoAdresata = pobraneId;
            if (idUsuwanegoAdresata == pobraneId)
                {
                    numerUsuwanejLinii = numerWczytanejLinii;
                }
            else if (numerWczytanejLinii == 1 && idUsuwanegoAdresata != pobraneId)
                pomocniczyPlikTekstowy << wczytanaLinia;
            else if (numerWczytanejLinii == 2 && numerUsuwanejLinii == 1)
                pomocniczyPlikTekstowy << wczytanaLinia;
            else if (numerWczytanejLinii > 2 && numerUsuwanejLinii == 1)
                pomocniczyPlikTekstowy << endl << wczytanaLinia;
            else if (numerWczytanejLinii > 1 && numerUsuwanejLinii != 1)
                pomocniczyPlikTekstowy << endl << wczytanaLinia;
            numerWczytanejLinii++;
        }
    plikTekstowy.close();
    plikTekstowy.clear();
    pomocniczyPlikTekstowy.close();
    pomocniczyPlikTekstowy.clear();
    remove(NAZWA_PLIKU_Z_ADRESATAMI.c_str());
    rename(NAZWA_POMOCNICZEGO_PLIKU_Z_ADRESATAMI.c_str(), NAZWA_PLIKU_Z_ADRESATAMI.c_str());
    }
}
