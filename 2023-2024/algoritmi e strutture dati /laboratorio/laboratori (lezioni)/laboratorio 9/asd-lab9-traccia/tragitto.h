#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

namespace tragitto {

struct Tappa {
  float distanza;  // distanza di questa tappa dalla precedente in km
  string citta;    // luogo di questa tappa
};

struct TragittoElem {
  Tappa tappa;
  TragittoElem* next;
};

// Il tragitto di un veicolo e' una lista con le varie tappe in ordine, 
// cosi' come spiegato nel testo del laboratorio
typedef TragittoElem* Tragitto;

const Tragitto tragittoVuoto = NULL;

// verifica se un Tragitto e vuoto
bool isEmpty(Tragitto);

// inserisce una Tappa in un Tragitto
void insert(Tragitto&, Tappa);

// ritorna FALSE se il Tragitto e vuoto
// altrimenti rimuove la prima Tappa del Tragitto 
//    e la assegna al secondo parametro e ritorna TRUE
bool extract(Tragitto&, Tappa&);
}

// stampa un Tragitto (formato: N volte [distanza citta'])
void printTragitto(tragitto::Tragitto);