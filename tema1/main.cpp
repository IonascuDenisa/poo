#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;

#include "incapere.h"
#include "adresa.h"
#include "locatar.h"
#include "proprietar.h"
#include "chirias.h"
#include "locuinta.h"
#include "adresa_builder.h"
#include "date_invalide.h"

int main() {
    std::ifstream f("date.txt");
    int nr_locuinte = -16;
    f >> nr_locuinte;//linia1

    try {
        if (nr_locuinte <= 0)
            throw date_invalide("numarul de locuinte introdus nu este corect");
    }
    catch (date_invalide &e) {
        std::cout << "eroare citire: " << e.what() << "\n";
    }

    std::vector<locuinta> locuinte;
    while (nr_locuinte) {
        bool chiriasi;
        f >> chiriasi; //linia2
        int nr_locuitori;
        f >> nr_locuitori; //linia3
        locuinta L(chiriasi, nr_locuitori);
        if (!chiriasi)
            nr_locuitori--;

        ///citire adresa

        adresa a;
        a.citire_adresa(f);
        L.set_adresa(a);
        ///citire camere
        int nr_camere;
        f >> nr_camere; //linia5
        nr_camere += 5;
        while (nr_camere) {
            incapere i;
            i.citiref(f);
            L.add_incaperi(i);
            nr_camere--;
        }
        ///citire proprietar
        proprietar p;

        p.citiref(f); //linia13
        L.add_oameni(p);
        ///citire chiriasi

        if (chiriasi == 1) {
            while (nr_locuitori--) {
                chirias c;
                c.citiref(f);
                L.add_oameni(c);
            }
        } else {
            while (nr_locuitori--) {
                locatar loc;
                loc.citiref(f);
                L.add_oameni(loc);
            }
        }

        locuinte.push_back(L);
        nr_locuinte--;
    }
    for (auto &it:locuinte) {
        it.afisare_oameni();
        cout << endl << "Locuinta are " << it.aria_locuintei() << " metrii patrati";
        cout << endl << endl;

    }

    adresa_builder add;
    adresa addd = add.bloc("bloc_nou").apartament(13).build();
    cout << endl << "adresa noua: " << addd;
    * /
    f.close();
    return 0;
}