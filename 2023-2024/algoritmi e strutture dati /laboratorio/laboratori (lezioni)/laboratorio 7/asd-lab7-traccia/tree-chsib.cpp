#include "tree-chsib.h"

using namespace tree;

/* Nota: nei commenti usiamo "albero" e "puntatore a un nodo" come sinonimi, scegliendo di volta in volta
la formulazione più adatta a dare la specifica di una funzione. 
Dal punto di vista tecnico, usiamo sempre il tipo Tree sia quando operiamo su un albero, sia quando operiamo, 
a livello concettuale, su un puntatore a un nodo dell'albero. 
Questo approccio e' corretto in quanto un albero (o sottoalbero) è un puntatore a una struct di tipo treeNode:
un albero è identificato univocamente dal puntatore alla sua radice */ 



/*******************************************************************************************************/
// il nodo di un albero è caratterizzato dall'etichetta, il puntatore al primo figlio e il puntatore al prossimo fratello
// NON manteniamo il puntatore al padre, anche se sarebbe comodo per alcune funzioni (ma del tutto inutile per altre)
struct tree::treeNode {
    Label label;    
    treeNode *firstChild;
    treeNode *nextSibling;
};



/*******************************************************************************************************/
// isEmpty restituisce true se l'albero t e' vuoto, false altrimenti
bool tree::isEmpty(const Tree& t) { 
   return (t == emptyTree);
}


// funzione ausiliaria: data un'etichetta l e un albero t (ovvero, un albero la cui radice
// è il nodo puntato da t), restituisce il puntatore al nodo dell'albero t che ha quell'etichetta 
// (emptyTree se nessun nodo ha quell'etichetta)
Tree getNode(const Label l, const Tree& t) { 
   if (isEmpty(t) || l == emptyLabel) {
      return emptyTree;
   }

   if (t -> label == l) {
      return t;
   }

   Tree aux = t -> firstChild;
   Tree node;
   while (aux != emptyTree) {
      node = getNode(l, aux);
      // non ho trovato cercando in questo sottoalbero, devo proseguire la scansione dei fratelli
      if (node == emptyTree) {
         aux = aux -> nextSibling;
      } else {
         return node;
      }
   }   
   return emptyTree; // se arrivo fino a qui, vuole dire che al termine di una ricerca esaustiva nell'albero il nodo non è stato trovato 
}

/*******************************************************************************************************/
// addElem aggiunge il nodo etichettato con labelOfNodeToAdd come
// figlio del nodo etichettato con labelOfNodeInTree.
// Caso particolare: aggiunta della radice, che si ottiene
// con labelOfNodeInTree uguale a emptyLabel (= nessun padre), e ha successo
// solo se l'albero e' vuoto (in caso contrario restituisce FAIL 
// e non aggiunge nulla).
// Restituisce FAIL se non esiste un nodo nell'albero etichettato 
// con labelOfNodeInTree oppure se nell'albero esiste gia' un nodo 
// etichettato con labelOfNodeToAdd; aggiunge e restituisce OK altrimenti

Tree createNode(const Label l) { 
   Tree t = new treeNode;
   t -> label = l;
   t -> firstChild = emptyTree;
   t -> nextSibling = emptyTree;
   return t;
}

Error tree::addElem(const Label labelOfNodeInTree, const Label labelOfNodeToAdd, Tree& t) {
   // labelOfNodeInTree è etichetta vuota e l'albero è vuoto
   if ((labelOfNodeInTree == emptyLabel) && isEmpty(t)) {
      t = createNode(labelOfNodeToAdd); 
      return OK;
   }

   // nell'albero esiste già un nodo con etichetta labelOfNodeToAdd, restituisco FAIL
   if (member(labelOfNodeToAdd, t)) {
       return FAIL;
   }

   // recupero il puntatore al nodo dell'albero che ha etichetta labelOfNodeInTree
   Tree aux = getNode(labelOfNodeInTree, t);

   if (aux == emptyTree) {
     return FAIL; // nell'albero non esiste un nodo con etichetta labelOfNodeInTree, restituisco FAIL
   } else {
     Tree child = createNode(labelOfNodeToAdd); // creo un nodo child con l'etichetta labelOfNodeToAdd
     child -> nextSibling = aux -> firstChild;     // il primo fratello di child sarà quello che era il primo figlio di auxT
     aux -> firstChild = child;                  // child diventa il primo figlio di auxT
   }
   return OK;
}     



/*******************************************************************************************************/
// deleteElem (versione iterativa) rimuove dall'albero il nodo etichettato con la Label l
// e collega al padre di tale nodo tutti i suoi figli
// Restituisce FAIL se si tenta di cancellare la radice e questa ha 
// dei figli (non si saprebbe a che padre attaccarli) oppure se non esiste 
// un nodo nell'albero etichettato con la Label; cancella e restituisce OK altrimenti
Error tree::deleteElemI(const Label l, Tree& t)
{
     return FAIL;     
}



/*******************************************************************************************************/
// deleteElem (versione ricorsiva): stesso comportamento della versione iterativa, ma implementata ricorsivamente
// (può anche non essere ricorsiva la deleteElemR, ma deve fare uso di funzioni ausiliarie ricorsive)
Error tree::deleteElemR(const Label l, Tree& t)
{
     return FAIL;    
}



/*******************************************************************************************************/
// father restituisce l'etichetta del padre del nodo con etichetta l se il nodo esiste nell'albero 
// (o sottoalbero) t e se il padre esiste. 
// Restituisce la costante emptyLabel altrimenti

bool hasChildWithLabel(const Label l, const Tree& t) {
   if (isEmpty(t)) {
      return false;
   } 

   Tree child = t -> firstChild;
   while (isEmpty(child) == false) {      // scorre il figlio
      if (child -> label == l) {
         return true;
      } 
      child = child -> nextSibling;
   }
   return false;
}

Label tree::father(const Label l, const Tree& t) { 
   if (isEmpty(t)) {
      return emptyLabel;
   }

   if (hasChildWithLabel(l, t)) {
      return t -> label;
   }

   Tree child = t -> firstChild;
   Label aux;
   while (isEmpty(child) == false) { 
      aux = father(l, child);
      if (aux != emptyLabel) {
         return aux;
      }
      child = child -> nextSibling;
   }
   return emptyLabel;  
}


/*******************************************************************************************************/
// children restituisce una lista di Label, contenente le etichette 
// di tutti i figli nell'albero t del nodo etichettato con l
// La lista può essere implementata usando una qualunque delle strutture dati viste a lezione
// (non un Vector!!!): si riusi una implementazione del TDD list, adattandola 
// a elementi di tipo string (nelle precedenti esercitazioni gli elementi erano int)
list::List tree::children(const Label l, const Tree& t) {
   list::List list = list::createEmpty();
   Tree aux = getNode(l, t);

   if (isEmpty(aux) == false) {
      Tree child = aux -> firstChild;
      while (!isEmpty(child)) {
         list::addBack(child -> label, list);
         child = child -> nextSibling;
      }
   }
   return list;
}



/*******************************************************************************************************/
// degree restituisce il numero di archi uscenti dal nodo etichettato con l; restituisce -1 se non esiste 
// nessuna etichetta l nell'albero
int tree::degree(const Label l, const Tree& t) {
   if (member(l,t) == false) {
      return -1;
   } 

   Tree node = getNode(l, t);
   int count = 0;

   Tree aux = node -> firstChild;
   while (aux != emptyTree) {
      ++count;
      aux = aux -> nextSibling;
   }
   return count;     // restituisce il numero di figli
}



/*******************************************************************************************************/
// ancestors (versione ricorsiva) restituisce una lista di Label, contenente le etichette 
// di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo stesso
// La lista può essere implementata usando una delle strutture dati viste a lezione
// (non un Vector)
// (può anche non essere ricorsiva la ancestorsR, ma deve fare uso di funzioni ausiliarie ricorsive)
list::List tree::ancestorsR(const Label l, const Tree& t)
{
   list::List lst = list::createEmpty();
   return lst;
}



/*******************************************************************************************************/
// ancestors (versione iterativa) restituisce una lista di Label, contenente le etichette 
// di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo stesso
// La lista può essere implementata usando una delle strutture dati viste a lezione
// (non un Vector)
list::List tree::ancestorsI(const Label l, const Tree& t)
{
   list::List lst = list::createEmpty();
   return lst;
}



/*******************************************************************************************************/
// leastCommonAncestor restituisce l'etichetta del minimo antenato comune 
// ai nodi etichettati con label1 e label2
Label tree::leastCommonAncestor(const Label label1, const Label label2, const Tree& t)
{
   return emptyLabel;
}



/*******************************************************************************************************/
// member restituisce true se il nodo etichettato con la label l appartiene all'albero t e false altrimenti
bool tree::member(const Label l, const Tree& t) { 
   if (isEmpty(t)) {
      return false;
   }
   if (t -> label == l) {
      return true;
   }
   Tree aux = t -> firstChild;
   while (aux != emptyTree) {
      if (member(l, aux) == true) {
         return true;
      } 
      aux = aux -> nextSibling;
      /*
      if (member(l, aux) == false) {
         aux = aux -> nextSibling;
      } else {
         return true;
      } */
   }
   return false;  
}



/*******************************************************************************************************/
// numNodes restituisce il numero di nodi nell'albero t mediante una visita ricorsiva in depthfirst
int tree::numNodes(const Tree& t) {
   if (isEmpty(t)) {
      return 0;
   }

   Tree aux = t -> firstChild;
   int count = 1;       // inizializzato a 1 come radice
   while (aux != emptyTree) {
     count += numNodes(aux);
     aux = aux -> nextSibling;
   }   
   return count;
}



/*******************************************************************************************************/
// createEmptyTree restituisce l'albero vuoto
Tree tree::createEmpty()
{
   return emptyTree;
}



/*******************************************************************************************************/
// Visualizzazione possibilmente strutturata come visto a lezione
void printTree(const Tree& t) {
    return;
}



/****************************************************************/
// Questa funzione NON richiede di conoscere come e' fatta la struttura dati che implementa l'albero: usa solo addElem e quindi e' ad 
// un alto livello di astrazione
// Vantaggi: codice compatto, leggibile, riutilizzabile per qualunque implementazione del TDD Tree
// Svantaggi: inefficiente: la addElem cerca ogni volta il nodo con etichetta fatherLabel, mentre basterebbe una chiamata sola per 
// trovarlo e poi si potrebbero attaccare tutti i figli a esso, senza ripetere la dispendiosa ricerca nell'albero; per renderla 
// efficiente dovrei pero' accedere direttamente alla struttura dati chiamando qualche funzione ausiliaria che operi 
// sui nodi dell'albero, rinunciando a scrivere codice modulare, chiaro e ad un ragionevole livello di astrazione... 
// Non esiste un'opzione migliore tra le due: se il codice deve essere efficiente, è opportuno scrivere una funzione ad hoc per 
// una determinata implementazione; se il codice deve essere riutilizzabile, bisogna limitarsi a usare le funzioni offerte dall'
// interfaccia del TDD in modo che la funzione continui ad andare bene anche se cambia l'implementazione
Tree readFromStream(istream& str)
{
    Tree t = createEmpty(); 
    string line;
    Label rootLabel, fatherLabel, childLabel;
    getline(str, line);  
    istringstream instream;            // uso una variabile di tipo istringstream per poter scandire i pezzi di ogni riga usando >>
    instream.clear();
    instream.str(line);
    instream >> rootLabel;             // il primo elemento che si incontra nel file e' l'etichetta della radice, per convenzione su come deve essere fatto il file
    addElem(emptyLabel, rootLabel, t); // la si inserisce nell'albero vuoto, indicando che il padre non c'e' (primo argomento emptyLabel)
    getline(str, line);                // poi si iniziano a scansionare le righe seguenti
    instream.clear();
    instream.str(line);
    while (!str.eof())  
        {        
	instream >> fatherLabel; // in ogni riga del file, il primo elemento e' l'etichetta del nodo padre e gli altri sono le etichette dei figli
        removeBlanksAndLower(fatherLabel); // normalizzo l'etichetta del padre
        while (!instream.eof())            // finche' la riga corrente non e' terminata
            { 
            instream >> childLabel;              // leggo la prossima etichetta
            removeBlanksAndLower(childLabel);    // la normalizzo
            addElem(fatherLabel, childLabel, t); // e la attacco al padre
            }
        getline(str, line);  
        instream.clear();
        instream.str(line);
        }
    str.clear();
    return t;
}



/****************************************************************/
Tree readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return createEmpty();}  
    return readFromStream(ifs);
}

