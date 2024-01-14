#include <fstream>
#include <iostream>
#include <vector>
#include "Radnici.h"

Osoba &Radnici::getRadnik() {
    return this->radnik;
}

void Radnici::setRadnik(Osoba &radnik) {
    Radnici::radnik = radnik;
}

std::string Radnici::getSifra() {
    return this->sifra;
}

void Radnici::setSifra() {
    std::cout<<"Unesite sifru radnika: ";
    std::getline(std::cin,this->sifra);
}

void Radnici::setRadnik() {
    this->radnik.postaviOsobu();
    this->setSifra();
    this->sacuvajUFajl();
}

void Radnici::sacuvajUFajl(){
    std::ofstream outFile("radnici.txt", std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Greska!" << std::endl;
        return;
    }

    outFile << this->radnik.getIme() <<" " << this->getSifra();
    outFile << "\n";

    outFile.close();
}

