/* La crescita della popolazione in una città può essere stimata a partire dalla popolazione iniziale,
aumentata di una certa percentuale (le nascite al netto delle morti) e di un numero (le persone che ci
si trasferiscono al netto di quelle che l’abbandonano).
Scrivere una funzione che presi come argomenti un intero non negativo (la popolazione iniziale), la 
percentuale di nascite al netto delle morti come intero fra −100 e 100 e il numero di persone che si 
trasferiscono nella città al netto di quelle che l’abbandonano, restituisce un intero pari al numero 
di abitanti dopo un anno. Si noti che sia la percentuale di nascite al netto delle morti che il numero
di persone che si trasferiscono nella città al netto di quelle che l’abbandonano possono essere 
negativi, positivi o nulli.
Nei casi particolari in cui il risultato della simulazione fornisca un numero negativo la funzione 
ritorna zero. [ File testf_population_sim.cpp ]
[SUGGERIMENTO: si noti che tutti i parametri sono interi, per cui usando moltiplicazione e divisione 
fra interi (nel giusto ordine) il risultato sarà ancora un intero.] */

#include <iostream>
#include <string>
using namespace std;

int population(int popolazioneIniziale, int tassoNatiMorti, int abbandono) {
    int popolazioneAnnoDopo = popolazioneIniziale + (popolazioneIniziale * tassoNatiMorti / 100) 
    + abbandono;
    if (popolazioneAnnoDopo < 0) {
        string err = "Errore = risultato negativo";
        throw err;
    }

    return popolazioneAnnoDopo;
}

int main() {

    int popolazioneIniziale, tassoNatiMorti, abbandono; 
    cout << "Inserire popolazione iniziale: ";
    cin >> popolazioneIniziale;
    cout << "Inserire percentuale di nascite al netto delle morti: ";
    cin >> tassoNatiMorti;
    cout << "Inserire numero persone trasferite: ";
    cin >> abbandono;

    int AnnoDopo = population(popolazioneIniziale, tassoNatiMorti, abbandono);

    cout << "La popolazione dopo un anno e': " << AnnoDopo << endl;
}