#include "KsiazkaAdresowa.h"



char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}



void KsiazkaAdresowa::menuGlowneProgramu()
{
    char wybor;
    int idZalogowanegoUzytkownika = 0;

    while (true)
    {
        if (idZalogowanegoUzytkownika == 0)
        {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                uzytkownikMenedzer.rejestracjaUzytkownika();
                break;
            case '2':
                idZalogowanegoUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();
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
        else
        {
            /*
            if (adresatMenadzer.pobierzAdresaci()->empty() == true)
            {
                // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
                adresatMenadzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
            }
*/
            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika, adresatMenedzer.pobierzZPlikuIdOstatniegoAdresata());
                break;
            case '2':
                //adresatMenadzer.wyszukajPoImieniu();
                break;
            case '3':
                //adresatMenadzer.wyszukajPoNazwisku();
                break;
            case '4':
                //adresatMenadzer.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //adresatMenadzer.ustawIdOstatniegoAdresata(adresatMenadzer.usunAdresata());
                //adresatMenadzer.usunAdresata(uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
                break;
            case '6':
                //adresatMenadzer.edytujAdresata();
                break;
            case '7':
                //uzytkownikMenadzer.zmianaHaslaUzytkownika();
                break;
            case '8':
                //uzytkownikMenadzer.ustawIdZalogowanegoUzytkownika(0);
                //adresatMenadzer.pobierzAdresaci()->clear();
                break;
            }
        }
    }

}


