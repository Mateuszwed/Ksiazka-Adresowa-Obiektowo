#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H


#include <iostream>
#include <vector>
#include <windows.h>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikiZAdresatami.h"

class AdresatMenedzer{


vector <Adresat> adresaci;

PlikiZAdresatami plikiZAdresatami;


public:

AdresatMenedzer(string nazwaPlikuZAdresatami) : plikiZAdresatami(nazwaPlikuZAdresatami) {}

char wybierzOpcjeZMenuUzytkownika();
Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
int pobierzZPlikuIdOstatniegoAdresata();


};

#endif
