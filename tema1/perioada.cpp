//
// Created by mihaela on 18.12.2020.
//

#include "perioada.h"
using std::cout;

void perioada::timp_proprietar()
{
    int x=durata();
    cout<<"proprietate personala de ";afisare_durata_rotunjita(x);
}
void perioada::timp_chirie()
{
    int x=durata(data3,data1);
    int y=durata(data2,data3);
    cout<<"inchiriat de ";afisare_durata_rotunjita(x);
    if(y>=0)
    {
        cout<<" si va mai locui inca "; afisare_durata_rotunjita(y);
    }
    else cout<<" pe o perioada nederminata";
}
void perioada::afisare_durata_rotunjita(int zi) {
    if (zi < 30) {
        if (zi >= 20)
            cout << " de";
        if (zi > 1 && zi < 20)
            cout << " zile ";
        if (zi == 1)
            cout << "o zi";
        if (zi == 0)
            cout << " nici o zi ";
    }
    if ((zi >= 30) && zi < 365)
    {
        if ((zi / 30) == 1)
            cout << "o luna";
        else
            cout << zi / 30 << " luni ";
    }
    if(zi>=365)
    {
        cout<<zi/365;
        if((zi/365) >= 20 )
            cout<<" de";
        if((zi/365)==1)
            cout<<" an";
        else
            cout<<" ani";
    }

}
void perioada::afisare_dat() {cout<<"marinela"<<data1<<" "<<data2<<" "<<"data curenta este:"<<data3;}
void perioada::set_data2(std::string d)
{
    data2=d;
}
int perioada::rdn(int y, int m, int d) { // Rata Die day one is 0001-01-01
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}
int perioada::durata( std::string &data3,  std::string &data1)
{
    std::string zi_data3_string=data3.substr(0,2);
    int zi_data3=std::stoi(zi_data3_string);

    std::string luna_data3_string=data3.substr(3,2);
    int luna_data3=std::stoi(luna_data3_string);

    std:: string an_data3_string=data3.substr(6,4);
    int an_data3=std::stoi(an_data3_string);

    std::string zi_data1_string=data1.substr(0,2);
    int zi_data1=std::stoi(zi_data1_string);

    std::string luna_data1_string=data1.substr(3,2);
    int luna_data1=std::stoi(luna_data1_string);

    std:: string an_data1_string=data1.substr(6,4);
    int an_data1=std::stoi(an_data1_string);

    int zile = rdn(an_data3, luna_data3, zi_data3) - rdn(an_data1, luna_data1, zi_data1);
    return zile;
}
int perioada::durata()
{
    std::string zi_data3_string=data3.substr(0,2);
    int zi_data3=std::stoi(zi_data3_string);

    std::string luna_data3_string=data3.substr(3,2);
    int luna_data3=std::stoi(luna_data3_string);

    std:: string an_data3_string=data3.substr(6,4);
    int an_data3=std::stoi(an_data3_string);

    std::string zi_data1_string=data1.substr(0,2);
    int zi_data1=std::stoi(zi_data1_string);

    std::string luna_data1_string=data1.substr(3,2);
    int luna_data1=std::stoi(luna_data1_string);

    std:: string an_data1_string=data1.substr(6,4);
    int an_data1=std::stoi(an_data1_string);

    int zile = rdn(an_data3, luna_data3, zi_data3) - rdn(an_data1, luna_data1, zi_data1);
    return zile;
}
perioada::perioada(std::string data1,std::string data2)
{
    this->data1=data1;
    this->data2=data2;
}