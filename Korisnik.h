//
// Created by farex on 12/26/2023.
//

#ifndef PROJEKAT_KORISNIK_H
#define PROJEKAT_KORISNIK_H
#include "Osoba.h"
#include "Datum.h"
enum Paket{dnevna = 1, jutarnja, studentska, mjesecna};

class Korisnik {
private:
    Osoba korisnik;
    Datum datumUclanjivanja;
    bool clanarina;
    Paket paket;
    float cijena;
    Datum datumIsteka;

public:
    Osoba &getKorisnici();
    Paket getPaket();
    bool isClanarina();
    Datum &getDatumUclanjivanja();
    float getCijena();

    void setKorisnik();
    void setDatumUclanjivanja();
    void setClanarina();
    void setPaket();
    void ispisiPaket();
    void setCijena();
    void provjeriValidnostClanarine();
    void postaviKorisnika();
    void sacuvajUFajl();

    void setKorisnik(Osoba& korisnik);
    void setDatum(Datum& datum);
    void setClanarina(bool clanarina);
    void setPaket(Paket paket);
    void setCijena(float cijena);
    Korisnik(){};
    ~Korisnik(){};
    friend std::ostream& operator<<(std::ostream &stream, Korisnik& a);


};


#endif //PROJEKAT_KORISNIK_H
