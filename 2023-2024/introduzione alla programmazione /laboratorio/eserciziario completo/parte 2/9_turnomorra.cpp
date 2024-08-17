/* Scrivere un programma che implementa un turno di gioco di forbice-carta-sasso, ovvero che legge in 
input la mossa dei due giocatori (ogni mossa è un carattere ’f’, ’c’, ’s’, quindi due caratteri) e 
restituisce in output chi ha vinto seguendo le regole del gioco ("Giocatore 1 hai vinto!" oppure 
"Giocatore 2 hai vinto!"). Il programma deve controllare che i giocatori abbiano inserito uno dei tre
caratteri validi. [ File turnomorra.cpp ] */

#include <iostream>
using namespace std;

int main () {
    char mossa1, mossa2;

    do {
        cout<<"Giocatore 1, inserisci una mossa (indicandola come f, c oppure s)"<<endl;
        cin>>mossa1;
    } while ( mossa1 != 'f' && mossa1 != 'c' && mossa1 != 's' );

    do {
        cout<<"Giocatore 2, inserisci una mossa (indicandola come f, c oppure s)"<<endl;
        cin>>mossa2;
    } while (mossa2 != 'f' && mossa2 != 'c' && mossa2 != 's' );
    
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
}