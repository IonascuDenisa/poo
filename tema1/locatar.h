//
// Created by mihaela on 18.12.2020.
//

#ifndef TEMA1_LOCATAR_H
#define TEMA1_LOCATAR_H
#include <iostream>

class locatar {
protected:
    std::string nume;
    std::string prenume;
    std::string cnp;
    bool fm;
public:
    explicit locatar(std::string ="Popescu",std::string="Ana Cristina",std::string ="601225412043", bool=true );
    locatar(const locatar& );
    std::string get_nume();
    std::string get_apelativ() const;
    void schimb_prenume(std::string&);
    void schimb_cnp(std::string);
    void schimb_fm();
    friend std::ostream& operator<<(std::ostream &os , locatar &p);
    virtual void citiref(std::ifstream &);
    static std::string get_adresa();
    void afisare_adresa();

};


#endif //TEMA1_LOCATAR_H
