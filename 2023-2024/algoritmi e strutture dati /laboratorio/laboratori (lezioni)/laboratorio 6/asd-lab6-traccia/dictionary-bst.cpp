#include "dictionary.h"

using namespace dict;

//STRUCT TO BE COMPLETED
// *** NON AGGIUNGETE IL PUNTATORE AL PADRE ALLA STRUCT!!!! *** 
struct dict::bstNode {
  Elem info;
  bstNode *leftChild;
  bstNode *rightChild;
};

//Funzione da implementare
bool dict::isEmpty(const Dictionary& d){
  return (d == emptyDictionary);             // emptyDictionary = nullptr
}
   
//Funzione da implementare
Dictionary dict::createEmptyDict(){
  Dictionary d = emptyDictionary;
  return d;
}

//Funzione da implementare
Error dict::insertElem(const Key k, const Value v, Dictionary& d){
  if (isEmpty(d)) {                    // caso base
    bstNode *node = new bstNode;
    node -> info.key = k;
    node -> info.value = v;
    node -> leftChild = emptyNode;
    node -> rightChild = emptyNode;
    d = node;
    return OK;
  }
  if (d -> info.key == k) {
    return FAIL;
  }
  if (d -> info.key < k) {
    return insertElem(k, v, (d -> rightChild));
  } else {
    return insertElem(k, v, (d -> leftChild));
  }
}

//Funzione da implementare
Value dict::search(const Key k, const Dictionary& d){
  if (isEmpty(d)) {
    return emptyValue;
  }
  if (d -> info.key == k) {
    return d -> info.value;
  }
  if (d -> info.key < k) {                    // k maggiore del nodo corrente
    return search(k, (d -> rightChild));      // cerca a destra 
  } else {                                    // k minore del nodo corrente 
    return search(k, (d -> leftChild));       // cerca a sinistra
  }
}

//Funzione da implementare

// funzione ausiliaria
Elem deleteMin(Dictionary& d) {
  if ((d -> leftChild) == emptyNode) {
    Elem temp = d -> info;
    Dictionary tempChild = d -> rightChild;     // figlio dell'ultimo nodo
    delete d;
    d = tempChild;
    return temp;
  } else {
    return deleteMin(d -> leftChild);
  }
}

Error dict::deleteElem(const Key k, Dictionary& d){
  if (isEmpty(d)) {
    return FAIL;
  }
  if (d -> info.key == k) {
    if (d -> rightChild == emptyNode && d -> leftChild == emptyNode) {    // caso senza figli
      delete d;
      d = emptyNode;
    } else if (d -> rightChild == emptyNode) {                            // solo figlio sinistro
      Dictionary temp = d -> leftChild;
      delete d;
      d = temp;
    } else if (d -> leftChild == emptyNode) {                             // solo figlio destro
      Dictionary temp = d -> rightChild;
      delete d;
      d = temp;
    } else {                                                             // entrambi i figli
      d -> info = deleteMin(d -> rightChild);
    }
    return OK;
  }
  if (d -> info.key < k) {
    return deleteElem(k, (d -> rightChild));
  } else {
    return deleteElem(k, (d -> leftChild));
  }
}

//Funzione da implementare
void print(const Dictionary& d) {
  if (isEmpty(d)) {
    return;
  }
  if (d -> leftChild != emptyNode) {
    print(d -> leftChild);
  }
  cout << d -> info.key << " : " << d -> info.value << endl;
  if (d -> rightChild != emptyNode) {
    print(d -> rightChild);
  }
}



























/****************************************************************/
/*              FUNZIONE IMPLEMENTATE                           */
/****************************************************************/
Dictionary readFromFile(string nome_file){
  ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return emptyDictionary;}  
  return readFromStream(ifs);
}

Dictionary readFromStdin(){
  cout << "\nInserire una sequenza di linee che rispettano la sintassi key: value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
  Dictionary d = readFromStream((std::cin));
  // Questa serve per aggirare un bug di alcune versioni attuali di glibc.
  clearerr(stdin);
  return d;
}

Dictionary readFromStream(istream& str){
  Dictionary d = emptyDictionary; 
  string key, kcopy;
  string value;
  getline (str, key, ':'); 
  getline (str, value); 
  while (!str.eof())  
    {        
      kcopy = key;
      removeBlanksAndLower(kcopy); 
      insertElem(kcopy, value, d);
      getline (str, key, ':'); 
      getline (str, value); 
    }
  str.clear();
  return d;
}
