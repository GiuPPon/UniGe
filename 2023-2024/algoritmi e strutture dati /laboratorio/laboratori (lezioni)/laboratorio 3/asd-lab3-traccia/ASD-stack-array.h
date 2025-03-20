#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H 

#include <string>

// Implementa STACK con dynamic array
// e tipo base Elem dotato di ordinamento
namespace stack{
    //lunghezza dei blocchi da aggiungere
    //quando l'array dinamico cresce
    const unsigned int BLOCKDIM = 10;

    // tipo base 
    typedef int Elem;  

    typedef struct {
        //array dove sarono messi gli elementi
        Elem* data;
        //posizione del ultimo elemento
        unsigned int size;
        //lunghezza dell'array
        unsigned int maxsize;
    } Stack;

    /**************************************************/
    /*       prototipi di funzioni da implementare    */
    /**************************************************/

    /* restituisce lo stack vuoto */
    Stack createEmpty();

    /* restituisce true se lo stack e' vuoto */
    bool isEmpty(const Stack&);

    /* aggiunge elem in cima (operazione safe, si può sempre fare) */
    void push(const Elem, Stack&);

    /* toglie dallo stack l'ultimo elemento e lo restituisce */
    /* se lo stack è vuoto solleva una eccezione di tipo string */
    Elem pop(Stack&);	

    /* restituisce l'ultimo elemento dello stack senza toglierlo.*/
    /* Se lo stack è vuoto solleva una eccezione di tipo string*/
    Elem top(Stack&);

    /**************************************************/
    /*       prototipi di funzioni implementate       */
    /**************************************************/
  
    /* riempie lo stack da file */
    Stack readFromFile(std::string);
        
    /* legge il contenuto di uno stack da standard input */
    Stack readFromStdin();

    /* stampa lo stack*/
    void print(const Stack&);

    /* produce una stringa contenente lo stack*/
    std::string tostring(const Stack&); 
}

#endif