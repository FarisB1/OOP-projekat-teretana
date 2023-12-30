//
// Created by farex on 12/26/2023.
//

#include <iostream>
#include <chrono>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Korisnik.h"
#include "Datum.h"

Osoba &Korisnik::getKorisnici(){
    return this->korisnik;
}

Datum &Korisnik::getDatumUclanjivanja() {
    return this->datumUclanjivanja;
}

Paket Korisnik::getPaket(){
    return this->paket;
}

bool Korisnik::isClanarina() {
    return this->clanarina;
}

void Korisnik::setKorisnik() {
    Osoba a;
    a.postaviOsobu();
    this->korisnik = a;
}


void Korisnik::setDatumUclanjivanja() {
    time_t t = time(0);
    struct tm* now = localtime(&t);
    Datum trenutniDatum(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    this->datumUclanjivanja = trenutniDatum;
    switch (static_cast<int>(this->paket)) {
        case 1:
            this->datumIsteka = trenutniDatum + 1;
            break;
        case 2:
            this->datumIsteka = trenutniDatum + 30;
            break;
        case 3:
            this->datumIsteka = trenutniDatum + 30;
            break;
        case 4:
            this->datumIsteka = trenutniDatum + 30;
            break;
        default:
            this->datumIsteka = trenutniDatum;
            break;
    }

}

void Korisnik::setPaket() {
    int e;
    do{
        std::cout<<"Unesite paket (dnevna - 1, jutarnja - 2, vecernja - 3, mjesecna - 4): ";
        std::cin>>e;
        if (e < 1 || e > 4) {
            std::cout << "Pogrešan unos. Molimo odaberite ispravan paket (1-4).\n";
        }
    }while(e<1 || e>4);
    this->paket = static_cast<Paket> (e);
}

void Korisnik::postaviKorisnika() {
    this->setKorisnik();
    std::cout<<"\n";
    this->setPaket();
    this->setDatumUclanjivanja();
    this->clanarina = true;
    this->setCijena();
    this->sacuvajUFajl();

    std::cout << "Korisnik uspjesno unesen!" << std::endl;
}

void Korisnik::sacuvajUFajl(){
    std::ofstream outFile("korisnici.txt", std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    outFile << this->korisnik.getIme() <<" " << this->korisnik.getPrezime()
            << " " << this->korisnik.getGodine() << " " << this->korisnik.getBrTelefona()
            << " ";
    outFile<< this->korisnik.getDatumRodjenja().getDan()<<"."<<this->korisnik.getDatumRodjenja().getMjesec()<<"."<<this->korisnik.getDatumRodjenja().getGodina();
    outFile << " ";
    switch (this->paket) {
        case 1:
            outFile<<"Dnevna";
            break;
        case 2:
            outFile<<"Jutarnja";
            break;
        case 3:
            outFile<<"Studentska";
            break;
        case 4:
            outFile<<"Mjesecna";
            break;
    }
    outFile << " ";
    outFile<< this->datumUclanjivanja.getDan()<<"."<<this->datumUclanjivanja.getMjesec()<<"."<<this->datumUclanjivanja.getGodina();
    outFile << "\n";

    outFile.close();

}

void Korisnik::ispisiPaket(){
    switch (this->paket) {
        case 1:
            std::cout<<"Dnevna";
            break;
        case 2:
            std::cout<<"Jutarnja";
            break;
        case 3:
            std::cout<<"Studentska";
            break;
        case 4:
            std::cout<<"Mjesecna";
            break;
    }
}

float Korisnik::getCijena() {
    return this->cijena;
}

void Korisnik::setCijena() {
    switch (static_cast<int>(this->paket)) {
        case 1:
            this->cijena = 5;
            break;
        case 2:
            this->cijena = 20;
            break;
        case 3:
            this->cijena = 30;
            break;
        case 4:
            this->cijena = 45;
            break;
        default:
            this->cijena = 5;
            break;
    }
}

void Korisnik::provjeriValidnostClanarine() {
    //Uzima vrijednost danasnjeg datuma
    time_t t = time(0);
    struct tm* now = localtime(&t);
    Datum trenutniDatum(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    datumIsteka.ispisiDatum();std::cout<<"\n";

    if (trenutniDatum > this->datumIsteka) {
        std::cout << "Clanarina istekla. Potrebno je produziti clanarinu." << std::endl;
    } else {
        std::cout << "Clanarina je jos uvijek validna." << std::endl;
    }
}
std::ostream& operator<<(std::ostream& stream, Korisnik& p){

    stream << "| " << std::left << std::setw(15) << p.korisnik.getIme() << " | " << std::setw(15) << p.korisnik.getPrezime() << " | "
           << std::setw(5) << p.korisnik.getGodine() << " | " << std::setw(15) << p.korisnik.getBrTelefona() << " | "
           << std::setw(15) << p.korisnik.getDatumRodjenja().ispisiDatum2() << " | " << std::setw(20); p.ispisiPaket(); stream << " | "
                                                                                                                               << std::setw(25) << p.getDatumUclanjivanja().ispisiDatum2() << " |" << std::endl;
    stream << "+-----------------+-----------------+-------+-----------------+-----------------+----------------------+---------------------------+" << std::endl;

    return stream;
}

void Korisnik::setKorisnik(Osoba& osoba){
    this->korisnik = osoba;
}
void Korisnik::setDatum(Datum& datum){
    this->datumUclanjivanja = datum;
}
void Korisnik::setClanarina(bool clanarina){
    this->clanarina = clanarina;
}
void Korisnik::setPaket(Paket paket){
    this->paket = paket;
}
void Korisnik::setCijena(float cijena){
    this->cijena = cijena;
}