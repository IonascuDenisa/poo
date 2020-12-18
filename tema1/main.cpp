#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

#include "incapere.h"
#include "adresa.h"
#include "locatar.h"
#include "proprietar.h"
#include "chirias.h"
#include "locuinta.h"

using std::cout;
using std::endl;

int main()
{
    std::ifstream f("date.txt");
    int nr_locuinte;
    f>>nr_locuinte; //linia1
    std::vector<locuinta>locuinte;
    while(nr_locuinte--)
    {
        bool chiriasi;
        f>>chiriasi; //linia2
        int nr_locuitori;
        f>>nr_locuitori; //linia3
        locuinta L(chiriasi,nr_locuitori);
        if(chiriasi==0)
            nr_locuitori--;

    ///citire adresa
        adresa a;
        a.citire_adresa(f);
        L.set_adresa(a);
    ///citire camere
        int nr_camere;
        f>>nr_camere; //linia5
        nr_camere+=5;
        while(nr_camere--)
        {
            incapere i;
            i.citiref(f);
            L.add_incaperi(i);
        }
    ///citire proprietar
        proprietar p;
        p.citiref(f); //linia13
        L.add_oameni(p);
        ///citire chiriasi

        if(chiriasi==1)
        {
            while(nr_locuitori--)
            {
                chirias c;
                 c.citiref(f);
                 L.add_oameni(c);
            }
        }
         else
             while(nr_locuitori--)
             {
                 locatar loc;
                 loc.citiref(f);
                L.add_oameni(loc);
             }
        locuinte.push_back(L);
    }
    for(auto &it:locuinte){
        it.afisare_oameni();
        cout<<endl<<"Locuinta are "<<it.aria_locuintei()<<" metrii patrati";
        cout<<endl<<endl;

    }
    f.close();
    return 0;
}


