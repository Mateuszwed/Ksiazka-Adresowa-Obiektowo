#include "KsiazkaAdresowa.h"


char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {

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



char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {

    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyswietl adresatow" << endl;
    cout << "---------------------------" << endl;
    cout << "3. Zmien haslo" << endl;
    cout << "4. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}



void KsiazkaAdresowa::menuGlowneProgramu() {

    char wybor;
    int idZalogowanegoUzytkownika = 0;

    while (true) {
        if (idZalogowanegoUzytkownika == 0) {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor) {
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
        } else {

            if (adresatMenedzer.sprawdzCzyVectorZAdresatamiJestPusty()) {
                adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
            }

            wybor = wybierzOpcjeZMenuUzytkownika();


            switch (wybor) {
            case '1':
                adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika, adresatMenedzer.pobierzZPlikuIdOstatniegoAdresata());
                break;
            case '2':
                adresatMenedzer.wyswietlWszystkichAdresatow();
                break;
            case '3':
                uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
                break;
            case '4':
                idZalogowanegoUzytkownika = 0;
                adresatMenedzer.wyczyscVector();
                break;

            }
        }
    }

}


