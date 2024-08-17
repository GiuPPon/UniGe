/* Definire una struct Time per mantenere informazioni orarie come terne ora, minuti, secondi 
(memorizzabili con degli interi senza segno).
Scrivere un programma che legge le informazioni relative a due variabili T1, T2 di tipo Time. Poi 
verifica (1) la correttezza dei dati inseriti (cioè che i valori di ore, minuti e secondi siano 
ammissibili) e (2) che T1 rappresenti un’ora precedente (o uguale) a T2. In caso affermativo calcola
il tempo trascorso tra i due orari, assumendo che si riferiscano allo stesso giorno
(e.g., sono trascorse 2 ore, 5 minuti e 3 secondi). [ File timeDiff.cpp ] */

#include <iostream>
using namespace std;

struct Time {
    int ora;
    int minuti;
    int secondi;
};

int main () {
    Time T1, T2;

    cout << "Inserire primo orario: " << endl;
    cout << "ora: ";
    cin >> T1.ora;
    cout << "minuti: ";
    cin >> T1.minuti;
    cout << "secondi: ";
    cin >> T1.secondi;

    cout << "Inserire secondo orario (ora, minuti, secondi): ";
    cout << "ora: ";
    cin >> T2.ora;
    cout << "minuti: ";
    cin >> T2.minuti;
    cout << "secondi: ";
    cin >> T2.secondi;

    if (T1.ora > 24) {
        cout << "primo orario: ora incorretta" << endl;
    } else if (T2.ora >= 24) {
        cout << "secondo orario: ora incorretta" << endl;
    } else if (T1.minuti >= 60) {
        cout << "primo orario: minuti incorretti" << endl;
    } else if (T2.minuti >= 60) {
        cout << "secondo orario: minuti incorretti" << endl;
    } else if (T1.secondi >= 60) {
        cout << "primo orario: secondi incorretti" << endl;
    } else if (T1.secondi >= 60) {
        cout << "secondo orario: secondi incorretti" << endl;
    }

    if (T1.ora > T2.ora) {
        cout << "errore: il primo orario non e' precedente al secondo" << endl;
        return 0;
    } else {
        int differenzaOre = T2.ora - T1.ora;
        int differenzaMinuti = T2.minuti - T1.minuti;
        int differenzaSecondi = T2.secondi - T1.secondi;

        if (differenzaSecondi < 0) {
            --differenzaMinuti;
            differenzaSecondi = differenzaSecondi + 60;
        }
        if (differenzaMinuti < 0) {
            --differenzaOre;
            differenzaMinuti = differenzaMinuti + 60;
        }

        cout << "Sono trascorse " << differenzaOre << " ore, " << differenzaMinuti << " minuti e ";
        cout << differenzaSecondi << " secondi tra il primo e il secondo orario." << endl;
    }
}