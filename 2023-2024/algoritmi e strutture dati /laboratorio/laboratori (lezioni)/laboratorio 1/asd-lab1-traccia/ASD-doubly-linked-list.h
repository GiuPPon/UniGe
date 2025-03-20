#ifndef ASD_DLL_H
#define ASD_DLL_H

namespace list{
  //*forward declaration del node*/
  /*la struttura e' implementata*/
  /*nel file ASD-doubly-linked-list.cpp*/
  struct node;           

  /*gli elementi della lista sono degli int; astraggo mediante un typedef*/
  typedef int Elem;       

  /* List e' il tipo "puntatore a node", dove node e' la struct */
  /*dichiarata ma non definita*/
  typedef node* List;

  /**************************************************/
  /*       prototipi di funzioni da implementare    */
  /**************************************************/
    
  /* crea la lista vuota */
  void createEmpty(List&);

  /* "smantella" la lista (tranne la sentinella) */
  void clear(List&);

  /* restituisce true se la lista e' vuota */
  bool isEmpty(const List&);

  /* restituisce la dimensione della lista */
  unsigned int size(const List&);

  /* restituisce l'elemento in posizione pos */
  /* se pos non e corretta, solleva una eccezione di tipo string*/
  Elem get(unsigned int pos, const List&);

  /* modifica l'elemento in posizione pos */
  /* se pos non e' corretta, solleva una eccezione di tipo string*/
  void set(unsigned int pos, Elem, const List&);

  /* inserisce l'elemento in posizione pos*/
  /*shiftando a destra gli altri elementi */
  /* se pos non e' corretta, solleva una eccezione di tipo string*/
  void add(unsigned int pos, Elem, const List&);

  /* inserisce l'elemento alla fine della lista */
  void addRear(Elem, const List&);

  /* inserisce l'elemento all'inizio della lista */
  void addFront(Elem, const List&);

  /* cancella l'elemento in posizione pos dalla lista */
  /* se pos non e' corretta, solleva una eccezione di tipo string*/
  void removePos(unsigned int pos, const List&);

  /* cancella tutte le occorrenze dell'elemento elem*/
  /*se presenti, dalla lista */
  void removeEl(Elem, const List&);

  /**************************************************/
  /*       prototipi di funzioni implementate       */
  /**************************************************/
  
  /* riempie una lista da file */
  void readFromFile(std::string, const List&);

  /* legge il contenuto di una lista da standard input */
  void readFromStdin(const List&);

  /* stampa la lista */
  void print(const List&);

  /* produce una string contenendo la lista*/
  std::string tostring(const List& li);          
}

#endif
