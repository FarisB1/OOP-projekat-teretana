//
// Created by farex on 12/26/2023.
//

#ifndef PROJEKAT_DATUM_H
#define PROJEKAT_DATUM_H
#include <string>

class Datum {
private:
    int dan;
    int mjesec;
    int godina;
public:
    void setDan();
    void setMjesec();
    void setGodina();

    void setDan(int a);
    void setMjesec(int a);
    void setGodina(int a);


    int getDan();
    int getMjesec();
    int getGodina();

    void postaviDatum();
    void ispisiDatum();
    std::string ispisiDatum2();
    int dani_u_mjesecu(int mjesec, int god) const;


    Datum(int dan, int mjesec, int god);
    Datum();
    ~Datum(){};

    Datum operator+(int dan) const;
    bool operator>(const Datum& a) const;
};


#endif //PROJEKAT_DATUM_H
