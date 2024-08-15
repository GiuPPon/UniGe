/* Scrivere una funzione onlineAverage senza argomenti che chiede all’utente di inserire e legge 
numeri reali sino a che l’utente vuole concludere l’inserimento. Quindi ad ogni ciclo oltre al numero 
reale chiede all’utente se vuole continuare e legge la risposta (y continua e n si ferma). Finito il 
ciclo di lettura restituisce la media dei numeri letti (di tipo double). Stampare quindi il valore 
della media nel main. NB: non è richiesto salvare i valori inseriti in un array, quindi NON usare 
alcun array. [ File testf_online_average.cpp ] */

#include <iostream> 
using namespace std;

double onlineAverage () {
    double sum = 0;
    int count = 0;
    char answer;

    do {
        double number;
        cout << "Inserisci un numero reale: ";
        cin >> number;

        sum = sum + number;
        count++;

        cout << "Vuoi inserire un altro numero? (y/n): ";
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');

    return sum / count;
}

int main () {
    double media = onlineAverage();
    cout << "La media e' " << media << endl;
}