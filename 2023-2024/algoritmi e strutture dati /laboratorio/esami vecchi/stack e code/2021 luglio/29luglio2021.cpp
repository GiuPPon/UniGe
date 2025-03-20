/******************************************************/
/* PROVA DI ESAME DI LABORATORIO DI ASD (DUE DOMANDE) */
/******************************************************/

// Descrizione:
// In questa prova di esame di laboratorio consideriamo un SW che, utilizzando una coda
// FIFO (implementata con array così come visto a lezione), simuli la gestione 
// di una playlist. La playlist contiene delle canzoni (Song) che sono 'struct' composte da: nome dell'autore (string), 
// nome della canzone (string) e durata della canzone in secondi (int).

// scrivere sotto Nome, Cognome e Matricola:
// NOME:
// COGNOME:
// MATRICOLA:
    
/**************************************************************/
/* DESCRIZIONE FUNZIONI DA IMPLEMENTARE
/**************************************************************/

/*
   Sviluppare le seguenti funzioni C/C++:
      
   1) printPlaylist()
      Stampa tutte le canzoni sullo standard output. Alla fine della stampa la coda deve tornare allo stato 
      iniziale ovvero contenere tutte le canzoni che vi erano inserite prima della stampa (consiglio: utilizzare una 
      nuova coda accessoria/ausiliaria)
      
   2) insertSong()
      Inserisce una nuova canzone, ma solo se non e' gia' presente nella playlist. Se l'inserimento va a buon 
      fine la funzione ritorna true, altrimenti false (vincolo: non e' possibile in questo caso usare una coda 
      accessoria/ausiliaria, la funzione si puo' implementare usando un'unica coda)
   
      Anche se si riesce 'a forzare' l'information hiding, essendo il file unico, cercare ugualmente di applicare i principi
      di buona programmazione e quindi nelle funzioni non comprese nel tipo di dato queue (cioe' playSong, printPlaylist e insertSong)
      utilizzare solamente le funzioni offerte dal tipo di dato e non utilizzare gli array sottostanti.
*/
    
#include <iostream>
#include <string>

using namespace std;

// Implementa QUEUE con strutture indicizzate e tipo base Elem dotato di ordinamento
namespace queue {

    const int BLOCKDIM = 1000;

    struct Song {
        string authorName;
        string songName;
        int duration;
    };

    const Song EMPTYSONG = { "VOID", "VOID", -1000000 };
    typedef Song Elem;      // tipo base: un elem e' una song 

    typedef struct {
        Elem* queue;
        int size;
        int maxsize;
    } Queue;

    Queue createEmpty();         /* restituisce la coda vuota */
    bool isEmpty(const Queue&);  /* restituisce true se la coda e' vuota, false altrimenti */
    void enqueue(Elem, Queue&);  /* inserisce l'elemento 'da una parte' della coda */
    Elem dequeue(Queue&);        /* cancella l'elemento (se esiste) 'dall'altra parte della coda' e lo restituisce; se la coda e' vuota la condizione e' di errore */
    Elem firstElem(Queue&);      /* restituisce l'elemento in prima posizione (se esiste) senza cancellarlo; se la coda e' vuota la condizione e' di errore */
}

using namespace queue;
using namespace std;

/****************************************************************/
/* 			FUNZIONI SULLE CODE 			                    */
/****************************************************************/

// Funzione ausiliaria (non fa parte dell'interfaccia del tipo di dato): aggiunge e nella posizione pos
void add(int pos, Elem e, Queue& l) {
   if (pos < 0 || pos > l.size) {cout << "\nPosizione fuori range, operazione ignorata\n"; return;}
   // l'array e' pieno, per poter inserire un nuovo elemento devo ridimensionare l'array espandendolo
   if (l.size == l.maxsize) {
      cout << "\nMessaggio di sistema: Espansione dell'array\n";
      l.size++;
      l.maxsize += BLOCKDIM;
      Elem* auxArray = new Elem[l.maxsize];
      for (int i=0; i<pos; ++i)
          auxArray[i] = l.queue[i];
      auxArray[pos] = e;
      for (int i=pos+1; i<l.size; ++i)
          auxArray[i] = l.queue[i-1];
      delete[] l.queue;
      l.queue = auxArray; 
      return;
    }

     // se la funzione non ha incontrato un return, vuole dire che pos e' nel range corretto e l'array non e' pieno
     l.size++;
     for (int i=l.size-1; i>pos; --i)
           l.queue[i] = l.queue[i-1];
     l.queue[pos] = e;
     return;
}

// Funzione ausiliaria (non fa parte dell'interfaccia del tipo di dato): elimina e nella posizione pos
Elem remove(int pos, Queue& l) {
   if (pos < 0 || pos >= l.size) {
      cout << "\nPosizione fuori range, operazione ignorata" << "\n"; 
      return EMPTYSONG;
     }
  
   // se rimuovendo l'elemento si liberano BLOCKDIM celle, allora ridimensioniamo l'array
   if (l.maxsize-l.size+1==BLOCKDIM && l.maxsize>BLOCKDIM) {
      cout << "\nMessaggio di sistema: Contrazione dell'array\n";
      l.size--;
      l.maxsize -= BLOCKDIM;
      Elem* auxArray = new Elem[l.maxsize];
      for (int i=0; i<pos; ++i)
          auxArray[i] = l.queue[i];
      for (int i=pos; i<l.size; ++i)
          auxArray[i] = l.queue[i+1];
      Elem tmp=l.queue[pos];
      delete[] l.queue;
      l.queue = auxArray; 
      return tmp;
   }

     // se la funzione non ha incontrato un return, vuole dire che pos e' nel range corretto e la lista non puo' essere ridotta di dimensione
     Elem tmp=l.queue[pos];
     for (int i=pos+1; i<l.size; ++i)
           l.queue[i-1]=l.queue[i];
     l.size--;
     return tmp;
}

/* restituisce la coda vuota */
Queue queue::createEmpty(){
    Queue q;
    q.size = 0;
    q.maxsize = BLOCKDIM;
    Elem* aux = new Elem[BLOCKDIM];
    q.queue = aux;
    return q;
}

/* restituisce true se la coda e' vuota, false altrimenti */
bool queue::isEmpty(const Queue& l) {
   return (l.size == 0);
}

/* inserisce l'elemento 'da una parte' della coda */
void queue::enqueue(Elem e, Queue& l) {
   add(l.size, e, l);
}

/* cancella l'elemento (se esiste) 'dall'altra parte della coda' e lo restituisce; se la coda e' vuota la condizione e' di errore */
Elem queue::dequeue(Queue& l) {
   return remove(0, l);
}

/* restituisce l'elemento in prima posizione (se esiste) senza cancellarlo; se la coda e' vuota la condizione e' di errore. */
Elem queue::firstElem(Queue& l) {
   if (isEmpty(l)) return EMPTYSONG;   
   else return l.queue[0];
}

/****************************************************************/
/* 			FUNZIONI DELLA PLAYLIST   			                */
/****************************************************************/

// Stampa tutte le canzoni sullo standard output.
// Alla fine della stampa la coda deve tornare allo stato iniziale (si utilizzi una nuova coda accessoria/ausiliaria)
void printPlaylist(Queue& playlist) {
    Queue temp = playlist;
    
    for (int i = 0; i < temp.size; ++i) {
        cout << temp.queue -> songName;
        if (i < temp.size - 1) {
            cout << " , ";
        }
    }
    cout << endl;
}

// Inserisce una nuova canzone s, ma solo se non e' gia' presente nella playlist.
// Se l'inserimento va a buon fine ritorna true, altrimenti false (non e' possibile in questo caso usare una coda accessoria/ausiliaria)
bool insertSong(Song s, Queue& playlist) {
    
    for (int i = 0; i < playlist.size; ++i) {
        if (playlist.queue ->songName[i] == s.songName) {
            return false;
        }
    }
    add(playlist.size, s, playlist);
    return true;
}


/****************************************************************/
/* 			MAIN  			                                    */
/****************************************************************/
int main() {
    // creiamo una playlist con due canzoni
    Queue q = createEmpty();
    Song s2 = {"Fedez", "Bella storia", 180};
    Song s3 = {"Jake la Furia", "Bandita", 220};
    enqueue(s2, q); enqueue(s3, q);
  
    cout << "*** FUNZIONE printPlaylist() *** " << endl;
    cout << "il test e' PASSATO se tra i separatori viene stampato:" << endl;
    cout << "Fedez" << endl;
    cout << "Bella storia" << endl;
    cout << "180" << endl;
    cout << "Jake la Furia" << endl;
    cout << "Bandita" << endl;
    cout << "220" << endl;
    cout << "---------------------------------------" << endl;
    printPlaylist(q);
    cout << "---------------------------------------" << endl;
    cout << " e se viene stampato dopo i due punti 0: ";
    cout << isEmpty(q) << endl;
    cout << endl;
    
    cout << "*** FUNZIONE insertSong() *** " << endl;
    cout << "il test e' PASSATO se tra i separatori viene stampato per due volte lo stesso risultato come riportato sotto:" << endl;
    cout << "Fedez" << endl;
    cout << "Bella storia" << endl;
    cout << "180" << endl;
    cout << "Jake la Furia" << endl;
    cout << "Bandita" << endl;
    cout << "220" << endl;
    cout << "Eros Ramazzotti" << endl;
    cout << "Adesso tu" << endl;
    cout << "100" << endl;
    cout << "---------------------------------------" << endl;
    Song s4 = {"Eros Ramazzotti", "Adesso tu", 100};
    insertSong(s4, q);
    printPlaylist(q);
    cout << "---------------------------------------" << endl;
    insertSong(s4, q);
    printPlaylist(q);
    cout << "---------------------------------------" << endl;
}
