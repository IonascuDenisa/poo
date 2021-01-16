//
// Created by mihaela on 18.12.2020.
//

#ifndef TEMA1_LOCUINTA_H
#define TEMA1_LOCUINTA_H
#include <iostream>
#include <vector>

#include "adresa.h"
#include "incapere.h"
#include "locatar.h"

class locuinta {
protected:
    bool chiriasi;
    int nr_locuitori;
    adresa a;
    std::vector<incapere> incaperi;
    std::vector<locatar> oameni;
public:
    explicit locuinta(bool= "true", int= 3);

    void add_incaperi(incapere const &);

    void add_oameni(locatar const &);

    void afisare_incaperi();

    void set_adresa(adresa &a);

    void afisare_adresa();

    std::string get_adresa();

    void afisare_oameni();

    void set_chiriasi(bool);

    void set_nr_locuitori(int);

    float aria_locuintei();

    friend std::ostream &operator<<(std::ostream &os, const locuinta &locuinta);

    virtual void afisare(std::ostream &os) const;

};
#endif //TEMA1_LOCUINTA_H
