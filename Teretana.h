//
// Created by farex on 12/26/2023.
//

#ifndef PROJEKAT_TERETANA_H
#define PROJEKAT_TERETANA_H
#include <vector>
#include <memory>
#include "Radnici.h"
#include "Korisnik.h"

const int brOrmarica = 30;

class Teretana {
public:
    std::vector<Korisnik> korisnici;
    std::vector<Radnici> radnici;
    std::unique_ptr<std::vector<int>> kljucevi;
    int brZauzetih;

    Teretana() : brZauzetih(0), kljucevi(std::make_unique<std::vector<int>>()) {}

    void ucitajIzFajla();
    void ispisiKorisinke();
    void stanjeTeretane();

    void dajKljuc();
    void uzmiKljuc();
    void ispisOrmarica();

    void dodajKorisnika();
    void produziClanarinu();
    void provjeriClanarinu();
    void dodajRadnika();



    void izbrisi(const std::string &filePath);
};

#endif //PROJEKAT_TERETANA_H
