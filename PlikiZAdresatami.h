#ifndef PLIKIZADRESATAMI_H
#define PLIKIZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>


#include "Adresat.h"
#include "MetodyPomocnicze.h"


class PlikiZAdresatami {

    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_POMOCNICZEGO_PLIKU_Z_ADRESATAMI = "PlikPomocniczy.txt";

    int idOstatniegoAdresata;
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

    bool czyPlikJestPusty(fstream &plikTekstowy);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:
    PlikiZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {};

    void usuwanieAdresataZPliku(int idUsuwanegoAdresata);
    void dopiszAdresataDoPliku(Adresat adresat);
    int pobierzZPlikuIdOstatniegoAdresata();
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);

};

#endif
