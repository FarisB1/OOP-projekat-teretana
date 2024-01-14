#ifndef PROJEKAT_KORISNIK_H
#define PROJEKAT_KORISNIK_H
#include "Osoba.h"
#include "Datum.h"
enum Paket{dnevna = 1, jutarnja, studentska, mjesecna};

class Korisnik : public Osoba {
private:
    Osoba korisnik;
    Datum datumUclanjivanja;
    bool clanarina;
    Paket paket;
    float cijena;
    Datum datumIsteka;
    bool jePrisutan;
    int brKartice;
    int kljuc;
public:
    bool JePrisutan();
    void prijava();
    void odjava();

    Osoba &getKorisnici();
    Paket getPaket();
    bool isClanarina();
    Datum &getDatumUclanjivanja();
    float getCijena();
    int getBrKartice();

    void setBrKartice();
    void setBrKartice(int a);
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

    int getKljuc();
    void setKljuc(int a);
    void removeKljuc();

    void produziClanarinu();

    void setDatumIsteka(Datum &datum);

};


#endif //PROJEKAT_KORISNIK_H
