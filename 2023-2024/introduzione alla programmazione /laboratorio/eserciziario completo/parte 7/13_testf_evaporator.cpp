/* Un evaporatore è una macchina in cui viene inserita una certa quantità iniziale di acqua e che ogni
giorno ne disperde una percentuale prefissata nell’ambiente. Quando l’acqua contenuta scende sotto la 
soglia minima di funzionamento la macchina si spegne per evitare danni.
Scrivere una funzione che presi come argomenti un float che rappresenta i litri di acqua inizialmente 
introdotti nella macchina, un int che rappresenta la percentuale di evaporazione giornaliera e un 
float che indica la soglia minima al di sotto della quale la macchina si spegne, restituisce il numero
di giorni in cui la macchina può continuare ad operare senza essere riempita. Si assuma che tutti gli 
argomenti siano sempre non negativi. [ File testf_evaporator.cpp ] */

#include <iostream>
using namespace std;

int GiorniFunzionamento(float LIniziali, int percentEvaporazione, float sogliaMinima) {
    int giorni = 0;
    while (LIniziali > sogliaMinima) {
        LIniziali = LIniziali - (LIniziali * percentEvaporazione / 100.0);
        giorni++;
    }
    return giorni;
}

int main() {
    cout << "Inserire i litri di acqua inizialmente introdotti nella macchina";
    float LIniziali;
    cin >> LIniziali;
    cout << "Inserire la percentuale di evaporazione giornaliera";
    int percentEvaporazione;
    cin >> percentEvaporazione;
    cout << "Inserire la soglia minima al di sotto della quale la macchina si spegne";
    float sogliaMinima;
    cin >> sogliaMinima;

    int giorni = GiorniFunzionamento(LIniziali, percentEvaporazione, sogliaMinima);

    cout << "La macchina puo' operare per " << giorni << " giorni senza essere riempita." << endl;
}