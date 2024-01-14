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
    int daysInMonth(int month, int year) const;


    Datum(int day, int month, int year);
    Datum();
    ~Datum(){};

    Datum operator+(int days) const;
    bool operator>(const Datum& other) const;
};

#endif //PROJEKAT_DATUM_H
