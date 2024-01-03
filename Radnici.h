//
// Created by farex on 12/26/2023.
//

#ifndef PROJEKAT_RADNICI_H
#define PROJEKAT_RADNICI_H
#include "Osoba.h"

class Radnici {
private:
    Osoba radnik;
    int brKorisnika;
public:
    Osoba &getRadnik();
    int getBrKorisnika();

    void setRadnik(Osoba &radnik);
    void setRadnik();
    void setBrKorisnika(int brKorisnika);
    void setBrKorisnika();



};


#endif //PROJEKAT_RADNICI_H
