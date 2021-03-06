//
// Created by mihaela on 18.12.2020.
//

#include "locuinta.h"
#include "incapere.h"

using std::cout;
using std::endl;

locuinta::locuinta (bool chiriasi,int nr_locuitori)
{
    this->chiriasi=chiriasi;
    this->nr_locuitori=nr_locuitori;
}
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
    a = ad;
}

void locuinta::add_oameni(locatar &om) {
    oameni.push_back(om);
}

void locuinta::add_incaperi(incapere const &i) {
    incaperi.push_back(i);
}

void locuinta::afisare_incaperi() {
    for (auto &it:incaperi) {
        cout << it << endl;
    }
}

std::ostream &operator<<(std::ostream &os, const locuinta &locuinta) {
    os << "chiriasi: " << locuinta.chiriasi << " nr_locuitori: " << locuinta.nr_locuitori << " a: " << locuinta.a;
    //<< " incaperi: " << locuinta.incaperi << " oameni: " << locuinta.oameni;
    return os;
}

void locuinta::afisare(std::ostream &os) const {
    os << "chiriasi: " << locuinta::chiriasi << " nr_locuitori: " << locuinta::nr_locuitori << " a: " << locuinta::a;

}

locuinta::~locuinta() {


}
