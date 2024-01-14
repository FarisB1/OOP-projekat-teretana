//
// Created by farex on 12/26/2023.
//

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Korisnik.h"
#include "Datum.h"
#include <ctime>
#include <vector>
#include <iterator>

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
    this->setBrKartice();
}

int Korisnik::getBrKartice() {
    return this->brKartice;
}

void Korisnik::setBrKartice() {
    srand(time(NULL));
    rand();
    this->brKartice = rand()%90000 + 10000;
}

void Korisnik::setBrKartice(int a) {
    this->brKartice = a;
}

int Korisnik::getKljuc(){
    return this->kljuc;
}

void Korisnik::setKljuc(int a){
    this->kljuc = a;
}

void Korisnik::removeKljuc() {
    this->kljuc = 0;
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
    this->jePrisutan = false;
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
    outFile<< this->datumUclanjivanja.getDan()<<"."<<this->datumUclanjivanja.getMjesec()<<"."<<this->datumUclanjivanja.getGodina()<<" " << this->getBrKartice();
    outFile<<" "<<this->datumIsteka.getDan()<<"."<<this->datumIsteka.getMjesec()<<"."<<this->datumIsteka.getGodina();
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
    this->datumIsteka.ispisiDatum();std::cout<<"\n";

    if (trenutniDatum > this->datumIsteka) {
        std::cout << "Clanarina istekla. Potrebno je produziti clanarinu." << std::endl;
    } else {
        std::cout << "Clanarina je jos uvijek validna." << std::endl;
    }
}

void Korisnik::produziClanarinu(){
    //Uzima vrijednost danasnjeg datuma
    time_t t = time(0);
    struct tm* now = localtime(&t);
    Datum trenutniDatum(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    this->datumIsteka.ispisiDatum();std::cout<<"\n";
    this->datumIsteka = this->datumIsteka + 30;
    izbrisi("korisnici.txt");
    sacuvajUFajl();
    std::cout<<"Novi datum isteka: ";
    this->datumIsteka.ispisiDatum();std::cout<<"\n";
}

std::ostream& operator<<(std::ostream& stream, Korisnik& p) {
    stream << "| " << std::left << std::setw(15) << p.korisnik.getIme() << " | " << std::setw(15) << p.korisnik.getPrezime() << " | "
           << std::setw(5) << p.korisnik.getGodine() << " | " << std::setw(15) << p.korisnik.getBrTelefona() << " | "
           << std::setw(15) << p.korisnik.getDatumRodjenja().ispisiDatum2() << " | " << std::setw(20); p.ispisiPaket(); stream << " | "
           << std::setw(25) << p.getBrKartice() << " | "
           << std::setw(25) << p.getDatumUclanjivanja().ispisiDatum2() << " |" << std::endl;
    stream << "+-----------------+-----------------+-------+-----------------+-----------------+----------------------+---------------------------+---------------------------+" << std::endl;

    return stream;
}


void Korisnik::setKorisnik(Osoba& osoba){
    this->korisnik = osoba;
}
void Korisnik::setDatum(Datum& datum){
    this->datumUclanjivanja = datum;
}
void Korisnik::setDatumIsteka(Datum& datum){
    this->datumIsteka = datum;
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

bool Korisnik::JePrisutan() {
    return this->jePrisutan;
}


void Korisnik::prijava() {
    this->jePrisutan = true;
}

void Korisnik::odjava(){
    this->jePrisutan = false;
}
