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
#include <iterator>

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
        
        int dan1, mjesec1, god1, dan2, mjesec2, god2, dan3, mjesec3, god3;
        char tacka;
        std::istringstream datum1(words[4]);
        datum1 >> dan1 >> tacka >> mjesec1 >> tacka >> god1;

        std::istringstream datum2(words[6]);
        datum2 >> dan2 >> tacka >> mjesec2 >> tacka >> god2;
        std::istringstream datum3(words[8]);
        datum3 >> dan3 >> tacka >> mjesec3 >> tacka >> god3;

        Datum datumRodjenja(dan1, mjesec1, god1);
        Datum datumUclanjivanja(dan2, mjesec2, god2);
        Datum datumIsteka(dan3,mjesec3,god3);
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
        e.setDatumIsteka(datumIsteka);
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
    std::cout << "Broj ormarica: " << brOrmarica << std::endl;
    std::cout << "Broj slobodnih ormarica: "<< brOrmarica - brojPrisutnih << std::endl;

    if(brojPrisutnih > brOrmarica) {
        std::cout << "UPOZORENJE: Svlacionice su popunjene!" << std::endl;
    }

    std::cout << "\n";
}

void Teretana::dajKljuc() {
    int a;
    std::cout << "Unesite ID kartice: ";
    std::cin >> a;
    std::cin.ignore();
    bool pronadjen = false;
    for (auto &korisnik : this->korisnici) {
        if (a == korisnik.getBrKartice() && !korisnik.JePrisutan()) {
            if (this->brZauzetih >= brOrmarica) {
                std::cout << "Svi ormarici su zauzeti.\n";
                return;
            }
            korisnik.prijava();
            this->brZauzetih++;
            int kljuc;
            pronadjen = true;
            srand(time(NULL));
            rand();

            bool ima = false;
            do {
                kljuc = rand() % 30 + 1;
                for (auto &nizKljuceva : *kljucevi) {
                    if (kljuc == nizKljuceva) {
                        ima = true;
                        break;
                    }
                }
            } while (ima);

            korisnik.setKljuc(kljuc);
            this->kljucevi->push_back(kljuc);
        }
    }
    if (!pronadjen) {
        std::cout << "ID kartice nije validan.\n";
    }
}

void Teretana::ispisOrmarica() {
    int ormaric[30] = {0};

    for (auto& kljuc : *kljucevi) {
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
            std::cout << "|    " << (i+j+1) << ((i+j+1)<10 ? "    |\t" : "   |\t");
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
    int a;
    ispisOrmarica();
    std::cout<<"Unesite ID kljuca: ";
    std::cin>>a;
    bool pronadjen = false;
    int indeks = -1;
    this->brZauzetih--;
    for (int i = 0; i < kljucevi->size(); i++){
        if ((*kljucevi)[i] == a){
            pronadjen = true;
            indeks = i;
            break;
        }
    }

    if (pronadjen){
        this->kljucevi->erase(this->kljucevi->begin() + indeks);
        for(auto &korisnik : this->korisnici)
        {
            if (korisnik.getKljuc() == a)
            {
                std::cout<<korisnik;
                korisnik.removeKljuc();
                korisnik.odjava();
                break;
            }
        }
    }
    if (!pronadjen){
        std::cout<<"Kljuc nije validan.\n";
    }
}

void Teretana::dodajKorisnika(){
    Korisnik temp;
    temp.postaviKorisnika();
    this->korisnici.push_back(temp);
    std::cin.ignore();
}

void Teretana::provjeriClanarinu() {
    int a;
    std::cout<<"Unesite ID kartice: ";
    std::cin>>a;
    std::cin.ignore();
    bool validan = false;
    for (auto &korisnik : this->korisnici){
        int br = korisnik.getBrKartice();
        if (a==br){
            korisnik.provjeriValidnostClanarine();
            validan = true;
            break;
        }
    }
    if (!validan){
        std::cout<<"Unesite validan ID kartice.\n";
    }
}

void Teretana::produziClanarinu() {
    int a;
    std::cout<<"Unesite ID kartice: ";
    std::cin>>a;
    std::cin.ignore();
    bool validan = false;
    for (auto &korisnik : this->korisnici){
        int br = korisnik.getBrKartice();
        if (a==br){
            korisnik.produziClanarinu();
            validan = true;
            break;
        }
    }
    if (!validan){
        std::cout<<"Unesite validan ID kartice.\n";
    }
}

void Teretana::izbrisi(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    std::vector<std::string> lines;
    std::string userNumber;
    bool pronadjen = false;
    int indeks;
    do{
        std::cout<<"Unesite ID kartice: ";
        std::getline(std::cin,userNumber);
        for (int i = 0; i < this->korisnici.size(); ++i) {
            if (this->korisnici[i].getBrKartice() == std::stoi(userNumber)) {
                pronadjen = true;
                indeks = i;
                break;
            }
        }
        if (!pronadjen) std::cout<<"Unesite validan ID.";
    }while(!pronadjen);

    this->korisnici.erase(this->korisnici.begin() + indeks);
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                           std::istream_iterator<std::string>());

            if (words.size() >= 2 && words[words.size() - 2] != userNumber) {
                lines.push_back(line);
            }
        }
        inputFile.close();

        std::ofstream outputFile(filePath);
        for (const auto& line : lines) {
            outputFile << line << '\n';
        }
        outputFile.close();

        std::cout << "Korisnik sa ID " << userNumber << " je obrisan.\n";
    } else {
        std::cerr << "Fajl nije otvoren: " << filePath << "\n";
    }
}


void Teretana::dodajRadnika() {
    Radnici temp;
    temp.setRadnik();
    this->radnici.push_back(temp);

    std::cin.ignore();
}

