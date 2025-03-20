/****************************************************/
/*          ESAME DI LABORATORIO DI ASD             */
/****************************************************/

// Descrizione:
// L'esame consiste nella creazione e gestione di una versione modificata di battaglia navale, che invece di essere su 2 dimensioni, è su 3 dimensioni.
// Infatti, invece di essere una battaglia navale, è una battaglia aerea. Invece delle usuali coordinate X e Y, aggiungiamo la Z per rappresentare l'altitudine
// degli aerei in volo.
// Per il resto, le regole del gioco sono le stesse di battaglia navale (solo su 3 dimensioni).
// La mappa di gioco è rappresentata come un cubo (una matrice a 3 dimensioni). La prima coordinata della matrice rappresenta la coordinata X, la seconda coordinata
// rappresenta la Y, e la terza coordinata rappresenta la Z.
// Esempio: mappa[0][1][2] rappresenta la cella di coordinata 0 sull'asse delle X, 1 sull'asse delle Y e 2 sull'asse delle Z.


#include <iostream>

using namespace std;


/****************************************************************/
// Definizione Battaglia Aerea come Matrice
/****************************************************************/

const int larghezza = 5; // dimensione asse X
const int lunghezza = 5; // dimensione asse Y
const int altezza = 3; // dimensione asse Z

const int cellaVuota = 0; // 0 rappresenta la cella vuota (i.e., nessun pezzo di aereo e' presente)
const int cellaPiena = 1; // 1 rappresenta la cella con pezzo d'aereo (non colpito, quindi ancora integro)
const int cellaColpita = 2; // 2 rappresenta la cella con pezzo d'aereo abbattuto (colpito, quindi danneggiato)

// la struct che rappresenta le coordinate sulla mappa (queste coordinate sono utilizzate per identificare le celle nella mappa)
struct Coordinate {
    int x;
    int y;
    int z;
};

// la struct che rappresenta il tavoliere della battaglia aerea (contiene la matrice mappa con tutte le celle, dove ogni cella puo' essere vuota 0, con pezzo di aereo 1, o con pezzo di aereo abbattuto 2)
struct BattagliaAerea {
    int mappa[larghezza][lunghezza][altezza]; // FR: forse metterei prima lunghezza e poi larghezza
};

/****************************************************************/
// Definizione Lista semplice ausiliaria
/****************************************************************/

struct Cella {
    Coordinate pos;
    Cella* prossimo;
};

typedef Cella* Lista; // definiamo lista come un puntatore a cella

const Lista listaVuota = nullptr; // la lista vuota corrisponde a nullptr
const Coordinate elementoVuoto = {-1, -1, -1}; // viene ritornato quando la lista è vuota e si prova a rimuovere un elemento da essa

/****************************************************************/
// Implementazione Lista semplice ausiliaria
/****************************************************************/

// funzione che crea la lista vuota
void creaLista(Lista& lista) {
    lista = listaVuota;
}

// funzione che aggiunge elemento alla lista (aggiunge in coda)
void aggiungiElemento(Lista& lista, Coordinate pos) {
    if(lista == listaVuota) {
        lista = new Cella();
        lista->pos = pos;
        lista->prossimo = listaVuota;
    }
    else {
        Lista aux = lista;
        while(aux->prossimo != listaVuota) {
            aux = aux->prossimo;
        }
        aux->prossimo = new Cella();
        aux->prossimo->pos = pos;
        aux->prossimo->prossimo = listaVuota;
    }
}

// funzione che rimuove elemento dalla lista (rimuove in testa)
//FR: direi anceh che ritorna l'elemento rimosso
Coordinate rimuoviElemento(Lista& lista) {
    if(lista == listaVuota) {
        return elementoVuoto;
    }
    Coordinate elemento = lista->pos;
    Lista aux = lista;
    lista = lista->prossimo;
    delete aux;
    return elemento;
}

// funzione che stampa a video la lista
void printLista(Lista lista) {
    cout << "[";
    while(lista != listaVuota) {
        cout << " Parte (" << lista->pos.x << ", " << lista->pos.y << ", " << lista->pos.z << ")";
        lista = lista->prossimo;
        if(lista != listaVuota) cout << ",";
    }
    cout << " ]" << endl;
}

/****************************************************************/
// Implementazione Battaglia Aerea come Matrice
/****************************************************************/

// Inizializza la plancia di gioco (con tutte le celle vuote)
void inizializzaBattagliaAerea(BattagliaAerea& gioco) {
    for(int x = 0; x < larghezza; x++) {
        for(int y = 0; y < lunghezza; y++) {
            for(int z = 0; z < altezza; z++) {
                gioco.mappa[x][y][z] = cellaVuota;
            }
        }
    }
}

// Crea un aereo (un pezzo alla volta) nelle coordinate indicate. La funzione ritorna True, se tale inserimento avviene con successo (la cella era vuota), False, altrimenti.
// Gli aerei si possono allungare su un'unica dimensione (X, Y, o Z). Intuitivamente, gli aerei sono delle rette parallele all'asse X, Y, o Z.
// Non consideriamo aerei che si allungano su più assi contemporaneamente (non sono ne rettangoli, ne cubi).
bool creaAereo(BattagliaAerea& gioco, Coordinate pos) {
    for(int x = 0; x < larghezza; x++) {
        for(int y = 0; y < lunghezza; y++) {
            for(int z = 0; z < altezza; z++) {
                if (x == pos.x && y == pos.y && z == pos.z) {
                    return false;
                }
            }
        }
    }
    
}

// Colpisci ("affonda") un pezzo di aereo nelle coordinate indicate. La funzione ritorna True, se tale attacco avviene con successo, False, altrimenti.
bool colpisciPezzoDiAereo(BattagliaAerea& gioco, Coordinate pos) {
    /* DA IMPLEMENTARE */
    return false;
}

// Funzione che ritorna una lista contenente le parti di un aereo. Le coordinate pos passate alla funzione possono indicare una qualsiasi componente dell'aereo.
// La lista ritornata contiene le coordinate delle parti dell'aereo (usate struttura dati lista ausiliaria).
// Nota: Con parti dell'aereo si intende le parti contigue alle coordinate indicate.
// Esempio: 
// Assumiamo che precedentemente sia stata chiamata la funzione creaAereo alle seguenti coordinate: (3,3,0) (3,3,1) (3,3,2)
// Cioe', ci troviamo in una situazione dove un aereo, composto da 3 pezzi, e' presente nella mappa.
// Se ora chiamiamo la funzione partiAereoIn, passando coordinate (3,3,0), dobbiamo ottenere come risultato la lista contenente coordinate: (3,3,0) (3,3,1) (3,3,2)
// Nota: Quale pezzo dell'aereo viene passato in input (o meglio sue coordinate) non e' rilevante, infatti la funzione partiAereoIn deve ritornare la stessa lista 
// anche nel caso venisse passato in input coordinate (3,3,1) o (3,3,2). Questa funzione e' utilizzata per recuperare le parti di un aereo, partendo da una qualsiasi sua parte.
Lista partiAereoIn(BattagliaAerea& gioco, Coordinate pos) {
    /* DA IMPLEMENTARE */
    return listaVuota;
}

// Funzione che ritorna True, se l'aereo alle coordinate indicate è abbattuto (ovvero, tutte le sue parti sono state colpite), False, altrimenti (quindi ancora in volo, 
// ovvero, almeno una sua parte non e' stata colpita).
// Visto che un aereo puo' essere composto da piu' pezzi, le coordinate passate in pos sono di un qualsiasi pezzo dell'aereo; come per la funzione partiAereoIn, questa funzione 
// deve avere stesso comportamento, per qualsiasi parte dell'aereo passata.
// Suggerimento: Utilizzare funzione partiAereoIn per recuperare le coordinate delle parti dell'aereo.
bool aereoAbbattutoIn(BattagliaAerea &gioco, Coordinate pos) {
    /* DA IMPLEMENTARE */
    return false;
}

/****************************************************************/
// MAIN con casi di test
/****************************************************************/
int main() {
    BattagliaAerea gioco;
    inizializzaBattagliaAerea(gioco);

    cout << "****** ESECUZIONE  ****** " << endl << endl;


    cout << "*** FUNZIONE 1 *** " << endl;
    // Aggiungi AEREO 1
    cout << "Aggiungi AEREO 1" << endl;
    cout << "Aggiungi pezzo in (3,3,0): " << (creaAereo(gioco, {3,3,0}) ? "Si" : "No") << endl;
    cout << "Aggiungi pezzo in (3,3,1): " << (creaAereo(gioco, {3,3,1}) ? "Si" : "No") << endl;
    cout << "Aggiungi pezzo in (3,3,2): " << (creaAereo(gioco, {3,3,2}) ? "Si" : "No") << endl;
    // Aggiungi AEREO 2
    cout << "Aggiungi AEREO 2" << endl;
    cout << "Aggiungi pezzo in (0,0,0): " << (creaAereo(gioco, {0,0,0}) ? "Si" : "No") << endl;
    cout << "Aggiungi pezzo in (0,1,0): " << (creaAereo(gioco, {0,1,0}) ? "Si" : "No") << endl;
    // Aggiungi AEREO 3
    cout << "Aggiungi AEREO 3" << endl;
    cout << "Aggiungi pezzo in (2,1,2): " << (creaAereo(gioco, {2,1,2}) ? "Si" : "No") << endl;
    cout << "Aggiungi pezzo in (3,1,2): " << (creaAereo(gioco, {3,1,2}) ? "Si" : "No") << endl;
    cout << "Aggiungi pezzo in (4,1,2): " << (creaAereo(gioco, {4,1,2}) ? "Si" : "No") << endl;
    // Aggiungi pezzi sbagliati
    cout << "Aggiungi pezzi sbagliati" << endl;
    // No, perché la cella non è vuota
    cout << "Aggiungi pezzo in (3,3,0): " << (creaAereo(gioco, {3,3,0}) ? "Si" : "No") << endl;
    // No, perché esiste una cella diagonale piena (la cella (3,3,1) in questo caso)
    //FR: lo spiegherei meglio...
    cout << "Aggiungi pezzo in (3,2,0): " << (creaAereo(gioco, {3,2,0}) ? "Si" : "No") << endl;


    cout << endl << "La tua funzione e' corretta se sopra ha stampato" << endl;
    cout << "Aggiungi AEREO 1\nAggiungi pezzo in (3,3,0): Si\nAggiungi pezzo in (3,3,1): Si\nAggiungi pezzo in (3,3,2): Si\nAggiungi AEREO 2\nAggiungi pezzo in (0,0,0): Si\nAggiungi pezzo in (0,1,0): Si\nAggiungi AEREO 3\nAggiungi pezzo in (2,1,2): Si\nAggiungi pezzo in (3,1,2): Si\nAggiungi pezzo in (4,1,2): Si\nAggiungi pezzi sbagliati\nAggiungi pezzo in (3,3,0): No\nAggiungi pezzo in (3,2,0): No" << endl;

	cout << endl << "*** FUNZIONE 2 *** " << endl;
    cout << "Lista delle parti di AEREO 1: " << endl;
    Lista parti = partiAereoIn(gioco, {3,3,0});
    printLista(parti);
    cout << "Lista delle parti di AEREO 2: " << endl;
    parti = partiAereoIn(gioco, {0,0,0});
    printLista(parti);
    cout << "Lista delle parti di AEREO 3: " << endl;
    parti = partiAereoIn(gioco, {2,1,2});
    printLista(parti);
    cout << "Lista delle parti in cella vuota: " << endl;
    parti = partiAereoIn(gioco, {3,3,3});
    printLista(parti);

    cout << endl << "La tua funzione e' corretta se sopra ha stampato (nota che l'ordine delle parti all'interno di ogni lista non è rilevante)" << endl;
    cout << "Lista delle parti di AEREO 1:" << endl;
    cout << "[ Parte (3, 3, 0), Parte (3, 3, 1), Parte (3, 3, 2) ]" << endl;
    cout << "Lista delle parti di AEREO 2:" << endl;
    cout << "[ Parte (0, 0, 0), Parte (0, 1, 0) ]" << endl;
    cout << "Lista delle parti di AEREO 3:" << endl;
    cout << "[ Parte (2, 1, 2), Parte (3, 1, 2), Parte (4, 1, 2) ]" << endl;
    cout << "Lista delle parti in cella vuota:" << endl;
    cout << "[ ]" << endl;

    cout << endl << "*** FUNZIONE 3 *** " << endl;
    cout << "Prima" << endl;
    cout << "AEREO 1 è: " << (aereoAbbattutoIn(gioco, {3,3,0}) ? "Abbattuto" : "In Volo") << endl;
    cout << "AEREO 2 è: " << (aereoAbbattutoIn(gioco, {0,0,0}) ? "Abbattuto" : "In Volo") << endl;
    cout << "AEREO 3 è: " << (aereoAbbattutoIn(gioco, {2,1,2}) ? "Abbattuto" : "In Volo") << endl;

    colpisciPezzoDiAereo(gioco, {3,3,0});
    colpisciPezzoDiAereo(gioco, {3,3,1});
    colpisciPezzoDiAereo(gioco, {3,3,2});
    colpisciPezzoDiAereo(gioco, {0,0,0});
    colpisciPezzoDiAereo(gioco, {3,3,3});

    cout << "Dopo" << endl;
    cout << "AEREO 1 è: " << (aereoAbbattutoIn(gioco, {3,3,0}) ? "Abbattuto" : "In Volo") << endl;
    cout << "AEREO 2 è: " << (aereoAbbattutoIn(gioco, {0,0,0}) ? "Abbattuto" : "In Volo") << endl;
    cout << "AEREO 3 è: " << (aereoAbbattutoIn(gioco, {2,1,2}) ? "Abbattuto" : "In Volo") << endl;

    cout << endl << "La tua funzione e' corretta se sopra ha stampato" << endl;
    cout << "Prima\nAEREO 1 è: In Volo\nAEREO 2 è: In Volo\nAEREO 3 è: In Volo\nDopo\nAEREO 1 è: Abbattuto\nAEREO 2 è: In Volo\nAEREO 3 è: In Volo" << endl;

}