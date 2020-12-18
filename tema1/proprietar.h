//
// Created by mihaela on 18.12.2020.
//

#ifndef TEMA1_PROPRIETAR_H
#define TEMA1_PROPRIETAR_H
#include <iostream>
#include "perioada.h"
#include "locatar.h"

class proprietar :public locatar
{
    std::string data_achizitionare;
    perioada p;
public:
    explicit proprietar(std::string ="Gigi",std::string="Ana-Maria",std::string ="601225412043", bool=false,std::string="16.12.2020");
    proprietar(const proprietar& );
    std::string get_data_achizitionare();
    void afi();
    void setp();
    void timp();
    void citiref(std::ifstream &) override ;

};


#endif //TEMA1_PROPRIETAR_H
