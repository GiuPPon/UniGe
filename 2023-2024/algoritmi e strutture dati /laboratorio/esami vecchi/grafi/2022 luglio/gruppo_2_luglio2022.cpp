/****************************************************/
/*          ESAME DI LABORATORIO DI ASD             */
/****************************************************/

// Descrizione:
// In questo esame consideriamo grafi rappresentati tramite matrici di adiacenza. Il grafo viene utilizzato per rappresentare persone e i loro incontri avvenuti nell'arco di una giornata (per esempio su MS Teams).
// Di conseguenza, il grafo e' non orientato e ogni arco e' etichettato dal numero di ore le persone sono state in contatto.
//Per esempio, supponiamo di avere il grafo seguente:
//
// 0 1 0
// 1 0 3
// 0 3 0
//
// Questo grafo contiene 3 persone, dove Persona 0 e' stata in meeting con Persona 1 per 1 ora, Persona 1 e' stata in meeting con Persona 0 per 1 ora e con Persona 2 per 3 ore.
// Infine Persona 2 e' stata in meeting con Persona 1 per 3 ore.

// Nome:
// Cognome:
// Matricola:

#include <iostream>

using namespace std;

/****************************************************************/
// Definizione Lista semplice ausiliaria (utile successivamente)
/****************************************************************/

struct Cella {
    int id;
    Cella* prossimo;
};

typedef Cella* Lista; // definiamo lista come un puntatore a cella

Lista lista_vuota = nullptr; // la lista vuota corrisponde a nullptr
int elemento_vuoto = -1; // viene ritornato quando la lista è vuota e si prova a rimuovere un elemento da essa

// funzione che crea la lista vuota
void creaLista(Lista& lista) {
    lista = lista_vuota;
}

// funzione che aggiunge elemento alla lista (aggiunge in coda)
void aggiungiElemento(Lista& lista, int id) {
    if(lista == lista_vuota) {
        lista = new Cella();
        lista->id = id;
        lista->prossimo = lista_vuota;
    }
    else {
        Lista aux = lista;
        while(aux->prossimo != lista_vuota) {
            aux = aux->prossimo;
        }
        aux->prossimo = new Cella();
        aux->prossimo->id = id;
        aux->prossimo->prossimo = lista_vuota;
    }
}

// funzione che rimuove elemento dalla lista (rimuove in testa)
int rimuoviElemento(Lista& lista) {
    if(lista == lista_vuota) {
        return elemento_vuoto;
    }
    int elemento = lista->id;
    Lista aux = lista;
    lista = lista->prossimo;
    delete aux;
    return elemento;
}

// funzione che stampa a video la lista
void printLista(Lista lista) {
    cout << "[";
    while(lista != lista_vuota) {
        cout << " Persona " << lista->id;
        lista = lista->prossimo;
        if(lista != lista_vuota) cout << ",";
    }
    cout << " ]" << endl;
}

/****************************************************************/
// Definizione Grafo con matrice di adiacenza
/****************************************************************/

typedef int Tempo; // durata del contatto

const int max_persone = 10; // massimo numero di persone che il grafo puo' attualmente contenere

struct Grafo {
    int n_persone;                            // numero corrente di persone nel grafo
    Tempo meetings[max_persone][max_persone]; // matrice di adiacenza dei meetings tra le persone
};

// funzione che inizializza il grafo con n_persone
void inizializzaGrafo(Grafo& grafo, int n_persone) {
    if(n_persone > max_persone) {
        return;
    }
    grafo.n_persone = n_persone;
    for(int i = 0; i < grafo.n_persone; i++) {
        for(int j = 0; j < grafo.n_persone; j++) {
            grafo.meetings[i][j] = 0;
        }
    }
}

// funzione che stampa a video il grafo
void printGrafo(Grafo grafo) {
    for(int i = 0; i < grafo.n_persone; i++) {
        cout << "Persona " << i << " e' stata in meeting con: ";
        bool contatto = false;
        for(int j = 0; j < grafo.n_persone; j++) {
            if(grafo.meetings[i][j] > 0) {
                cout << "- Persona " << j << " per " << grafo.meetings[i][j] << (grafo.meetings[i][j] > 1 ? " ore; " : " ora; ");
                contatto = true;
            }
        }
        if(!contatto) {
            cout << "Nessuno";
        }
        cout << endl;
    }
}

// funzione che registra un meeting tra persona id_persona1 e persona id_persona2 (tale meeting e' stato di durata_contatto ore)
void registraMeeting(Grafo& grafo, int id_persona1, int id_persona2, Tempo durata_contatto) {
     // DA IMPLEMENTARE
}

// funzione che ritorna il numero totale di ore che una persona ha trascorso facendo meeting con altre persone
int numeroTotaleOreMeeting(Grafo grafo, int id_persona) {
    // DA IMPLEMENTARE
    return 0;
}

// funzione che ritorna lista di persone che non hanno avuto alcun meeting
Lista personeCheNonHannoAvutoMeeting(Grafo grafo) {
    // DA IMPLEMENTARE
    return lista_vuota;
}

// funzione che ritorna una lista contenente tutte le persone che hanno comunicato (direttamete e indirettamente) con id_persona (la lista ritornata non contiene id_persona) per almeno 3 ore
// questa lista rappresenta una possibile propagazione di informazioni a partire dalla persona id_persona
// la propagazione di informazione tra una persona e un'altra si considera avvenuta quando la sua durata è di almeno 3 ore
Lista possibiliLeakInformazioni(Grafo grafo, int id_persona) {
    // DA IMPLEMENTARE
    return lista_vuota;
}

/****************************************************************/
// MAIN con casi di test
/****************************************************************/
int main() {
    int n_persone = 5; // inizializziamo grafo con 5 persone
    Grafo grafo;
    inizializzaGrafo(grafo, n_persone);

    cout << "****** ESECUZIONE  ****** " << endl << endl;
	cout << "*** FUNZIONE 1 *** " << endl;
    registraMeeting(grafo, 0, 1, 2); // registriamo meeting tra Persona 0 e Persona 1 per 2 ore
    registraMeeting(grafo, 0, 2, 1); // registriamo meeting tra Persona 0 e Persona 2 per 1 ora
    registraMeeting(grafo, 1, 2, 3); // registriamo meeting tra Persona 1 e Persona 2 per 3 ore
    registraMeeting(grafo, 1, 3, 5); // registriamo meeting tra Persona 1 e Persona 3 per 5 ore
    cout << "meetings OSSERVATI:" << endl;
    printGrafo(grafo); // stampa il grafo a video
    cout << endl;
    cout << "La tua funzione e' corretta se sopra ha stampato (dopo meetings OSSERVATI):" << endl;
    cout << "Persona 0 e' stata in contatto con: - Persona 1 per 2 ore; - Persona 2 per 1 ora;" << endl;
    cout << "Persona 1 e' stata in contatto con: - Persona 0 per 2 ore; - Persona 2 per 3 ore; - Persona 3 per 5 ore;" << endl;
    cout << "Persona 2 e' stata in contatto con: - Persona 0 per 1 ora; - Persona 1 per 3 ore;" << endl;
    cout << "Persona 3 e' stata in contatto con: - Persona 1 per 5 ore;" << endl;
    cout << "Persona 4 e' stata in contatto con: Nessuno" << endl;

    cout << endl << "*** FUNZIONE 2 *** " << endl;
    cout << "TEST numero di ore totali di meeting per Persona 1: " << (numeroTotaleOreMeeting(grafo, 1) == 10 ? "PASSATO" : "FALLITO") << endl;

    cout << endl << "*** FUNZIONE 3 *** " << endl;
    Lista persone = personeCheNonHannoAvutoMeeting(grafo);
    cout << "Persone che non hanno avuto meetings: ";
    printLista(persone);
    cout << endl << "La tua funzione e' corretta se sopra ha stampato: " << endl;
    cout << "Persone che non hanno avuto meetings: [ Persona 4 ]" << endl;

    cout << endl << "*** FUNZIONE 4 *** " << endl;
    registraMeeting(grafo, 3, 4, 5); // registriamo contatto diretto tra Persona 3 e Persona 4 per 5 ore
    cout << "Possibili leak di informazioni (diretti e indiretti) da Persona 1: ";
    printLista(possibiliLeakInformazioni(grafo, 1));
    cout << endl;
    cout << "La tua funzione e' corretta se sopra ha stampato: (l'ordine degli elementi stampati non ha importanza)" << endl;
    cout << "Possibili leak di informazioni (diretti e indiretti) da Persona 1: [ Persona 2, Persona 3, Persona 4 ]" << endl;
}