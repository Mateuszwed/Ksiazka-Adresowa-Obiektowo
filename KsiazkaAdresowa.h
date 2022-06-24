#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa {

    char wybor;
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

    void rejestracjaUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    int pobierzZPlikuIdOstatniegoAdresata();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    bool sprawdzCzyVectorZAdresatamiJestPusty();
    void menuZalogowanegoUzytkownika();
    void menuNiezalogowanegoUzytkownika();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void usunAdresata();
    void edytujAdresata();

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        adresatMenedzer = NULL;
    };

    ~KsiazkaAdresowa() {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    };

    void menuGlowneProgramu();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();

};

#endif
