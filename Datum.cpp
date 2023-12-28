//
// Created by farex on 12/26/2023.
//
#include <iostream>
#include <sstream>
#include "Datum.h"

Datum::Datum(int day, int month, int year) {
    this->dan = day;
    this->mjesec = month;
    this->godina = year;
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

int Datum::daysInMonth(int month, int year) const {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28;
        default:
            return 0; // Invalid month
    }
}
Datum Datum::operator+(int days) const {
    Datum result(*this);
    result.dan += days;

    // Handle month and year rollover
    while (result.dan > daysInMonth(result.mjesec, result.godina)) {
        result.dan -= daysInMonth(result.mjesec, result.godina);
        result.mjesec++;
        if (result.mjesec > 12) {
            result.mjesec = 1;
            result.godina++;
        }
    }

    return result;
}

bool Datum::operator>(const Datum& other) const {
    if (godina > other.godina) return true;
    if (godina < other.godina) return false;
    if (mjesec > other.mjesec) return true;
    if (mjesec < other.mjesec) return false;
    return dan > other.dan;
}