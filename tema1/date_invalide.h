//
// Created by mihaela on 17.01.2021.
//

#ifndef TEMA1_DATE_INVALIDE_H
#define TEMA1_DATE_INVALIDE_H
#include <iostream>

class date_invalide : public std::runtime_error {
public:
    date_invalide(const std::string &);
};


#endif //TEMA1_DATE_INVALIDE_H
