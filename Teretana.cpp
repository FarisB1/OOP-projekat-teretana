//
// Created by farex on 12/26/2023.
//

#include "Teretana.h"
#include "Korisnik.h"
#include "Osoba.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

void Teretana::ucitajIzFajla() {
    std::ifstream inputFile("korisnici.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Fajl nije otvoren!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::vector<std::string> words;

        for (std::string word; iss >> word;) {
            words.push_back(word);
        }

        std::string ime = words[0];
        std::string prezime = words[1];
        int god = std::stoi(words[2]);
        std::string broj = words[3];
        std::string pak = words[5];
        
        int dan1, mjesec1, god1, dan2, mjesec2, god2;
        char tacka;
        std::istringstream datum1(words[4]);
        datum1 >> dan1 >> tacka >> mjesec1 >> tacka >> god1;

        std::istringstream datum2(words[6]);
        datum2 >> dan2 >> tacka >> mjesec2 >> tacka >> god2;
        // Printing the extracted information
        Datum datumRodjenja(dan1, mjesec1, god1);
        Datum datumUclanjivanja(dan2, mjesec2, god2);
        int pakett;

        if (pak == "Dnevna") {
            pakett = 1;
        } else if (pak == "Jutarnja") {
            pakett = 2;
        } else if (pak == "Studentska") {
            pakett = 3;
        } else if (pak == "Mjesecna") {
            pakett = 4;
        }

        int brKartice = std::stoi(words[7]);

        Osoba a;
        a.setIme(ime);
        a.setPrezime(prezime);
        a.setGodine(god);
        a.setBrTelefona(broj);
        a.setDatumRodjenja(datumRodjenja);
        Korisnik e;
        e.setKorisnik(a);
        e.setDatum(datumUclanjivanja);
        e.setClanarina(true);
        e.setPaket(static_cast<Paket>(pakett));
        e.setCijena();
        e.setBrKartice(brKartice);
        e.odjava();
        this->korisnici.push_back(e);
    }
    inputFile.close();
}

void Teretana::ispisiKorisinke() {
    std::cout << "+-----------------+-----------------+-------+-----------------+-----------------+----------------------+---------------------------+---------------------------+" << std::endl;
    std::cout << "|      Ime        |      Prezime    | Godine|   Br Telefona   | Datum Rodjenja  |       Paket          |      Br Kartice           | Datum Uclanjivanja        |" << std::endl;
    std::cout << "+-----------------+-----------------+-------+-----------------+-----------------+----------------------+---------------------------+---------------------------+" << std::endl;
        for (auto& korisnik : this->korisnici) {
            std::cout << korisnik;
        }
}

void Teretana::stanjeTeretane() {
    std::cout << "\nSTANJE TERETANE\n\n";

    int brojPrisutnih = 0;

    for(int i=0; i<korisnici.size(); i++) {
        if(korisnici[i].JePrisutan()) {
            brojPrisutnih++;
        }
    }

    std::cout << "Trenutno prisutni clanovi: " << brojPrisutnih << std::endl;
    std::cout << "Broj svlacionica: " << brOrmarica << std::endl;


    if(brojPrisutnih > brOrmarica) {
        std::cout << "UPOZORENJE: Svlacionice su popunjene!" << std::endl;
    }

    std::cout << "\n";
}

void Teretana::dajKljuc() {
    int a;
    std::cout<<"Unesite ID kartice: ";
    std::cin>>a;
    std::cin.ignore();
    for(auto &korisnik:this->korisnici){
        if(a==korisnik.getBrKartice() && !korisnik.JePrisutan()) {
            if (this->brZauzetih >= brOrmarica){
                std::cout << "Svi ormarici su zauzeti.";
                return;
            }
            korisnik.prijava();
            this->brZauzetih++;
            int kljuc;
            srand(time(NULL));
            rand();
            kljuc=rand()%30+1;
            this->kljucevi.push_back(kljuc);
        }
        else{
            std::cout<<"Unesite validan ID kartice.\n";
        }
    }
}

void Teretana::ispisOrmarica() {
    int ormaric[30] = {0};

    for (auto& kljuc : this->kljucevi) {
        if (kljuc >= 1 && kljuc <= 30) {
            ormaric[kljuc - 1] = 1;
        }
    }

    std::cout << "Ormarici:\n";
    for (int i = 0; i < 30; i += 5) {
        for (int j = 0; j < 5; ++j) {
            std::cout << "+---------+\t";
        }
        std::cout << "\n";
        for (int j = 0; j < 5; ++j) {
            std::cout << "|    " << (i + j + 1) << ((i + j + 1)<10 ? "    |\t" : "   |\t");
        }
        std::cout << "\n";
        for (int j = 0; j < 5; ++j) {
            std::cout << "| " << (ormaric[i + j] == 1 ? "Zauzeto" : "       ") << " |\t";
        }
        std::cout << "\n";
        for (int j = 0; j < 5; ++j) {
            std::cout << "+---------+\t";
        }
        std::cout << "\n";
    }
}

void Teretana::uzmiKljuc() {

}