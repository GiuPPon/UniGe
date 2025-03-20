/****************************************************/
/* PROVA DI ESAME DI LABORATORIO DI ASD (traccia 1) */
/*                 Domande 3                        */
/****************************************************/

// Descrizione:
// In questa prova di esame di laboratorio consideriamo il tipo di dato Stack (Pila) implementato con
// strutture collegate semplicemente mediante puntatori e tipo base char.

// scrivere sotto Nome, Cognome e Matricola:
// NOME:
// COGNOME:
// MATRICOLA:

/**************************************************************/
/* DESCRIZIONE FUNZIONI DA IMPLEMENTARE

   Sviluppare le seguenti funzioni C/C++:

   1) Stack fillInStack(string str)
      Questa funzione deve inserire in uno stack s tutti i caratteri che costituiscono la stringa str
      passata come parametro e deve restituire s.
      es.  fillInStack("abc") dovra' restituire lo stack con i valori c; b; a ('c' e' l'elemento in cima allo stack)

   2) bool equalStacks(const Stack& s1, const Stack& s2)
      Questa funzione, che fa parte del tipo di dato stack, deve verificare se i due stack presi in input sono uguali.
      Quindi dovra' restituire true se i due stack s1 e s2 contengono gli stessi elementi nello stesso ordine, false altrimenti
      es. equalStacks(s1, s2) dove s1=c; b; a  e s2=c; b; a dovra' restituire true

   3) bool palindroma(string str)
       Questa funzione deve prendere in input una stringa (str) e valutare se questa e' palindroma o meno.
       Nel primo caso la funzione dovra' restituire true, nel secondo false.
       Una stringa e' palindroma quando si legge allo stesso modo partendo da destra e da sinistra
       es. 'radar' e' palindroma, 'nonono' non e' palindroma

       Questa funzione deve OBBLIGATORIAMENTE utilizzare due stack nel seguente modo:
       - Inserire tutta la stringa in uno stack;
       - Prendere un secondo stack e "riversare" meta' del primo stack nel secondo;
       - Se i due stack sono a questo punto uguali (cioe' stessi elementi nello stesso ordine), allora la stringa � palindroma

       E se la stringa è di lunghezza dispari? Serve un piccolo accorgimento ...

       Le funzioni che fanno parte del tipo di dato (escluso equalStacks) non possono essere modificate cosi' come il MAIN.
       E' sempre possibile aggiungere funzioni ausiliarie.
       Anche se non si riesce a forzare l'information hiding, essendo il file unico, cercare ugualmente di applicare i principi
       di buona programmazione e quindi nelle funzioni non comprese nel tipo di dato stack (cioe' fillInStack e palindroma) utilizzare
       solamente (o almeno principalmente) le funzioni offerte dal tipo di dato.
*/

#include <iostream>
#include <string>

using namespace std;

/************************************************************************/
/*      STACK con strutture collegate semplicemente mediante puntatori  */
/************************************************************************/

namespace stack
{
    typedef char Elem;
    struct cell;
    typedef cell *Stack;
    const Stack EMPTYSTACK = nullptr;
    const char EMPTYELEM = ' ';

    Stack createEmpty();                                /* Crea e restituisce uno stack vuoto */
    bool isEmpty(const Stack &);                        /* Verifica se lo stack e' vuoto. Restituisce true se lo stack e' vuoto, false altrimenti */
    void push(const Elem, Stack &);                     /* Aggiunge elem in cima allo stack (operazione safe, si puo' sempre fare) */
    Elem pop(Stack &);                                  /* Toglie dallo stack l'ultimo elemento e lo restituisce; se lo stack e' vuoto la condizione e' di errore. Lo segnaliamo restituendo EMPTYELEM */
    Elem top(const Stack &);                            /* Restituisce l'ultimo elemento dello stack senza toglierlo; se lo stack e' vuoto la condizione e' di errore. Lo segnaliamo restituendo EMPTYELEM */
    int size(const Stack &);                            /* Restituisce la size (cioe' il numero di elementi) dello stack senza svuotare lo stack */
    bool equalStacks(const Stack &s1, const Stack &s2); /* Restituisce true se i due stack s1 e s2 contengono gli stessi elementi nello stesso ordine (cioe' sono uguali), false altrimenti */
}

struct stack::cell
{
    Elem elem;
    cell *next;
};

/****************************************************************/
// IMPLEMENTAZIONE del tipo di dato Stack
/****************************************************************/
stack::Stack stack::createEmpty()
{
    return stack::EMPTYSTACK;
}

/****************************************************************/
bool stack::isEmpty(const Stack &s)
{
    return (s == EMPTYSTACK);
}

/****************************************************************/
void stack::push(const Elem x, Stack &s)
{
    cell *aux = new cell;
    aux->elem = x;
    aux->next = s;
    s = aux;
}

/****************************************************************/
stack::Elem stack::pop(Stack &s)
{
    if (isEmpty(s))
        return EMPTYELEM;
    cell *cur = s;
    s = s->next;
    Elem e = cur->elem;
    delete cur;
    return e;
}

/****************************************************************/
stack::Elem stack::top(const Stack &s)
{
    if (isEmpty(s))
        return EMPTYELEM;
    else
        return s->elem;
}

/****************************************************************/
int stack::size(const Stack &s)
{
    cell *aux = s;
    int tot = 0;
    while (!isEmpty(aux))
    {
        tot++;
        aux = aux->next;
    }
    return tot;
}

/****************************************************************/
bool stack::equalStacks(const Stack &s1, const Stack &s2)
{
    stack::cell *cur = s1;
    stack::cell *aux = s2;

    while (cur != nullptr) {
        while (aux != nullptr) {
            if (cur -> elem != aux -> elem) {
                return false;
            }
            aux = aux -> next;
        }
        cur = cur -> next;
    }
    return true;
}

/****************************************************************/
// Funzioni che non fanno parte del tipo di dato Stack
/****************************************************************/
// Visualizza a video lo stack
void print(const stack::Stack &s)
{
    stack::cell *aux = s;
    cout << endl;
    while (aux != stack::EMPTYSTACK)
    {
        cout << aux->elem << "; ";
        aux = aux->next;
    }
    cout << endl;
}

// Inserisce in uno stack s tutti i caratteri che costituiscono la stringa str e restituisce s
stack::Stack fillInStack(string str)
{
    stack::Stack s;
    for (unsigned int i = 0; i < str.size(); ++i) {
        stack::push(str[i], s);
    }
    return s;
}

// Funzione ausiliaria che inverte uno stack
stack::Stack reverse(stack::Stack &s)
{
    if (s == NULL || s->next == NULL)
        return s;

    /* reverse the rest list and put
      the first element at the end */
    stack::Stack rest = reverse(s->next);
    s->next->next = s;

    /* tricky step -- see the diagram */
    s->next = NULL;

    /* fix the head pointer */
    return rest;
}

// Questa funzione deve prendere in input una stringa e valutare se questa e' palindroma (restituisce true) o meno (restituisce false)
// Una stringa e' palindroma quando si legge allo stesso modo da destra e da sinistra
// es. 'radar' e' palindroma, 'nono' non e' palindroma
bool palindroma(string str)
{
    stack::Stack half1;
    stack::Stack half2;
    unsigned int half = str.size() / 2;

    for (unsigned int i = 0; i < half; ++i) {
        stack::push(str[i], half1);
    }
    if (str.size() % 2 != 0) {
        half = half + 1;
    }
    for (unsigned int j = half; j < str.size(); ++j) {
        stack::push(str[j], half2);
    }

    if (stack::equalStacks(half1, half2) == true) {
        return true;
    }
    return false;
}

/****************************************************************/
// MAIN con casi di test
/****************************************************************/
int main()
{
    // Creo uno Stack 's1' e inserisco i valori 'a', 'b', 'c'
    stack::Stack s1 = stack::createEmpty();
    stack::push('a', s1);
    stack::push('b', s1);
    stack::push('c', s1);

    // Creo uno Stack 's2' vuoto
    stack::Stack s2 = stack::createEmpty();

    cout << "In s1 e' stato inserito il seguente Stack ('c' e' l'elemento in cima allo stack):";
    print(s1);
    cout << endl;
    cout << "s2 e' invece vuoto:";
    print(s2);

    cout << "*** FUNZIONE fillInStack() *** " << endl;
    if (size(fillInStack("abaco")) == 5)
        cout << "TEST 1 fillInStack() PASSATO" << endl;
    else
        cout << "TEST 1 fillInStack() FALLITO" << endl;
    cout << endl;

    cout << "*** FUNZIONE equalStacks() *** " << endl;
    if (stack::equalStacks(s1, s1))
        cout << "TEST 1 equalStacks() PASSATO" << endl;
    else
        cout << "TEST 1 equalStacks() FALLITO" << endl;

    if (!stack::equalStacks(s1, s2))
        cout << "TEST 2 equalStacks() PASSATO" << endl;
    else
        cout << "TEST 2 equalStacks() FALLITO" << endl;
    cout << endl;

    cout << "*** FUNZIONE palindroma() *** " << endl;
    if (palindroma("ereggere"))
        cout << "TEST 1 palindroma() PASSATO" << endl;
    else
        cout << "TEST 1 palindroma() FALLITO" << endl;

    if (!palindroma("nononono"))
        cout << "TEST 2 palindroma() PASSATO" << endl;
    else
        cout << "TEST 2 palindroma() FALLITO" << endl;
    cout << endl;
}
