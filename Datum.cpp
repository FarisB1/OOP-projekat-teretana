//
// Created by farex on 12/26/2023.
//
#include <iostream>
#include <sstream>
#include "Datum.h"

Datum::Datum(int dan, int mjesec, int god) {
    this->dan = dan;
    this->mjesec = mjesec;
    this->godina = god;
}

int Datum::getDan() {
    return this->dan;
}

int Datum::getMjesec() {
    return this->mjesec;
}

int Datum::getGodina() {
    return this->godina;
}
void Datum::setGodina() {
    do{
        std::cout<<"Unesite godina: ";
        std::cin>>this->godina;
    } while (this->godina<1900);
}
void Datum::setMjesec() {
    do{
        std::cout<<"Unesite mjesec: ";
        std::cin>>this->mjesec;
    } while (this->mjesec>12 || this->mjesec<0);
}

void Datum::setDan() {
    switch (this->mjesec) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            do{
                std::cout<<"Unesite dan: ";
                std::cin>>this->dan;
            }while (this->dan>31 || this->dan<0);
            break;
        case 4: case 6: case 9: case 11:
            do{
                std::cout<<"Unesite dan: ";
                std::cin>>this->dan;
            }while (this->dan>30 || this->dan<0);

            break;
        case 2:
            bool prestupna;
            if(this->godina%4==0 && this->godina%100!=0 || this->godina%400 == 0) prestupna = true;
            else prestupna = false;

            if (prestupna){
                do{
                    std::cout<<"Unesite dan: ";
                    std::cin>>this->dan;
                }while (this->dan>29 || this->dan<0);
            }
            else{
                do{
                    std::cout<<"Unesite dan: ";
                    std::cin>>this->dan;
                }while (this->dan>28 || this->dan<0);
            }
    }
}



void Datum::postaviDatum() {
    setGodina();
    setMjesec();
    setDan();
    std::cin.ignore();
}

void Datum::ispisiDatum() {
    std::cout<<this->dan<<"."<<this->mjesec<<"."<<this->godina<<"\n";
}

// Assuming ispisiDatum returns a string
std::string Datum::ispisiDatum2() {
    std::ostringstream oss;
    oss << this->dan << '.' << this->mjesec << '.' << this->godina;
    return oss.str();
}


Datum::Datum() {
    this->dan = 1;
    this->mjesec = 1;
    this->godina = 1900;
}

void Datum::setGodina(int a) {
    this->godina = a;
}

void Datum::setDan(int a) {
    this->dan = a;
}

void Datum::setMjesec(int a) {
    this->mjesec = a;
}

int Datum::dani_u_mjesecu(int mjesec, int god) const {
    switch (mjesec) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return (god % 4 == 0 && god % 100 != 0) || (god % 400 == 0) ? 29 : 28;
        default:
            return 0;
    }
}
Datum Datum::operator+(int dan) const {
    Datum rez(*this);
    rez.dan += dan;
    
    while (rez.dan > dani_u_mjesecu(rez.mjesec, rez.godina)) {
        rez.dan -= dani_u_mjesecu(rez.mjesec, rez.godina);
        rez.mjesec++;
        if (rez.mjesec > 12) {
            rez.mjesec = 1;
            rez.godina++;
        }
    }

    return rez;
}

bool Datum::operator>(const Datum& a) const {
    if (godina > a.godina) return true;
    if (godina < a.godina) return false;
    if (mjesec > a.mjesec) return true;
    if (mjesec < a.mjesec) return false;
    return dan > a.dan;
}