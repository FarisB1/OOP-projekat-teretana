//
// Created by farex on 12/26/2023.
//

#include "Radnici.h"

Osoba &Radnici::getRadnik() {
    return this->radnik;
    this->brKorisnika = 0;
}

void Radnici::setRadnik(Osoba &radnik) {
    Radnici::radnik = radnik;
}

int Radnici::getBrKorisnika() {
    return this->brKorisnika;
}

void Radnici::setBrKorisnika(int brKorisnika) {
    Radnici::brKorisnika = brKorisnika;
}

void Radnici::setRadnik() {
    this->radnik.postaviOsobu();
    this->brKorisnika = 0;
}
