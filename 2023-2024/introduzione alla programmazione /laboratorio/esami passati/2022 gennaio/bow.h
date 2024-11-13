#include <string>
#include <vector>

struct Entry {
  std::string word;
  int num;
};

typedef std::vector<Entry> BagOfWords;

// Aggiunge
void add(BagOfWords &, std::string);

// Cancella
void del(BagOfWords &, const std::string);

// Restituisce conteggio
int count(const BagOfWords &, std::string);

// Stampa
void print(const BagOfWords &);
