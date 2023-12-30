#include <iostream>
#include "Korisnik.h"
#include "Datum.h"
#include "Osoba.h"
#include "Teretana.h"

void loginMeni(){
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
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                std::cout<<"Hvala i dovidjenja";
                break;

        }
    }while(izbor != 5);

    system("Pause");
}

int main() {
    Teretana T;
    T.ucitajIzFajla();

    /*
    Korisnik temp;
    for (int i=0; i<2; i++)
    {
        temp.postaviKorisnika();
        T.korisnici.push_back(temp);
    }
    */
    T.ispisiKorisinke();
    system("Pause");
    loginMeni();
    return 0;
}
