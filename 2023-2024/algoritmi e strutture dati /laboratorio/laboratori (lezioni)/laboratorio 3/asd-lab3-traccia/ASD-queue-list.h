// NON MODIFICARE QUESTO FILE
#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H 

#include <string>
#include <iostream>

// Implementa QUEUE con una lista e 
// tipo base Elem dotato di ordinamento
namespace queue{
    // tipo base 
    typedef int Elem;   

    struct cell;

    typedef cell *list;

    const list EMPTYLIST = nullptr;

    typedef struct {
        //lista dove saranno messi gli elementi, uguale a nullptr se è vuota
        list li;
        //ultimo elemento della lista, uguale a nullptr se è vuota
        list end;
    } Queue;

    /**************************************************/
    /*       prototipi di funzioni da implementare    */
    /**************************************************/

    /* restituisce la coda vuota */
    Queue createEmpty(); 

    /* restituisce true se la queue e' vuota */
    bool isEmpty(const Queue&);

    /* inserisce l'elemento "da una parte" della coda */
    void enqueue(Elem, Queue&); 

    /* cancella l'elemento (se esiste) "dall'altra parte */
    /*della coda" e lo restituisce; se la coda è vuota solleva */
    /*una eccezione di tipo string*/
    Elem dequeue(Queue&);

    /* restituisce l'elemento in prima posizione (se esiste) senza cancellarlo*/ 
    /*se la coda è vuota solleva una eccezione di tipo string*/
    Elem first(Queue&);

    /**************************************************/
    /*       prototipi di funzioni implementate       */
    /**************************************************/
  
    /* riempie una coda da file */
    Queue readFromFile(std::string);
        

    /* legge il contenuto di una coda da standard input */
    Queue readFromStdin();

    /* stampa la coda*/
    void print(const Queue&);

    /* produce una string contenente la coda*/
    std::string tostring(const Queue&); 
}

#endif
