/* Scrivere una funzione che prende come argomenti un intero non negativo (la popolazione iniziale), 
la percentuale di nascite al netto delle morti come intero fra 0 e 100 e restituisce il numero di anni
necessario a raddoppiare gli abitanti se la popolazione è in crescita, o a dimezzarli se la popolazione 
sta diminuendo (nell’ipotesi che non vi siano trasferimenti). [ File testf_population_sim3.cpp ] */

#include <iostream>
#include <string>
using namespace std;

int population_3(int PopolazioneIniziale, int BirthRate) {
    if  (PopolazioneIniziale < 0 || BirthRate < 0 || BirthRate > 100) {
        string err = "Input non valido";
        throw err;
    }

    double growthRate = 1 + (static_cast<double>(BirthRate) / 100);

    if (growthRate == 1) {
        return -1;
    }

    int years = 0;
    double population = PopolazioneIniziale;

    
    while (population * growthRate != population && population / growthRate != population) {
        if (growthRate > 1) {
            population = population * growthRate;
        } else {
            population = population / growthRate;
        }
        years++;
    }

    return years;
}

int main() {
    int PopolazioneIniziale, BirthRate;
    cout << "Inserisci la popolazione iniziale: ";
    cin >> PopolazioneIniziale;
    cout << "Inserisci la percentuale di nascite al netto delle morti (da 0 a 100): ";
    cin >> BirthRate;

    try {
        int years = population_3(PopolazioneIniziale, BirthRate);
        if (years == -1) {
            cout << "La popolazione non cambierà nel tempo." << endl;
        } else {
            if (years > 0) {
                cout << "Saranno necessari " << years << " anni per raddoppiare la popolazione." << endl;
            } else {
                cout << "Saranno necessari " << -years << " anni per dimezzare la popolazione." << endl;
            }
        }
    } catch (string& err) {
        cout << err << endl;
    }
}