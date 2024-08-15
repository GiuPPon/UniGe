/* Partendo dall’esercizio 2.9 (vedi precedente sezione) scrivere un programma che gioca più mani di
morra cinese però contro il computer. Come primo passo consigliamo di modificare l’esercizio 2.9 in 
modo da inserire per il turno del computer (che sostituisce Giocatore 2) la generazione di una mossa 
random (suggerimento: generare un numero intero tra 0 e 2 e associarlo alle mosse 0=>’f’, 1=>’c’, 
2=>’s’). Poi, alla fine di ogni mano il programma deve dire chi ha vinto (cioè il giocatore umano o il
computer) ha vinto e chiedere all’utente se vuole continuare; se l’utente risponde ’S’ o ’s’ prosegue
con un’altra mano, altrimenti termina. [ File partitamorra.cpp ] */

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    char mossa1, mossa2;
    char scelta;
    srand(time(NULL)); // questa linea va eseguita una volta sola nel programma

    do {
        do {
            cout<<"Giocatore 1, inserisci una mossa (indicandola come f, c oppure s)"<<endl;
            cin>>mossa1;
        } while ( mossa1 != 'f' && mossa1 != 'c' && mossa1 != 's' );

        int randomNumber = rand()%3; // questa invece va eseguita ogni volta che vogliamo generare un nuovo numero
        if (randomNumber == 0){
            mossa2 = 'f';
        } else if (randomNumber == 1){
            mossa2 = 'c';
        } else {
            mossa2 = 's';
        }
        cout << mossa2 << endl;
        
        if (mossa1 == 'f' && mossa2 == 'c' ) {
        cout<<"Giocatore 1 hai vinto!"<<endl;
        }

        if (mossa1 == 'c' && mossa2 == 'f' ) {
        cout<<"Giocatore 2 hai vinto!"<<endl;
        }

        if (mossa1 == 'f' && mossa2 == 's' ) {
        cout<<"Giocatore 2 hai vinto!"<<endl;
        }

        if (mossa1 == 's' && mossa2 == 'f' ) {
        cout<<"Giocatore 1 hai vinto!"<<endl;
        }

        if (mossa1 == 'c' && mossa2 == 's' ) {
        cout<<"Giocatore 1 hai vinto!"<<endl;
        }

        if (mossa1 == 'f' && mossa2 == 'f' ) {
        cout<<"Pareggio"<<endl;
        }

        if (mossa1 == 'c' && mossa2 == 'c') {
        cout<<"Pareggio"<<endl;
        }

        if (mossa1 == 's' && mossa2 == 's' ) {
        cout<<"Pareggio"<<endl;
        }

        cout << "Vuoi continuare? " << endl;
        cin >> scelta;
        if(scelta != 's' && scelta != 'S'){
            return 0;
        }
    } while (scelta == 's' || scelta == 'S');
}