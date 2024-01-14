#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include "Osoba.h"
#include "Datum.h"

Osoba::Osoba() {
    this->ime = "Niko";
    this->prezime = "Nikic";
    this->godine = 18;
    this->brTelefona ="061000000";
    datumRodjenja.setDan(1);
    datumRodjenja.setMjesec(1);
    datumRodjenja.setGodina(2024);
}

std::string Osoba::getIme() {
    return this->ime;
}

std::string Osoba::getPrezime() {
    return this->prezime;
}

int Osoba::getGodine() {
    return this->godine;
}

std::string Osoba::getBrTelefona(){
    return this->brTelefona;
}

Datum &Osoba::getDatumRodjenja() {
    return this->datumRodjenja;
}

void Osoba::setGodine() {
    int a;
    std::cout<<"Unesite godine osobe: ";
    std::cin>>a;
    this->godine = a;
    std::cin.ignore();
}

void Osoba::setIme() {
    char a[30];
    std::cout<<"Unesite ime osobe: ";
    std::cin.getline(a,30);
    this->ime = a;
}

void Osoba::setPrezime() {
    char a[30];
    std::cout<<"Unesite prezime osobe: ";
    std::cin.getline(a,30);
    this->prezime = a;
}

void Osoba::setDatumRodjenja() {
    Datum a;
    std::cout<<"Unesite datum rodjenja:\n";
    a.postaviDatum();
    this->datumRodjenja = a;
}

void Osoba::setBrTelefona(){
    char a[30];
    std::cout<<"Unesite broj telefona osobe: ";
    std::cin.getline(a,30);
    this->brTelefona = a;
}

void Osoba::postaviOsobu() {
    this->setIme();
    this->setPrezime();
    this->setGodine();
    this->setBrTelefona();
    this->setDatumRodjenja();
    std::cout<<"Uspjesno dodana osoba!\n";

}

std::ostream& operator<<(std::ostream& stream, Osoba& p){
    stream << p.getIme() << "\t" << p.getPrezime() << "\t"<<p.getGodine()<<"\t"<<p.getBrTelefona()<<"\t";p.getDatumRodjenja().ispisiDatum();stream<<"\n";
    return stream;
}

void Osoba::setDatumRodjenja(Datum datum) {
    this->datumRodjenja = datum;
}

void Osoba::setBrTelefona(std::string brTelefon) {
    this->brTelefona =  brTelefon;
}

void Osoba::setGodine(int i) {
    this->godine = i;
}

void Osoba::setIme(std::string imeTemp) {
    this->ime = imeTemp;

}void Osoba::setPrezime(std::string prezimeTemp) {
    this->prezime = prezimeTemp;
}

void Osoba::izbrisi(const std::string &filePath) {
    std::ifstream inputFile(filePath);
    std::vector<std::string> lines;
    std::string ime;
    std::getline(std::cin,ime);
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                           std::istream_iterator<std::string>());

            if (words.size() >= 2 && words[words.size() - 2] != ime) {
                lines.push_back(line);
            }
        }
        inputFile.close();

        std::ofstream outputFile(filePath);
        for (const auto& line : lines) {
            outputFile << line << '\n';
        }
        outputFile.close();

        std::cout << "Korisnik " << ime << " je obrisan.\n";
    } else {
        std::cerr << "Fajl nije otvoren: " << filePath << "\n";
    }
}

