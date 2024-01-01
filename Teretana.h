//
// Created by farex on 12/26/2023.
//

#ifndef PROJEKAT_TERETANA_H
#define PROJEKAT_TERETANA_H
#include <vector>
#include "Radnici.h"
#include "Korisnik.h"

const int brOrmarica = 30;

class Teretana {
public:
    std::vector<Korisnik> korisnici;
    std::vector<Radnici> radnici;
    std::vector<int> kljucevi;
    int brZauzetih;

    void ucitajIzFajla();
    void ispisiKorisinke();
    void stanjeTeretane();

    void dajKljuc();
    void uzmiKljuc();
    void ispisOrmarica();
    Teretana(){
        brZauzetih = 0;
    }
};

#endif //PROJEKAT_TERETANA_H
