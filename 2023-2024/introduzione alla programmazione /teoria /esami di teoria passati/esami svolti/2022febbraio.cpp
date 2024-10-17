#include <iostream>
#include <string>
using namespace std;

// ESERCIZIO 1 (3 PUNTI)

/* Realizzare una funzione che prenda in input un
numero intero e restituisca il numero di cifre che
lo compongono, ignorando il segno */

int contaCifre(unsigned int num) {
    if (num == 0) {
        return 1; 
    }
    unsigned int count = 0;
    while (num > 0) {
        num /= 10;
        count ++;
    }
    return count;
}

//ESERCIZIO 2

/*Realizzare una funzione ricorsiva
int CountOccurrences(int A[], int size, int val);
che operi su array statici di interi e restituisca il numero di elementi di A uguali a val.
Il prototipo non può essere modificato, ma si possono usare funzioni ausiliarie.*/

int CountOccurrences(int A[], int size, int val) {
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (A[i] == val) {
            count++;
        }
    }
    
    return count;
}

// ESERCIZIO 3: Consideriamo il tipo di dato “insieme di turisti”

/* 3.A (1 PUNTO) Realizzare le strutture che descrivano:
- turista (codice fiscale, cognome, nome, nazionalità)
- insieme_di_turisti, realizzato tramite liste semplici */

struct turista {
    string codFiscale;
    string cognome;
    string nome;
    string nazionalità;
};

struct insieme_di_turisti {
    turista turista;
    cell *next;
};

/* 3.B (1 PUNTO) Realizzare la funzione booleana
StessoTurista, che ritorna true se due variabili di tipo
turista sono uguali */

bool StessoTurista(turista &turista1, turista &turista2) {
    if ((turista1.codFiscale == turista2. codFiscale) && (turista1.cognome == turista2.cognome) && (turista1.nome == turista2.nome) && (turista1.nazionalità == turista2.nazionalità)) {
        return true;
    }
    return false;
} 

/* 3.C (2 PUNTI) Produrre i prototipi (o interfacce) delle
funzioni stando molto attenti ai parametri formali
- InserisciTurista
- CancellaTurista
- InsiemeVuoto (funzione booleana)
- StampaInsiemeTuristi
- UnioneTraInsiemi */

void InserisciTurista(insieme_di_turisti &turisti, turista &turista);

void CancellaTurista(insieme_di_turisti &turisti);

bool InsiemeVuoto(insieme_di_turisti &turisti);

string StampaInsiemeTuristi(insieme_di_turisti &turisti, turista &turista);

string UnioneTraInsiemi(insieme_di_turisti &insieme1, insieme_di_turisti &insieme2);

// 3.D (3 PUNTI) Implementare la funzione UnioneTraInsiemi

string UnioneTraInsiemi(insieme_di_turisti &insieme1, insieme_di_turisti &insieme2) {
    
}


