/* (Puntatori) Scrivete un programma in cui usate i puntatori per accedere alle locazioni di variabili.
Siete incoraggiati a migliorare i messaggi di stampa minimali proposti nell’esercizio in modo da capire 
più facilmente quali valori state stampando, ad esempio aggiungendo frasi come indirizzo di s1 == 
oppure valore di p ==. A inizio esecuzione si ha s1="Hello" e s2="World" mentre a termine esecuzione 
s1="Ciao" e s2="Mondo". Tutte le modifiche per sostituire le stringhe sono effettuate tramite il 
puntatore p. Analizzare i valori e gli indirizzi restituiti e verificare che il comportamento sia 
corretto. [ File provaptr.cpp ] */

#include <iostream>
#include <string>
using namespace std;

int main () {
    // dichiarare due variabili s1 e s2 di tipo string inizializzate rispettivamente a "Hello" e "World"
    string s1 = "Hello";
    string s2 = "World";
    // stampare "Variabile s1: " seguito dal contenuto di s1 e l'indirizzo di s1
    cout << "Variabile s1: " << s1 << " (Indirizzo: " << static_cast<void*>(&s1) << ")" << endl;
    // stampare "Variabile s2: " seguito dal contenuto di s2 e l'indirizzo di s2
    cout << "Variabile s2: " << s2 << " (Indirizzo: " << static_cast<void*>(&s2) << ")" << endl;
    // dichiarare una variabile p di tipo puntatore a string inizializzata con l'indirizzo di s1
    string *p = &s1;
    // stampare il messaggio "p contiene " ... " (un indirizzo)"
    cout << "p contiene " << static_cast<void*>(p) << " (un indirizzo)" << endl;
    // stampare il messaggio "mentre con *p si ottiene " ... " (il contenuto della variabile puntata da p)"
    cout << "mentre con *p si ottiene " << *p << " (il contenuto della variabile puntata da p)" << endl;
    // assegnare all'area di memoria puntata da p la stringa "Ciao"
    *p = "Ciao";
    // stampare il messaggio "p contiene " ... " (un indirizzo)"
    cout << "p contiene " << static_cast<void*>(p) << " (un indirizzo)" << endl;
    // stampare il messaggio "mentre con *p si ottiene " ... " (il contenuto della variabile puntata da p)"
    cout << "mentre con *p si ottiene " << *p << " (il contenuto della variabile puntata da p)" << endl;
    // assegnare a p l'indirizzo di s2
    p = &s2;
    // stampare il messaggio "p contiene " ... " (un indirizzo)"
    cout << "p contiene " << static_cast<void*>(p) << " (un indirizzo)" << endl;
    // stampare il messaggio "mentre con *p si ottiene " ... " (il contenuto della variabile puntata da p)"
    cout << "mentre con *p si ottiene " << *p << " (il contenuto della variabile puntata da p)" << endl;
    // assegnare all'area di memoria puntata da p la stringa "Mondo"
    *p = "Mondo";
    // stampare il messaggio "p contiene " ... " (un indirizzo)"
    cout << "p contiene " << static_cast<void*>(p) << " (un indirizzo)" << endl;
    // stampare il messaggio "mentre con *p si ottiene " ... " (il contenuto della variabile puntata da p)"
    cout << "mentre con *p si ottiene " << *p << " (il contenuto della variabile puntata da p)" << endl;
    // stampare "Variabile s1: " seguito dal contenuto di s1 e l'indirizzo di s1
    cout << "Variabile s1: " << s1 << " (Indirizzo: " << static_cast<void*>(&s1) << ")" << endl;
    // stampare "Variabile s2: " seguito dal contenuto di s2 e l'indirizzo di s2
    cout << "Variabile s2: " << s2 << " (Indirizzo: " << static_cast<void*>(&s2) << ")" << endl;
}

/* [SUGGERIMENTO: Per stampare gli indirizzi (riferimenti a variabili e valore di puntatori) in maniera 
leggibile, è preferibile usare static_cast<void*>(...) mettendo l’indirizzo al posto dei puntini.] */