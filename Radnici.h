//
// Created by farex on 12/26/2023.
//

#ifndef PROJEKAT_RADNICI_H
#define PROJEKAT_RADNICI_H
#include "Osoba.h"

class Radnici : public Osoba{
private:
    Osoba radnik;
    std::string sifra;

public:
    Osoba &getRadnik();
    int getBrKorisnika();

    void setSifra();
    std::string getSifra();

    void setRadnik(Osoba &radnik);
    void setRadnik();
    void setBrKorisnika(int brKorisnika);
    void setBrKorisnika();

    void sacuvajUFajl();

    void povecajBrKorisika();
};


#endif //PROJEKAT_RADNICI_H
