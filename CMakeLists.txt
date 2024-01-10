cmake_minimum_required(VERSION 3.26)
project(PROJEKAT)

set(CMAKE_CXX_STANDARD 17)

add_executable(PROJEKAT main.cpp
        Korisnik.cpp
        Korisnik.h
        Radnici.cpp
        Radnici.h
        Teretana.cpp
        Teretana.h
        Datum.cpp
        Datum.h
        Osoba.cpp
        Osoba.h)
