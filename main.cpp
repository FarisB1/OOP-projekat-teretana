#include <iostream>
#include <fstream>
#include <sstream>
#include "Korisnik.h"
#include "Datum.h"
#include "Osoba.h"
#include "Teretana.h"


void adminMeni(Teretana &T){
    int izbor;

    do{
        system("cls");
        std::cout << "           ______               __                       ____  ___    _   _____   _____        \n"
                     "           /_  __/__  ________  / /_____ _____  ____ _   / __ \\/   |  / | / /   | / ___/        \n"
                     " ______     / / / _ \\/ ___/ _ \\/ __/ __ `/ __ \\/ __ `/  / /_/ / /| | /  |/ / /| | \\__ \\   ______\n"
                     "/_____/    / / /  __/ /  /  __/ /_/ /_/ / / / / /_/ /  / _, _/ ___ |/ /|  / ___ |___/ /  /_____/\n"
                     "          /_/_ \\___/_/   \\___/\\__/\\__,_/_/ /_/\\__,_/  /_/ |_/_/  |_/_/ |_/_/  |_/____/          \n";


        std::cout<<"\n1. Stanje teretane\n";
        std::cout<<"2. Dodaj radnika\n";
        std::cout<<"3. Clanarine \n";
        std::cout<<"4. Nazad\n";
        std::cout<<"Unesite izbor: ";
        std::cin>>izbor;
        std::cin.ignore();
        switch (izbor) {
            case 1:
                T.stanjeTeretane();
                system("Pause");
                break;

            case 2:
                T.dodajRadnika();
                system("Pause");
                break;

            case 3:
                T.ispisiKorisinke();
                T.provjeriClanarinu();
                system("Pause");
                break;

            case 4:
                std::cout<<"Hvala i dovidjenja\n";
                break;

        }
    }while(izbor != 4);

    system("Pause");
}

bool loginAdmin() {
        std::string username, password;

        std::cout << "Unesite korisnicko ime: ";
        std::cin >> username;

        std::cout << "Unesite lozinku: ";
        std::cin >> password;

        std::ifstream file("admin.txt");
        std::string line;

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string storedUsername, storedPassword;

            try {
                if (!(iss >> storedUsername >> storedPassword)) {
                    throw std::runtime_error("Greska citanja!");
                }

                if (storedUsername == username && storedPassword == password) {
                    std::cout << "Uspjesno ste se ulogovali kao admin.\n";
                    system("Pause");
                    return true;
                }
            } catch (const std::exception& e) {
                std::cerr << "Greska: " << e.what() << std::endl;
                system("Pause");
                continue;
            }
        }

        std::cout << "Neuspesno logovanje kao admin.\n";
        system("Pause");
        return false;
}

bool loginRadnik(Teretana &T) {
    std::string username, password;

    std::cout << "Unesite korisnicko ime: ";
    std::cin >> username;

    std::cout << "Unesite lozinku: ";
    std::cin >> password;

    std::ifstream file("radnici.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string storedUsername, storedPassword;

        try {
            if (!(iss >> storedUsername >> storedPassword)) {
                throw std::runtime_error("Greska citanja!");
            }

            if (storedUsername == username && storedPassword == password) {
                std::cout << "Uspjesno ste se ulogovali kao radnik.\n";
                system("Pause");
                return true;
            }
        } catch (const std::exception& e) {
            std::cerr << "Greska: " << e.what() << std::endl;
            system("Pause");
            continue;
        }
    }

    std::cout << "Neuspesno logovanje kao admin.\n";
    system("Pause");
    return false;
}

void radnikMeni(Teretana &T){
    int izbor;

    do{
        system("cls");
        std::cout << "           ______               __                       ____  ___    _   _____   _____        \n"
                     "           /_  __/__  ________  / /_____ _____  ____ _   / __ \\/   |  / | / /   | / ___/        \n"
                     " ______     / / / _ \\/ ___/ _ \\/ __/ __ `/ __ \\/ __ `/  / /_/ / /| | /  |/ / /| | \\__ \\   ______\n"
                     "/_____/    / / /  __/ /  /  __/ /_/ /_/ / / / / /_/ /  / _, _/ ___ |/ /|  / ___ |___/ /  /_____/\n"
                     "          /_/_ \\___/_/   \\___/\\__/\\__,_/_/ /_/\\__,_/  /_/ |_/_/  |_/_/ |_/_/  |_/____/          \n";


        std::cout<<"\n1. Unesi korisnika\n";
        std::cout<<"2. Daj kljuc\n";
        std::cout<<"3. Uzmi kljuc\n";
        std::cout<<"4. Produzi clanarinu\n";
        std::cout<<"5. Provjeri clanarinu \n";
        std::cout<<"6. Svi korisnici \n";
        std::cout<<"7. Zauzeti ormarici\n";
        std::cout<<"8. Izbrisi korisnika\n";
        std::cout<<"9. Nazad\n";
        std::cout<<"Unesite izbor: ";
        std::cin>>izbor;
        std::cin.ignore();
        switch (izbor) {
            case 1:
                T.dodajKorisnika();
                system("Pause");
                break;
            case 2:
                T.ispisiKorisinke();
                T.dajKljuc();
                system("Pause");
                break;
            case 3:
                T.uzmiKljuc();
                system("Pause");
                break;
            case 4:
                T.ispisiKorisinke();
                T.produziClanarinu();
                system("Pause");
                break;
            case 5:
                T.ispisiKorisinke();
                T.provjeriClanarinu();
                system("Pause");
                break;
            case 6:
                T.ispisiKorisinke();
                system("Pause");
                break;
            case 7:
                T.ispisOrmarica();
                system("Pause");
                break;
            case 8:
                T.ispisiKorisinke();
                T.izbrisi("korisnici.txt");
                system("Pause");
                break;
            case 9:
                std::cout<<"Hvala i dovidjenja\n";
                break;

        }
    }while(izbor != 9);

    system("Pause");
}

void korisnikMeni(Teretana &T){
    int izbor;

    do{
        system("cls");
        std::cout << "           ______               __                       ____  ___    _   _____   _____        \n"
                     "           /_  __/__  ________  / /_____ _____  ____ _   / __ \\/   |  / | / /   | / ___/        \n"
                     " ______     / / / _ \\/ ___/ _ \\/ __/ __ `/ __ \\/ __ `/  / /_/ / /| | /  |/ / /| | \\__ \\   ______\n"
                     "/_____/    / / /  __/ /  /  __/ /_/ /_/ / / / / /_/ /  / _, _/ ___ |/ /|  / ___ |___/ /  /_____/\n"
                     "          /_/_ \\___/_/   \\___/\\__/\\__,_/_/ /_/\\__,_/  /_/ |_/_/  |_/_/ |_/_/  |_/____/          \n";


        std::cout<<"\n1. Stanje svlacionice\n";
        std::cout<<"2. Nazad\n";
        std::cout<<"Unesite izbor: ";
        std::cin>>izbor;

        switch (izbor) {
            case 1:
                T.stanjeTeretane();
                T.ispisOrmarica();
                system("Pause");
                break;
            case 2:
                std::cout<<"Hvala i dovidjenja\n";
                break;

        }
    }while(izbor != 2);

    system("Pause");
}

void loginMeni(Teretana &T){
    int izbor, a;
    do{
        system("cls");
        std::cout << "           ______               __                       ____  ___    _   _____   _____        \n"
                     "           /_  __/__  ________  / /_____ _____  ____ _   / __ \\/   |  / | / /   | / ___/        \n"
                     " ______     / / / _ \\/ ___/ _ \\/ __/ __ `/ __ \\/ __ `/  / /_/ / /| | /  |/ / /| | \\__ \\   ______\n"
                     "/_____/    / / /  __/ /  /  __/ /_/ /_/ / / / / /_/ /  / _, _/ ___ |/ /|  / ___ |___/ /  /_____/\n"
                     "          /_/_ \\___/_/   \\___/\\__/\\__,_/_/ /_/\\__,_/  /_/ |_/_/  |_/_/ |_/_/  |_/____/          \n\n\n"
                     "           / /   ____  ____ _(_)___                                                             \n"
                     " ______   / /   / __ \\/ __ `/ / __ \\______                                                     \n"
                     "/_____/  / /___/ /_/ / /_/ / / / / /_____/                                                     \n"
                     "        /______/\____/\\__, /_/_/ /_/                                                            \n"
                     "                    /____/                                           \n";


        std::cout<<"\n1. Admin\n";
        std::cout<<"2. Radnik\n";
        std::cout<<"3. Korisnik\n";
        std::cout<<"4. Kraj\n";
        std::cout<<"Unesite izbor: ";
        std::cin>>izbor;

        switch (izbor) {
            case 1:
                if (loginAdmin()){
                    adminMeni(T);
                }
                break;
            case 2:
                if (loginRadnik(T)){
                    radnikMeni(T);
                }
                break;
            case 3:
                korisnikMeni(T);
                break;
            case 4:
                std::cout<<"Hvala i dovidjenja\n";
                break;

        }
    }while(izbor != 4);

    system("Pause");
}

int main() {
    Teretana T;
    T.ucitajIzFajla();

    system("Pause");
    loginMeni(T);
    return 0;
}
