//
// Created by mihaela on 17.01.2021.
//

#ifndef TEMA1_ADRESA_BUILDER_H
#define TEMA1_ADRESA_BUILDER_H

#include "adresa.h"

class adresa_builder {
private:
    adresa a;
public:
    adresa_builder() = default;

    adresa_builder &strada(std::string);

    adresa_builder &numar(int);

    adresa_builder &bloc(std::string);

    adresa_builder &etaj(int);

    adresa_builder &apartament(int);

    adresa_builder &interfon(std::string);

    adresa_builder &oras(std::string);

    adresa_builder &judet(std::string);

    adresa build();


};


#endif //TEMA1_ADRESA_BUILDER_H
