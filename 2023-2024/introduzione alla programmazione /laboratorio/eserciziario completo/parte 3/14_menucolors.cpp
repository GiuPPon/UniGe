/* Scrivere un programma che chiede all’utente di scegliere il suo colore preferito presentandogli un 
menu con almeno 5 scelte di colori i cui nomi iniziano con una lettera diversa (ad esempio rosso, 
verde, blu, giallo e arancio). Per selezionare la scelta l’utente potrà usare l’iniziale del colore 
scelto, indifferentemente in maiuscolo o minuscolo. Se il carattere inserito non corrisponde a nessun 
colore proposto il programma ricomincerà da capo presentando il menu con le scelte. 
[ File menucolors.cpp ] [SUGGERIMENTO: Come base di partenza può essere usato l’esercizio 3.6] */

#include <iostream>
#include <string>
using namespace std;

int main () {
    char answer;
    string color;

    bool sceltaValida = false;

    while (!sceltaValida) {
        cout << "Scegli un colore:" << endl;
        cout << "R , r - Rosso" << endl;
        cout << "V , v - Verde" << endl;
        cout << "B , b - Blu" << endl;
        cout << "G , g - Giallo" << endl;
        cout << "A , a - Arancio" << endl;

        cin >> answer;

        if (answer >= 'a' && answer <= 'z') {
            answer -= ('a' - 'A'); // Converte in maiuscolo
        }

        switch(answer) {
            case 'R':
                color = "Rosso";
                sceltaValida = true;
                break;
            case 'V':
                color = "Verde";
                sceltaValida = true;
                break;
            case 'B':
                color = "Blu";
                sceltaValida = true;
                break;
            case 'G':
                color = "Giallo";
                sceltaValida = true;
                break;
            case 'A':
                color = "Arancio";
                sceltaValida = true;
                break;
            default:
                cout << "Scelta non valida. Riprova." << endl;
        }
    }
    cout << "Hai scelto il colore: " << color << endl;
}