// pre appello dicembre 2022

// esercizio 1

/*1.A (1 PUNTO+1 PUNTO) Sul piano cartesiano realizzare la struct CIRCLE (centro e raggio) e la
struct POINT necessaria per realizzare il centro. */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct circle {
    struct centro {
        double x;
        double y;
    };
    double raggio;
}

// 1.B (1.5 PUNTI) Realizzare una funzione che verifichi se due cerchi

// PARI hanno la stessa area

bool same_area (circle &cerchio1, circle &cerchio2) {
    const int PI = 3.14;
    double area_cerchio1 = PI * cerchio1.raggio * cerchio1.raggio;
    double area_cerchio2 = PI * cerchio2.raggio * cerchio2.raggio;

    if (area_cerchio1 == area_cerchio2) {
        return true;
    }
    return false;
    
}

// DISPARI hanno lo stesso perimetro

bool same_perimetro (circle& cerchio1, circle& cerchio2) {
    const int PI = 3.14;
    double perimetro_cerchio1 = 2.0 * PI * cerchio1.raggio;
    double perimetro_cerchio2 = 2.0 * PI * cerchio2.raggio;

    if (perimetro_cerchio1 == perimetro_cerchio2) {
        return true;
    }
    return false;
}

// 1.C (2.5 PUNTI)

// PARI Realizzare una funzione che verifichi se due cerchi si sovrappongono

bool is_sovrapposto (const circle& cerchio1, const circle& cerchio2) {
    double cateto1 = cerchio1.centro.x - cerchio2.centro.x;
    double cateto2 = cerchio1.centro.y - cerchio2.centro.y;
    double distanza = sqrt(pow(cateto1, 2) + pow(cateto2, 2));
    // double distanza = sqrt(pow(cerchio2.centro.x - cerchio1.centro.x, 2) + pow(cerchio2.centro.y - cerchio1.centro.y, 2)); 
    double sum_raggi = cerchio1.raggio + cerchi2.raggio;

    if (distanza < sum_raggi) {
        return true;
    }
    return false;
}

// DISPARI Realizzare una funzione che verifichi se, dati due cerchi, uno è contenuto nell’altro 

void is_contenuto (const circle& cerchio1, const circle& cerchio2) {
    double cateto1 = cerchio1.centro.x - cerchio2.centro.x;
    double cateto2 = cerchio1.centro.y - cerchio2.centro.y;
    double distanza = sqrt(pow(cateto1, 2) + pow(cateto2, 2));
    
    if (distanza + cerchio1.raggio <= cerchio2.raggio) {
        return true;
    } 
    return false;
}

// ESERCIZIO 2 (2 PUNTI)

// PARI Realizzare una funzione che preso un n>0 restituisca un vector contenente (esattamente) 
// i primi n multipli di n

vector<int> create_vector_multipli (int n) {
    vector<int> v(n);
    int num = 0;
    for (int i = 1; i < n; ++i) {
            num += n;
            v.at(i) = num;
        }
    return v;
}
    

// DISPARI Realizzare una funzione che preso un n>0 restituisca un vector contenente (esattamente) 
// tutti i numeri maggiori di zero divisori di n

vector<int> create_vector_divisori (int n) {
    vector<int> v(0);
    int check = n;
    int res = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            res++;
            v.resize (res);
            v.at(res - 1) = i;
        }
    }
    v.resize(res + i);
    v.at(res) = n;
    return (v);
}

// ESERCIZIO 3 Descrivere una lista semplice di string

// 3.A (2.5 PUNTI) Realizzare una funzione ricorsiva che restituisca

// PARI: concatenazione (operatore +) degli elementi di una lista
string concatenazione_ricorsiva (list &l) {
    return string(cell -> data) + concatenazione_ricorsiva(cell -> next);
}
// DISPARI: lunghezza della lista
string lunghezza_lista (list &l) {
    return 1 + lunghezza_lista(cur -> next);
}

// 3.B (2.5 PUNTI) Realizzare una funzione che restituisca true se

// PARI almeno un elemento della lista è la string “ecco”
bool elem_ecco(list &l, string s) {
    if (l == nullptr){
        return false;
    }
    if (cur -> data == "ecco") {
        return true;
    }
    return elem_ecco (cur -> next);
}
// DISPARI tutti gli elementi sono ”ecco”, false altrimenti
bool tutti_ecco(list &l, string s) {
    return (cur->dato == "ecco") && tuttiEcco(cur->next);
}
