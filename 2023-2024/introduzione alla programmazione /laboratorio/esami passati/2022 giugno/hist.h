#include <string>
#include <vector>

struct Bin {
  int value;
  int num;
};

typedef std::vector<Bin> Hist;

// Aggiunge
void add(Hist &, int);

// Ordina
void sort(Hist &);

// Restituisce conteggio
int count(const Hist &, int);

// Stampa
void print(const Hist &);
