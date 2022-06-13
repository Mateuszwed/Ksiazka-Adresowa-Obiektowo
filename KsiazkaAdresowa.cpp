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


void KsiazkaAdresowa::menuGlowneProgramu()
{
    char wybor;

    while (true)
    {
        if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() == 0)
        {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                uzytkownikMenedzer.rejestracjaUzytkownika();
                break;
            case '2':
                uzytkownikMenedzer.logowanieUzytkownika();
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
        /*
        else
        {
            if (adresatMenadzer.pobierzAdresaci()->empty() == true)
            {
                // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
                adresatMenadzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
            }

            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                adresatMenadzer.ustawIdOstatniegoAdresata(adresatMenadzer.dodajAdresata(uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika(), adresatMenadzer.pobierzIdOstatniegoAdresata()));
                break;
            case '2':
                adresatMenadzer.wyszukajPoImieniu();
                break;
            case '3':
                adresatMenadzer.wyszukajPoNazwisku();
                break;
            case '4':
                adresatMenadzer.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //adresatMenadzer.ustawIdOstatniegoAdresata(adresatMenadzer.usunAdresata());
                adresatMenadzer.usunAdresata(uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
                break;
            case '6':
                adresatMenadzer.edytujAdresata();
                break;
            case '7':
                uzytkownikMenadzer.zmianaHaslaUzytkownika();
                break;
            case '8':
                uzytkownikMenadzer.ustawIdZalogowanegoUzytkownika(0);
                adresatMenadzer.pobierzAdresaci()->clear();
                break;
            }
        }
    }

    */
}
}

