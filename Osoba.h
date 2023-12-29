//
// Created by farex on 12/26/2023.
//

#ifndef PROJEKAT_OSOBA_H
#define PROJEKAT_OSOBA_H
#include "Datum.h"
#include <ostream>
#include <string>
class Osoba {
private:
    std::string ime;
    std::string prezime;
    int godine;
    std::string brTelefona;
    Datum datumRodjenja;

public:
    std::string getIme();
    std::string getPrezime();
    int getGodine();
    std::string getBrTelefona();
    Datum &getDatumRodjenja();

    void setGodine();
    void setDatumRodjenja();
    void setIme();
    void setPrezime();
    void setBrTelefona();

    void postaviOsobu();
    friend std::ostream& operator<<(std::ostream &stream, Osoba& a);

    Osoba();
    ~Osoba(){};

    void setDatumRodjenja(Datum datum);
    void setBrTelefona(std::string brTelefon);
    void setGodine(int i);
    void setIme(std::string imeTemp);
    void setPrezime(std::string prezimeTemp);
};


#endif //PROJEKAT_OSOBA_H
