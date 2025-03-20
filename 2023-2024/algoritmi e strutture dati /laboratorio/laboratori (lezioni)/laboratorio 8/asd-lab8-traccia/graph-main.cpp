////////////////////////////////////////////////////////////////////////
// COMPILAZIONE:
// g++  -std=c++11 -Wall list-array.cpp graph.cpp graph-main.cpp -o graph-main
////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <iostream>
#include <fstream> 
#include "graph.h"

using namespace std;

const string menu_text = R"(
a: inserisci la mappa (grafo) da tastiera
b: inserisci la mappa da file
c: visualizza la mappa
d: inserisci una città (vertice) nella mappa
e: inserisci una nuova strada (arco) nella mappa
f: stampa il numero di città presenti nella mappa
g: stampa il numero di strade nella mappa
h: stampa il numero di strade che portano a una città (il suo grado)
i: verifica se due città sono adiacenti (collegate da una strada)
j: stampa le città adiacenti a una data città
k: calcola un cammino tra due città
l: svuota la mappa
)";

const int n_scelte = 11;

const string prompt = "\ndigita p per stampare il menu, q per terminare\n>";

// variabile globale usata per decidere se stampare i prompt
bool quiet;

// Visualizza il menu con le scelte possibili e chiede
// all'utente di immetterne una. 
// Continua a ripresentare il menu finché l'utente non
// immette una scelta valida. Ritorna la scelta fatta ed esce se
// viene immesso 'q' o EOF.
int menu()
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

// leggi una stringa da uno stream
string read_string(istream &istr)
{
  string res;
  istr >> res;
  if (!istr) {
    istr.clear();
    throw runtime_error("fine del file quando è attesa una stringa");
  }
  return res;
}

graph::Weight read_weight(istream &istr)
{
  graph::Weight w;
  istr >> w;
  if (!istr) {
    istr.clear();
    throw runtime_error("non posso leggere una distanza");
  }
  return w;
}

// legge un grafo (si può usare da stdin o file)
void read_graph(graph::Graph &g, istream &istr)
{
  graph::clear(g);
  while (true) {
    graph::Label v1 = read_string(istr);
    if (v1 == "0")
      break;
    graph::Label v2 = read_string(istr);
    graph::Weight w = read_weight(istr);
    graph::addVertex(v1, g);
    graph::addVertex(v2, g);
    graph::addEdge(v1, v2, w, g);
  }
}

// stampa il prompt per chiedere un valore (ignorato se quiet è vero)
void ask(string prompt)
{
  if (quiet)
    return;
  prompt[0] = toupper(prompt[0]);
  cout << prompt << ": ";
}


int main(int argc, char *argv[]) {

  quiet = argc >= 2 && argv[1][0] == 'q';

  graph::Graph g = graph::createEmptyGraph();

  if (!quiet)
    cout << menu_text;

  // ciclo sulla scelta
  while (true) {
    try {
      ifstream ifs;
      unsigned int n;
      list::List l = list::createEmpty();
      graph::Label vertex1, vertex2;
      graph::Weight w;

      switch (menu())
        {
        case 0:  // leggi da tastiera
          ask("inserisci le strade nel formato 'origine destinazione distanza' (0 per terminare)");
          cout << endl;
          read_graph(g, cin);
          break;
    
        case 1:  // leggi da file
          ask("nome del file");
          ifs.open(read_string(cin).c_str());
          if (!ifs)
            throw runtime_error("non posso aprire il file");
          read_graph(g, ifs);
          break;
        
        case 2:  // stampa il grafo
          graph::printGraph(g);
          break;
        
        case 3:  // inserisci un nuovo vertice
          ask("nome");
          if (!graph::addVertex(read_string(cin), g))
            cout << "Città già presente, nodo non inserito" << endl;
          break;
        
        case 4:  // inserisci un nuovo arco
          ask("inserisci le due città e la distanza tra le due");
          vertex1 = read_string(cin);
          vertex2 = read_string(cin);
          w = read_weight(cin);
          if (!graph::addEdge(vertex1, vertex2, w, g))	
            cout << "Una delle città non era presente o la strada lo era già, strada non inserita" << endl;
          break;
        
        case 5:  // numero dei vertici
          cout << graph::numVertices(g) << endl;
          break;
        
        case 6:  // numero degli archi
          cout << graph::numEdges(g) << endl;
          break;
        
        case 7:  // grado
          ask("città");
          if (graph::nodeDegree(read_string(cin), n, g))
            cout << n << endl;
          else
            cout << "Città non presente nella mappa" << endl;
          break;

        case 8:  // adiacenza tra due vertici
          ask("inserisci le due città");
          if (graph::areAdjacent(read_string(cin), read_string(cin), g))
            cout << "Le città sono adiacenti" << endl;
          else
            cout << "Le città NON sono adiacenti" << endl;
          break;
        
        case 9:  // lista di adiacenza
          ask("città");
          l = graph::adjacentList(read_string(cin), g);
          if (list::isEmpty(l))
            cout << "La città non ha collegamenti o non è presente nella mappa" << endl;
          else {
            printList(l);
            cout<<endl;
            list::clear(l);
          }
          break;

        case 10:  // percorso tra due città
          ask("inserisci le due città");
          vertex1 = read_string(cin);
          vertex2 = read_string(cin);
          if(!graph::findPath(vertex1, vertex2, l, n, g)){
            cout << "Nessun percorso trovato" << endl;
          }else {
            cout << "Percorso di lunghezza " << n << ":" << endl;
            cout << vertex1 << "; ";
            printList(l);
            cout<<endl;
            list::clear(l);
          }
          break;

        case 11:  // svuota la mappa
          graph::clear(g);
          break;
        }  // switch
    }  // try
    catch (runtime_error &e) {
      cerr << "errore: " << e.what() << endl;
    }
  }  // while
}  // main
