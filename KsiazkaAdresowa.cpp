#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika() {

    uzytkownikMenedzer.rejestracjaUzytkownika();

}


int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {

    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();

}


void KsiazkaAdresowa::logowanieUzytkownika(){

    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()){

        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, pobierzIdZalogowanegoUzytkownika());
    }

}


int KsiazkaAdresowa::pobierzZPlikuIdOstatniegoAdresata() {

    return adresatMenedzer->pobierzZPlikuIdOstatniegoAdresata();

}


void KsiazkaAdresowa::dodajAdresata() {

    adresatMenedzer->dodajAdresata(pobierzIdZalogowanegoUzytkownika(), pobierzZPlikuIdOstatniegoAdresata());

}


void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {

    adresatMenedzer->wyswietlWszystkichAdresatow();

}


void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {

    adresatMenedzer->wczytajAdresatowZalogowanegoUzytkownikaZPliku(pobierzIdZalogowanegoUzytkownika());

}


bool KsiazkaAdresowa::sprawdzCzyVectorZAdresatamiJestPusty() {

    return adresatMenedzer->sprawdzCzyVectorZAdresatamiJestPusty();

}


void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {

    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(pobierzIdZalogowanegoUzytkownika());

}


char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {

    return uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
}


char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {

    return uzytkownikMenedzer.wybierzOpcjeZMenuUzytkownika();
}


void KsiazkaAdresowa::wylogowanieUzytkownika() {

    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;

}


void KsiazkaAdresowa::menuNiezalogowanegoUzytkownika() {

    switch (wybor) {
    case '1':
        rejestracjaUzytkownika();
        break;
    case '2':
        logowanieUzytkownika();
        break;
    case '9':
        exit(0);
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
        break;
    }

}


void KsiazkaAdresowa::menuZalogowanegoUzytkownika() {

    switch (wybor) {
    case '1':
        dodajAdresata();
        break;
    case '2':
        wyswietlWszystkichAdresatow();
        break;
    case '3':
        zmianaHaslaZalogowanegoUzytkownika();
        break;
    case '4':
        wylogowanieUzytkownika();
        break;

    }
}


void KsiazkaAdresowa::menuGlowneProgramu() {

    while (true) {
        if (!uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
            wybor = wybierzOpcjeZMenuGlownego();

            menuNiezalogowanegoUzytkownika();

        } else {

            if (sprawdzCzyVectorZAdresatamiJestPusty()) {
                wczytajAdresatowZalogowanegoUzytkownikaZPliku();
            }

            wybor = wybierzOpcjeZMenuUzytkownika();
            menuZalogowanegoUzytkownika();

        }
    }
}


