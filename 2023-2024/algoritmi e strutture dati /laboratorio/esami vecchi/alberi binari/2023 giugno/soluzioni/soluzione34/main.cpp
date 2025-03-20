#include <fstream>
#include <iostream>

#include "bag.h"

using namespace std;

typedef int Elem;


void error(string msg)
{
    cerr << "errore: " << msg << endl;
    exit(1);
}

const string menu_text = R"(
a: stampa in ordine crescente
b: verifica se la bag contiene un valore minore a v (1 parametro: v)
c: conta il numero di elementi uguali a v (1 parametro: v)
)";

const int n_scelte = 3;

const string prompt = "\ndigita p per stampare il menu, q per terminare\n> ";

// Visualizza il menu con le scelte possibili e chiede
// all'utente di immetterne una. 
// Continua a ripresentare il menu finché l'utente non
// immette una scelta valida. Ritorna la scelta fatta ed esce se
// viene immesso 'q' o EOF.
int menu(bool quiet)
{
  while (true) {
    if (!quiet)
      cout << prompt;
    char ch;
    if (!(cin >> ch) || ch == 'q')
      exit(0);
    if (ch == 'p') {
      cout << menu_text;
      continue;
    }
    int res = ch - 'a';
    if (res < 0 || res > n_scelte) {
      cerr << "scelta non valida" << endl;
      continue;
    }
    return res;
  }
}

int main(int argc, char *argv[])
{
    bool quiet = argc >= 2 && argv[1][0] == 'q';

    string fileName;
    if (!quiet)
        cout << "File di input: ";
    cin >> fileName;
    if (!cin)
        error("non posso leggere il nome del file");
    ifstream f(fileName);
    if (!f)
        error("non posso aprire " + fileName);
    
    bag::Bag b = bag::createEmpty();

    bag::Elem v;
    while (f >> v)
        bag::insert(b, v);
    
    if (!quiet)
        cout << menu_text;

    while(true) {
        int choice = menu(quiet);

        if (choice == 1 || choice == 2) {  // lettura del parametro v
            cin >> v;
            if (!cin) {
                cerr << "non posso leggere il parametro v" << endl;
                continue;
            }
        }

        switch(choice) {
            case 0:  // stampa in ordine
                bag::printInOrder(b);
                cout << endl;
                break;
            case 1:  // verifica se la bag ha un valore minore di v
                cout << (bag::hasLowerValue(b, v) ? "vero" : "falso") << endl;
                break;
            case 2: // numero di elementi uguali a v
                cout << bag::countEqual(b, v) << endl;
                break;
        }
    }
}