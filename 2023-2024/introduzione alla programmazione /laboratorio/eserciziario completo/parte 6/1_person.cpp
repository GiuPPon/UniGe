#include <iostream>
#include <string>
using namespace std;

// Definire un tipo struct Person per rappresentare i dati relativi a una persona:
struct Person {
    string name;
    string surname;
    int birthYear;
};

int main () {
    // Dichiarare due variabili di tipo Person 
    Person me, you;

    //Assegnare valori ai membri di me e di you
    me.name = "Bruce";
    me.surname = "Wayne";
    me.birthYear = 1939;
    you.name = "Clark";
    you.surname = "Kent";
    you.birthYear = 1933;

    // Accedere (in lettura) ai valori dei membri, qui per stamparli
    cout << "My name is " << me.name << " " << me.surname << endl;
    cout << "I was born in " << me.birthYear << endl;
    // Assegnare il valore di un’intera variabile struct a un’altra
    me = you;
    // Accedere (in lettura) ai valori dei membri, qui per stamparli
    cout << "My name is " << me.name << " " << me.surname << endl;
    cout << "I was born in " << me.birthYear << endl;

}