//
// Created by mihaela on 18.12.2020.
//

#ifndef TEMA1_ADRESA_H
#define TEMA1_ADRESA_H
#include <iostream>
using std::cout;

class adresa {
    std::string strada;
    int numar;
    std::string bloc;
    int etaj;
    int apartament;
    std::string interfon;
    std::string oras;
    std::string judet;
    friend class locatar;
public:
    explicit adresa(std::string="Unirii" ,int =23,std::string="M4 bis" ,int=4 ,int=132 ,std::string="0132",std::string="Bucuresti" ,std::string ="Sector3");
    adresa(const adresa& );
    void afisare_adresa();
    std::string get_adresa();
    void citire_adresa(std::ifstream &f);

    friend std::ostream &operator<<(std::ostream &os, const adresa &adresa);
};


#endif //TEMA1_ADRESA_H
