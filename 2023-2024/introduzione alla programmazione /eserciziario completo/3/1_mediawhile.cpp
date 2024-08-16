/* Scrivere un programma che legge un certo numero di valori reali e ne stampa la media (notare che
lo schema seguente fissa una serie di dettagli ulteriori non specificati nel “testo” dell’esercizio). */

#include <iostream>
using namespace std;

int main () {
    cout << "Di quanti numeri vuoi fare la media?" << endl;
    int how_many;
    cin >> how_many;
    
    if (how_many <= 0) {
        cout << "Errore: il numero doveva essere positivo" << endl;
        return 42;
    }
    
    float sum = 0;
    int count = 0;
    
    while (count < how_many) {
        cout << "Inserisci un numero " << endl;
        float x;
        cin >> x;
        sum = sum + x;
        ++count;
    }
    
    cout << "La media e' " << sum / how_many << endl;
}