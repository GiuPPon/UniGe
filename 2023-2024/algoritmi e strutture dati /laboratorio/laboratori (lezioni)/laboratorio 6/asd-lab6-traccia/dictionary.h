#include <iostream>
#include <stdexcept>
#include <vector> 
#include <fstream> 
#include <chrono>          // necessario compilare con -std=c++11
#include <stdlib.h>        // srand, rand
#include <string>          // std::string

#include "string-utility.h"

using namespace std::chrono; 
using namespace std; 

namespace dict {

  // Codici di errore
  enum Error {OK, FAIL};

  // Tipi e costanti
  typedef string Key;        // tipo base 
  typedef string Value;      // tipo base 

  const Key emptyKey = "###RESERVED KEYWORD### EMPTY KEY";
  const Value emptyValue = "###RESERVED KEYWORD### EMPTY VALUE";

  typedef struct {
    Key	key;
    Value value;
  } Elem;

  // Implementazione basata su albero binario di ricerca
  struct bstNode; // forward declaration

  typedef bstNode* Dictionary;

  const Dictionary emptyNode = NULL;
  const Dictionary emptyDictionary = NULL;

  //Prototipi di funzione da implementare
  Error insertElem(const Key, const Value, Dictionary&);
  Error deleteElem(const Key, Dictionary&);
  Value search(const Key, const Dictionary&);
  Dictionary createEmptyDict();
  bool isEmpty(const Dictionary&);
}  // end namespace Dict

//Funzione da implementare
void print(const dict::Dictionary&);

//Funzione implementate
dict::Dictionary readFromFile(string);
dict::Dictionary readFromStdin();
dict::Dictionary readFromStream(istream&);

