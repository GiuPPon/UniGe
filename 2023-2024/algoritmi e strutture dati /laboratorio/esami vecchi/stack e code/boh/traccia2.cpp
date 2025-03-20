/***********************************************************/
/* PROVA DI ESAME DI LABORATORIO DI ASD (traccia gruppo 2) */
/***********************************************************/

// Descrizione:
// In questo laboratorio si considera il tipo di dato STACK visto a lezione e leggermente
// modificato per contenere dei caratteri implementato con la struttura dati lista di puntatori

// scrivere sotto Nome, Cognome e Matricola:
// NOME:
// COGNOME:
// MATRICOLA:

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
const char EMPTYCHAR = '$'; // carattere usato per gestire casi di errore; da non usare nelle stringhe e stack di esempio

/***************************/
/* Stack.h
/***************************/
namespace stack
{
    struct cell;
    typedef cell *Stack;
    const Stack EMPTYSTACK = nullptr;

    bool isEmpty(const Stack &);
    void push(const char, Stack &); /* aggiunge il carattere in cima (operazione safe, si puo' sempre fare) */
    char pop(Stack &);              /* toglie dallo stack l'ultimo elemento e lo restituisce; se lo stack e' vuoto
                                    viene restituito EMPTYCHAR) */
    Stack createEmpty();
}

/***************************/
/* Stack.cpp
/***************************/
// Gli elementi dello STACK sono dei caratteri
struct stack::cell
{
    char elem;
    cell *next;
};

/****************************************************************/
bool stack::isEmpty(const Stack &s)
{
    return (s == EMPTYSTACK);
}

/****************************************************************/
void stack::push(const char x, Stack &s)
{
    cell *aux = new cell;
    aux->elem = x;
    aux->next = s;
    s = aux;
}

/****************************************************************/
char stack::pop(Stack &s)
{
    if (isEmpty(s))
        return EMPTYCHAR;
    cell *cur = s;
    s = s->next;
    char e = cur->elem;
    delete cur;
    return e;
}

// funzione ausiliaria crea stack vuoto
stack::Stack stack::createEmpty()
{
    Stack s = EMPTYSTACK;
    return s;
}

/****************************************************************/
/* DESCRIZIONE FUNZIONI DA IMPLEMENTARE

   Sviluppare le seguenti funzioni C/C++:

   1) returnFirstParenthesis(string &str) che analizza una stringa partendo dall'inizio e ritorna la prima parentesi tonda
   che trova (aperta o chiusa) e cancella dalla stringa str gli eventuali caratteri precedenti che non sono parentesi tonde
   (notare che la stringa str e' passata per riferimento proprio per poterla modificare).
   Nel caso non ci siano parentesi tonde in str la funzione dovra' ritornare EMPTYCHAR.
   Se per esempio str fosse 1+2)+(999) allora la funzione dovra' restituire ')' e str diventare +(999)

   2) parenthesisArebalanced(string &str) che legge una stringa di caratteri da sinistra verso destra e decide se
   le parentesi contenute nella stringa sono bilanciate o no.
   Se per esempio str fosse (1+2)+(999) allora la funzione dovra' restituire true
   Se invece str fosse (()()(() la funzione dovra' restituire false

   Suggerimento: Partendo da una pila vuota, processiamo le parentesi da sinistra verso destra.
   Se un simbolo è una parentesi aperta (usare la funzione  returnFirstParenthesis precedente per recuperare il valore), lo mettiamo sulla pila
   come segnale che un simbolo di chiusura corrispondente deve apparire più tardi. Se il simbolo è una parentesi chiusa,
   facciamo pop sulla pila. Finché è possibile fare pop sulla pila per trovare una corrispondenza per il simbolo di chiusura,
   le parentesi rimangono bilanciate. Se a un certo punto non c’è un simbolo di apertura sulla pila che corrisponde al simbolo
   di chiusura che stiamo leggendo in quel momento, la stringa non ha le parentesi bilanciate. Alla fine della stringa, quando
   tutti i simboli sono stati processati e abbiamo analizzato una stringha con parentesi bilanciate, la pila dovra' essere vuota.

   3) countParenthesis(stack::Stack& s) che prende in input uno Stack ed usando le operazioni offerte
   dal tipo di dato Stack conta le parentesi tonde aperte e chiuse trovate (e scarta gli altri caratteri) svuotando lo Stack
   Se per esempio lo Stack contenesse ( 1 8 + ) ) allora la funzione dovra' restituire il numero 3
*/

// Questa funzione analizza una stringa partendo dall'inizio e ritorna la prima parentesi tonda che trova
// (aperta o chiusa) e cancella dalla stringa str gli eventuali caratteri precedenti che non sono parentesi
// tonde (notare che la stringa str e' passata per riferimento proprio per poterla modificare).
// Nel caso non ci siano parentesi in str la funzione dovra' ritornare EMPTYCHAR.
char returnFirstParenthesis(string &str)
{
    // Scorre la stringa per trovare la prima parentesi tonda
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '(' || str[i] == ')') {
            char result = str[i];
            // substr è un metodo della classe std::string in C++ e serve per estrarre una sottostringa da una stringa
            str = str.substr(i + 1);
            // Rimuovi tutti i caratteri prima di 'i' inclusa la parentesi trovata
            // str.erase(0, i + 1);

            // Ritorna la parentesi trovata
            return result;
        }
    }
    // Se nessuna parentesi è trovata, ritorna EMPTYCHAR
    return EMPTYCHAR;
}

// Questa funzione legge una stringa di caratteri da sinistra verso destra e decide se
// le parentesi contenute nella stringa sono bilanciate o no.
bool parenthesisArebalanced(string &str)
{
    int count1 = 0;
    int count2 = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            ++count1;
        } else if (str[i] == ')') {
            ++count2;
        }
    }
    if (count1 == count2) {
        return true;
    }
    return false;
}

// Questa funzione prende in input uno Stack ed usando le operazioni offerte
// dal tipo di dato Stack deve contare le parentesi aperte e chiuse trovate
int countParenthesis(stack::Stack &s)
{
   int count = 0;

    // Continua finché lo stack non è vuoto
    while (!isEmpty(s)) {
        char topElement = pop(s);
        // Conta solo le parentesi tonde
        if (topElement == '(' || topElement == ')') {
            ++count;
        }
    }
    // Ritorna il conteggio totale
    return count;
}

/****************************************************************/
// MAIN con casi di test
/****************************************************************/

using namespace stack;
int main()
{
    cout << "****** ESECUZIONE  ****** " << endl;
    cout << "*** FUNZIONE 1 *** " << endl;
    string s = "2+(1+1)";
    if (returnFirstParenthesis(s) == '(' && s == "1+1)")
        cout << "il caso di test e' PASSATO" << endl;
    else
        cout << "il caso di test e' FALLITO" << endl;

    cout << "*** FUNZIONE 2 *** " << endl;
    s = "((1+2)*3)";
    if (parenthesisArebalanced(s))
        cout << "il caso di test e' PASSATO" << endl;
    else
        cout << "il caso di test e' FALLITO" << endl;
    s = "(2+(1+1)";
    if (!parenthesisArebalanced(s))
        cout << "il caso di test e' PASSATO" << endl;
    else
        cout << "il caso di test e' FALLITO" << endl;

    cout << "*** FUNZIONE 3 *** " << endl;
    Stack myStack = EMPTYSTACK;
    push('(', myStack);
    push('1', myStack);
    push(')', myStack);
    push(')', myStack);
    if (countParenthesis(myStack) == 3)
        cout << "il caso di test e' PASSATO" << endl;
    else
        cout << "il caso di test e' FALLITO" << endl;

    return 0;
}
