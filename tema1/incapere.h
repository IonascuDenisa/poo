//
// Created by mihaela on 18.12.2020.
//

#ifndef TEMA1_INCAPERE_H
#define TEMA1_INCAPERE_H
#include <iostream>

class incapere {
protected:
    std::string nume;
    float lungime,latime;
    friend class locatar;
public:
    explicit incapere(std::string="hol",float=4 ,float=2);
    incapere(const incapere &);
    void afisare_arie() const;
    float arie() const;
    std::string get_nume();
    void schimbare_nume(std::string&);
    incapere& operator=(incapere x);
    friend std::ostream& operator<<(std::ostream &os , const incapere &i);
    void citiref(std::ifstream &f);
};


#endif //TEMA1_INCAPERE_H
