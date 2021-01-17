//
// Created by mihaela on 17.01.2021.
//

#include "adresa_builder.h"

adresa_builder &adresa_builder::numar(int nr) {
    a.numar = nr;
    return *this;
}

adresa_builder &adresa_builder::strada(std::string str) {
    a.strada = str;
    return *this;
}


adresa_builder &adresa_builder::bloc(std::string bl) {
    a.bloc = bl;
    return *this;
}

adresa_builder &adresa_builder::etaj(int et) {
    a.etaj = et;
    return *this;
}

adresa_builder &adresa_builder::apartament(int ap) {
    a.apartament = ap;
    return *this;
}

adresa_builder &adresa_builder::interfon(std::string interf) {
    a.interfon = interf;
    return *this;
}

adresa_builder &adresa_builder::oras(std::string Or) {
    a.oras = Or;
    return *this;
}

adresa_builder &adresa_builder::judet(std::string jud) {
    a.judet = jud;
    return *this;
}

adresa adresa_builder::build() {
    return a;
}

