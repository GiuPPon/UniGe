#include <iostream>
#include <string>
#include "list.h"

using namespace std;

int main(){
    
    List l=nullptr;

    inserimentoInTesta(l, "Venezia");
    cout<<stampaAdiacenti(l, "Venezia")<<endl;
    inserimentoInTesta(l, "Milano");
    inserimentoInTesta(l, "Torino");
    inserimentoInTesta(l, "Genova");
    // inserimentoInTesta(l, "Venezia");

    cout<<stampaAndata(l)<<endl;
    cout<<stampaRitorno(l)<<endl;

    cout<<stampaAdiacenti(l, "Venezia")<<endl;
    cout<<stampaAdiacenti(l, "Milano")<<endl;
    cout<<stampaAdiacenti(l, "Torino")<<endl;
    cout<<stampaAdiacenti(l, "Genova")<<endl;
    cout<<stampaAdiacenti(l, "Pisa")<<endl;

}