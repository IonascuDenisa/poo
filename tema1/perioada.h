//
// Created by mihaela on 18.12.2020.
//

#ifndef TEMA1_PERIOADA_H
#define TEMA1_PERIOADA_H
#include <iostream>

class perioada {
    std::string data1,data2;
    std::string data3="16.12.2020";

public:
    explicit perioada(std::string="12.02.2012",std::string="16.07.2015");
    static int rdn(int , int , int ) ;
    int durata();
    static int durata( std::string &, std::string &);
    void set_data2(std::string);
    void afisare_dat();
    static void afisare_durata_rotunjita(int);
    void timp_chirie();
    void timp_proprietar();

};


#endif //TEMA1_PERIOADA_H
