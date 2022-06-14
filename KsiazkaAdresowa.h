#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa{

UzytkownikMenedzer uzytkownikMenedzer;
AdresatMenedzer adresatMenedzer;

public:

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresatMenedzer(nazwaPlikuZAdresatami) {
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };


void menuGlowneProgramu();
char wybierzOpcjeZMenuGlownego();
char wybierzOpcjeZMenuUzytkownika();

};

#endif
