/* (Puntatori + Compilazione Separata) Scrivere una funzione in un file dedicato che prende come 
argomenti 3 variabili di tipo char (per riferimento), propone all’utente di scegliere una di esse 
stampando il valore che contengono e restituisce l’indirizzo di quella scelta (ad esempio, per poterla 
modificare nel main). Se non viene scelta nessuna variabile ritorna nullptr. Se ad una richiesta non 
si risponde 'y' la funzione termina ritornando il puntatore alla variabile che è stata scelta
(o a nullptr se era la prima domanda). */

#include <iostream>
#include "selectVar_funct.h"
using namespace std;

char* selectVar(char& a, char& b, char& c) {
    // definire un puntatore di tipo char p inizializzato al puntatore nullo
    char *p = nullptr;
    // stampare i messaggi "Scegli fra queste variabili" e
    cout << "Scegli fra queste variabili" << endl;
    // "potrai cambiare idea in seguito e sceglierne una diversa che preferisci"
    cout << "potrai cambiare idea in seguito e sceglierne una diversa che preferisci" << endl;
    // stampare il messaggio "Vuoi la prima (y/n)? contiene " e stampare a
    cout << "Vuoi la prima (y/n)? contiene " << a << endl;
    // dichiarare una variabile answer di tipo char
    char answer;
    // leggere answer
    cin >> answer;
    // se la risposta è 'y' o 'Y'
    // assegnare a p l'indirizzo di a
    if (answer == 'y' || answer == 'Y') {
        p = &a;
    }
    // stampare il messaggio "Preferisci la seconda (y/n)? contiene " e stampare b
    cout << "Preferisci la seconda (y/n)? contiene " << b << endl;
    // leggere answer
    cin >> answer;
    // se la risposta è 'y' o 'Y'
    // assegnare a p l'indirizzo di b
    if (answer == 'y' || answer == 'Y') {
        p = &b;
    }
    // stampare il messaggio "Preferisci la terza (y/n)? contiene " e stampare c
    cout << "Preferisci la terza (y/n)? contiene " << c << endl;
    // leggere answer
    cin >> answer;
    // se la risposta è 'y' o 'Y'
    // assegnare a p l'indirizzo di c
    if (answer == 'y' || answer == 'Y') {
    p = &c;
    }
    // restituire p
    return p;
}

// s = messaggio da visualizzare
char* proposeVar (string s, char& d) {
    cout << s;
    char answer;
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {
        return &d;
    } else {
        return nullptr;
    }
}

void printChoice (char *scelta, char& e, )