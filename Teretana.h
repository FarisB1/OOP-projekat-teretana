//
// Created by farex on 12/26/2023.
//

#ifndef PROJEKAT_TERETANA_H
#define PROJEKAT_TERETANA_H
#include <vector>
#include "Korisnik.h"
class Teretana {
public:
    std::vector<Korisnik> korisnici;

public:
    void ucitajIzFajla();
    void ispisiKorisinke();
};


#endif //PROJEKAT_TERETANA_H
