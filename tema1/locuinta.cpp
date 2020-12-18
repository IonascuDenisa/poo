//
// Created by mihaela on 18.12.2020.
//

#include "locuinta.h"

using std::cout;
using std::endl;

float locuinta::aria_locuintei()
{
    float arie=0;
    for(auto &it: incaperi)
    {
        arie+=it.arie();
    }
    return arie;
}
void locuinta::set_nr_locuitori(int n) {nr_locuitori=n;}
void locuinta ::set_chiriasi(bool b) {chiriasi=b;}
void locuinta::afisare_oameni()
{
    auto it=oameni.begin();
    std::advance(it,1); //++it
    cout<<oameni[0].get_apelativ()<<oameni[0].get_nume()<<"este proprietarul locuintei de la adresa: "<<a.get_adresa();cout<<endl;
    if(chiriasi && nr_locuitori==1)
    {
        cout << "si locuieste singur.";
    }
    if(chiriasi && nr_locuitori>1 )
    {
        cout << "si locuieste alaturi de : ";
    }
    if(!chiriasi) cout<<"pe care a inchiriat-o. Chiriasii sunt: ";
    while(it!=oameni.end())
    {
        cout<<*it;
        ++it;
    }
}
void locuinta::afisare_adresa()
{
    a.afisare_adresa();
}
std::string locuinta::get_adresa()
{
    return a.get_adresa();
}
void locuinta::set_adresa(adresa &ad)
{
    a=ad;
}
void locuinta::add_oameni(locatar const & om)
{
    oameni.push_back(om);
}
void locuinta::add_incaperi(incapere const &i)
{
    incaperi.push_back(i);
}
void locuinta::afisare_incaperi()
{
    for(auto &it:incaperi)
    {
        cout<<it<<endl;
    }
}

