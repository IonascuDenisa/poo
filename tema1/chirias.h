//
// Created by mihaela on 18.12.2020.
//

#ifndef TEMA1_CHIRIAS_H
#define TEMA1_CHIRIAS_H
#include <iostream>
#include "perioada.h"
#include "locatar.h"


class chirias :public locatar
{
    std::string inceputul_inchirierii;
    std::string sfarsitul_inchirierii;
    int chirie;
    perioada p;
public:
    explicit chirias(std::string ="Snowww",std::string="John",std::string ="601225412043", bool=false,std::string="30.01.2011",std::string="17.12.2020",int=200);
    chirias(const chirias& );
    std::string get_inceputul_inchirierii();
    std::string get_sfarsitul_inchirierii();
    void setp();
    void timp();
    void citiref(std::ifstream &) override;
};


#endif //TEMA1_CHIRIAS_H
