/* Definire una struct Date per rappresentare date, ossia informazioni relative a giorno, mese ed anno
(tutti memorizzabili con degli interi senza segno)
Scrivere un programma che legge la data corrente D una data qualsiasi D1. Dopo avere verificato la 
correttezza di D1 (per D assumiamo che sia inserita correttamente), controlla se D1 sia una data
passata o futura e stampa un messaggio di output opportuno. [ File whenDate.cpp ]
[SUGGERIMENTO: Per agevolare il controllo della correttezza della data conviene chiedere l’anno come 
primo dato in input, per verificare se sia o no bisestile. Tale controllo fornisce indicazioni sul 
controllo successivo, quello del mese e del giorno, anche se in casi limitati.]
[SUGGERIMENTO: per verificare se la data sia passata o futura si può procedere per passi, controllando
prima l’anno: se è minore dell’anno in corso allora la data è sicuramente passata, se è maggiore 
dell’anno in corso allora la data è sicuramente futura. Se è esattamente l’anno in corso allora 
occorre controllare il mese e, solo nel caso anch’esso non sia informativo (ossia uguale al mese 
corrente) passare al controllo del giorno.] */

#include <iostream>
using namespace std;

struct Date {
unsigned int day;
unsigned int month;
unsigned int year;
};

int main() {
    // Lettura della data corrente
    Date D;
    cout << "Inserisci la data corrente (giorno mese anno): ";
    cin >> D.day;
    cin >> D.month;
    cin >> D.year;

    // Lettura della data D1
    Date D1;
    cout << "Inserisci una data qualsiasi (giorno mese anno): ";
    cin >> D1.day;
    cin >> D1.month;
    cin >> D1.year;

    // Verifica se D1 è una data passata o futura rispetto alla data corrente
    if (D1.year < D.year) {
        cout << "La data inserita e' passata rispetto alla data corrente." << endl;
    } else if (D1.year > D.year) {
        cout << "La data inserita e' futura rispetto alla data corrente." << endl;
    } else {
        // Se l'anno è lo stesso, controlla il mese
        if (D1.month < D.month) {
            cout << "La data inserita e' passata rispetto alla data corrente." << endl;
        } else if (D1.month > D.month) {
            cout << "La data inserita e' futura rispetto alla data corrente." << endl;
        } else {
            // Se anche il mese è lo stesso, controlla il giorno
            if (D1.day < D.day) {
                cout << "La data inserita e' passata rispetto alla data corrente." << endl;
            } else if (D1.day > D.day) {
                cout << "La data inserita e' futura rispetto alla data corrente." << endl;
            } else {
                cout << "La data inserita e' la stessa della data corrente." << endl;
            }
        }
    }
}