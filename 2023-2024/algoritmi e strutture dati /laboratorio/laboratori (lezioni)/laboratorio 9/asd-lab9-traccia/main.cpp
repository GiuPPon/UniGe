/////////////////////////////////////////////////////////
//
//  Compilare con:   g++ -Wall -std=c++11 *cpp
//
/////////////////////////////////////////////////////////

#include <math.h>  // funzione round()

#include "priority_queue.h"

using namespace tragitto;
using namespace priorityQueue;


int main() {

  int n;
  string inputString, nomeFile;
  cout << "Inserire il nome del file da cui leggere i dati\n";  
  cin >> nomeFile;
  ifstream ifs(nomeFile.c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) 
    {
    cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; 
    return 1;
    }  
  
  getline(ifs, inputString);
  stringstream s(inputString);
  if (!(s >> n)) 
    {
    cout << "\nErrore lettura numero veicoli, controllare formato del file in input\n"; 
    return 1;
    } 

  InfoVeicolo* veicolo = new InfoVeicolo[n];
  for(int i=0; i<n; ++i) {
    getline(ifs, inputString); 
    stringstream s(inputString); 

    // preleva la targa e la citta' di partenza dallo stream (prime 2 stringhe)
    s >> veicolo[i].plate; 
    s >> veicolo[i].location; 

    // ciclo per prelevare il tragitto, una tappa dopo l'altra.
    // l'ultimo numero della serie non fa parte del tragitto,
    // bensi' esprime la velocita' media del veicolo.

    Tappa t;

    while (true) 
       {
       // ciclo while un po' criptico ma corretto: scandisce tutta la linea
       // di input leggendo alternativamente una distanza e una citta'
       // e interrompendosi se qualcosa va storto (es. distanza non numerica)
       if (!(s >> t.distanza)) break;
       if (!(s >> t.citta)) break;
       tragitto::insert(veicolo[i].path, t); 
       }
    veicolo[i].speed = t.distanza; // l'ultimo numero preso in input e associato al campo distanza e' in realta' la velocita' media   
  
  }

  cout << "\nRIEPILOGO DATI INSERITI:\n\n";
  for(int i=0; i<n; i++) {
    cout << veicolo[i].plate << "::";
    cout << veicolo[i].location << " ";
    printTragitto(veicolo[i].path); 
    cout << "::" << veicolo[i].speed << endl;
  }

  cout << "\nINIZIO SIMULAZIONE:\n";

  Elem evento;
  PriorityQueue pq = createEmptyPQ(n);
  // inizializzazione della coda con priorità con gli eventi del tempo t=0
  for(int i=0; i<n; i++) {
    evento.veicolo = &veicolo[i];
    evento.timeStamp = 0;
    priorityQueue::insert(pq, evento);
  }

  // ciclo di simulazione

  while (!priorityQueue::isEmpty(pq)) {

    //prossimo evento

    findMin(pq, evento);
    deleteMin(pq);

    // visualizza evento (tappa raggiunta da un veicolo)
    // il time stamp viene arrotondato a intero per meglio visualizzare

    cout << evento.veicolo->plate << " " << round(evento.timeStamp) << " " << evento.veicolo->location << endl;

    // se e' l'ultima tappa, non devo generare un nuovo evento

    if (tragitto::isEmpty(evento.veicolo->path)) continue;

    // altrimenti calcolo la prossima tappa da raggiungere
    // (prossimo evento di quel veicolo)

    // prendo la prossima citta' dal "path", che si accorcia di un elemento.

    Tappa nextStep;
    extract(evento.veicolo->path,nextStep);
    evento.veicolo->location = nextStep.citta;

    // calcolo il tempo previsto di arrivo nella prossima citta'
    // in minuti (quindi moltiplico le ore per 60)

    evento.timeStamp += 60.0 * (nextStep.distanza/evento.veicolo->speed);

    // nuovo evento e' pronto, inserisco nella coda con priorita'

    priorityQueue::insert(pq,evento);

    // la simulazione prosegue

  }

  return 0;

}
