/* Analogamente al punto precedente, scrivere una funzione che prende, oltre ai parametri della 
funzione al punto 19, anchebun intero che rappresenta un numero di anni e restituisce la popolazione 
dopo quel numero di anni. [ File testf_population_sim2.cpp ]
[SUGGERIMENTO: Queste due funzioni possono essere implementate secondo tre approcci:
– potete scrivere la prima e usarla ripetutamente (ciclo) per calcolare la seconda
– oppure potete scrivere la seconda in maniera indipendente; in questo caso la prima contiene una 
chiamata alla seconda, essendo un caso particolare, in cui il numero di anni è uno. ] */

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


int populationDopoAnni(int popolazioneIniziale, int tassoNatiMorti, int abbandono, int anni) {
    int popolazione = popolazioneIniziale;
    for (int i = 0; i < anni; ++i) {
        popolazione = population(popolazione, tassoNatiMorti, abbandono);
    }
    return popolazione;
}

int main() {
    int popolazioneIniziale, tassoNatiMorti, abbandono, anni; 
    cout << "Inserire popolazione iniziale: ";
    cin >> popolazioneIniziale;
    cout << "Inserire percentuale di nascite al netto delle morti: ";
    cin >> tassoNatiMorti;
    cout << "Inserire numero persone trasferite: ";
    cin >> abbandono;
    cout << "Inserire quanti anni dopo: ";
    cin >> anni;

    int AnniDopo = populationDopoAnni(popolazioneIniziale, tassoNatiMorti, abbandono, anni);

    cout << "La popolazione dopo " << anni << "anni e': " << AnniDopo << endl;
}