/* Scrivere un programma che scrive in lettere i nomi italiani delle ore, approssimati ai 15 minuti. 
Il programma deve prendere in input due valori interi, uno tra 0 e 23 (ore) e l’altro tra 0 e 59 
(minuti) e se i valori dati in input non rispettano il vincolo stampa un messaggio di errore ed esce 
ritornando -1 come codice di errore. Se l’input è corretto, scrive “Sono le ore " seguito dal valore 
delle ore (p.es. se è 11 scrive “undici", ma se è 1 scrive “l’una" e se è 0 scrive “mezzanotte") e dal
valore dei minuti, approssimato per difetto al quarto d’ora (ad esempio se i minuti sono 15-29 scrive
“ e un quarto", se 30-44 scrive “ e mezza", se 45-59 scrive “ e tre quarti"; se 0-14 invece non scrive
niente). Infine, se i minuti non sono divisibili esattamente per 15, scrive “ passate". Esempio: 12:34
"Sono le ore dodici e mezza passate", 00:56 "Sono le ore mezzanotte e tre quarti passate".
[ File saytime.cpp ] */

#include <iostream>
using namespace std;

int main () {
    int ore, minuti;
    cout << "inserire ora: ";
    cin >> ore;
    cout << "inserire minuti: ";
    cin >> minuti;

    cout << "sono le ore ";

    switch (ore) {
        case 0:
            cout << "mezzanotte ";
            break;

        case 1:
            cout << "l'una ";
            break;

        case 2:
            cout << "due ";
            break;

        case 3:
            cout << "tre ";
            break;

        case 4:
            cout << "quattro ";
            break;

        case 5:
            cout << "cinque ";
            break;

        case 6:
            cout << "sei ";
            break;

        case 7:
            cout << "sette ";
            break;

        case 8:
            cout << "otto ";
            break;

        case 9:
            cout << "nove ";
            break;

        case 10:
            cout << "dieci ";
            break;

        case 11:
            cout << "undici ";
            break;

        case 12:
            cout << "dodici ";
            break;
        
        case 13:
            cout << "tredici ";
            break;

        case 14:
            cout << "quattordici ";
            break;

        case 15:
            cout << "quindici ";
            break;

        case 16:
            cout << "sedici ";
            break;
        
        case 17:
            cout << "diciassette ";
            break;

        case 18:
            cout << "diciotto ";
            break;

        case 19:
            cout << "diciannove ";
            break;

        case 20:
            cout << "venti ";
            break;

        case 21:
            cout << "ventuno ";
            break;

        case 22:
            cout << "ventidue ";
            break;

        case 23:
            cout << "ventitre ";
            break;
        
        default:
            cout << "Errore" << endl;
            return -1;
    }

    if (15 <= minuti && minuti <= 29) {
        cout << "e un quarto ";
    } else if (30 <= minuti && minuti <= 44) {
        cout << "e mezza ";
    } else if (45 <= minuti && minuti <= 59) {
        cout << "e tre quarti ";
    }

    if (minuti % 15 != 0) {
        cout << "passate" << endl;
    }
}