/****************************************************/
/* PROVA DI ESAME DI LABORATORIO DI ASD (traccia gruppo 1) */
/****************************************************/

// Descrizione:
// In questa prova di esame di laboratorio consideriamo le liste circolari semplici viste a lezione (ovvero strutture collegate 
// semplicemente mediante puntatori) i cui elementi sono delle struct (vedere la struct fattura_t nel codice) che contengono
// alcune informazioni relative ad una fattura (in particolare Id, nome dell'azienda e subtotale dei vari prodotti)
//
// ad esempio le informazioni di una fattura potrebbero essere le seguenti:
// 1, "Polpa Pronta Rica", 40
//
// dove 40 rappresenta il subtotale in Euro della fattura 1 intestata all'azienda Polpa Pronta Rica

// scrivere sotto Nome, Cognome e Matricola:
// NOME:
// COGNOME:
// MATRICOLA:
    
/**************************************************************/
/* DESCRIZIONE FUNZIONI DA IMPLEMENTARE

   Sviluppare le seguenti funzioni C/C++:

   1) print_list() che stampa tutte le fatture contenute nella lista senza effettuare nessun ordinamento. 
      Se ad esempio nella lista sono contenute le seguenti 3 celle:
      {1, "Olio Carli", 100}, {2, "Polpa Pronta Rica", 200}, {3, "Dell cartoni", 300}
      la funzione dovra' stampare le fattura una per ogni riga andando a capo dopo ogni fattura (ovvero stmapare il seguente testo nell'esempio):
      1, Olio Carli, 100
      2, Polpa Pronta Rica, 200
      3, Dell cartoni, 300
      FINE
      
      Alla fine la stampa sarà completata dalla parola FINE. Nel caso la lista sia vuota la funzione dovrà stampare solo FINE.
      
   2) tail_insert() che inserisce una nuova fattura alla fine della lista
      Se ad esempio nella lista sono contenute le seguenti 2 celle:
      {1, "Olio Carli", 100}, {2, "Polpa Pronta Rica", 200} 
      ed aggiungiamo {3, "Dell cartoni", 300} alla fine della lista
      la lista diventera' la seguente:
      {1, "Olio Carli", 100}, {2, "Polpa Pronta Rica", 200}, {3, "Dell cartoni", 300}
      
   3) compute_total() che calcola il totale di tutte le fatture contenute nella lista e ritorna il valore completo di IVA al 22%
      Se ad esempio nella lista sono contenute le seguenti 2 celle:
      {1, "Olio Carli", 100}, {2, "Polpa Pronta Rica", 200}
      la funzione dovra' ritornare il valore 366 (ovvero 300 + il 22% di 300 = 66)
      Nel caso la lista sia vuota la funzione deve ritornare il valore emptyValue (definito come costante)
*/

#include <iostream>
#include <string>
using namespace std;

/****************************************************************/
// Struct, typedef e const
/****************************************************************/

struct fattura_t {
	int id;
	std::string azienda;
	float subtotale; // dovrebbe essere  Euro ma per semplicita' usiamo i float
};

struct cell {
	fattura_t payload;
	cell* next;
};

typedef cell* basic_list;

const basic_list emptyList = NULL;
const float emptyValue = -1000;

/****************************************************************/
// Implementazione delle liste circolari semplici
/****************************************************************/

// Inserisce una nuova cella che contiene la fattura 'new_value' all'inizio della lista (in testa)
void head_insert(basic_list& list, fattura_t new_value) {
	cell* aux = new cell;
	aux->payload = new_value;
	if (list == emptyList) 
		aux->next = aux;
	else 
		{cell* tmp = list;
		 while (tmp->next != list)
			tmp = tmp->next;
		tmp->next = aux;
		aux->next = list;
		}
    
    list = aux;
}


// Stampa le fatture contenute nella lista. Nel caso la lista sia vuota la funzione deve stampare solo la stringa FINE
void print_list(std::ostream& output_stream, basic_list list) {
  cell *cur = list;
  do {
    output_stream << cur -> payload.id << " " << cur -> payload.azienda << " " << cur -> payload.subtotale << endl;
    cur = cur -> next;
  } while (cur != list);
}

// Inserisce una nuova cella che contiene la fattura 'new_value' alla fine della lista (cioe' in coda)
void tail_insert(basic_list& list, fattura_t new_value) {
  cell *aux = new cell;
  aux -> payload = new_value;
  
  if (list == emptyList) {
    list = aux;
    aux -> next = aux;
  }

  cell *cur = list;
  while (cur -> next != list) {
    cur = cur -> next;
  }
  cur -> next = aux;
  aux -> next = list;
}

// Calcola il totale delle fatture contenute nella lista considerando l'IVA al 22%
float compute_total(basic_list& list) {
  cell *cur = list;
  float sum = 0.0;

  if (list == emptyList) {
    return emptyValue;
  }

  do {
    sum += cur -> payload.subtotale;
    cur = cur -> next;
  } while (cur != list);
  return sum + ((sum / 100) * 22);
}

/****************************************************************/
// MAIN con casi di test
/****************************************************************/
int main(int argc, char* argv[]) {
    // definiamo una lista
	basic_list my_list = emptyList;
	// definiamo due fatture f1 e f2
	fattura_t f1 = {2, "Olio Carli", 100};
	fattura_t f2 = {1, "Polpa Pronta Rica", 50};
	// inseriamo f1 e f2 nella lista usando head_insert() (in testa)
	head_insert(my_list, f1);
	head_insert(my_list, f2);
	
	cout << "****** ESECUZIONE  ****** " << endl;
	cout << "*** FUNZIONE 1 *** " << endl;
	// stampiamo la lista
	cout << "* INIZIO STAMPA *" << endl;
	print_list(cout, my_list);
	cout << "* FINE STAMPA *" << endl;
	cout << "\nLa tua funzione 1 e' corretta se subito sopra, tra INIZIO STAMPA e FINE STAMPA, ha stampato: " << endl;
	cout << "1, Polpa Pronta Rica, subtotale 50" << endl;
    cout << "2, Olio Carli, subtotale 100" << endl;
    cout << "FINE" << endl;
	
	// definiamo una nuova fattura f3
    fattura_t f3 = {3, "Dell cartoni", 150};
	// inseriamo f3 nella lista usando tail_insert() (in coda)
    tail_insert(my_list, f3);
    cout << "\n*** FUNZIONE 2 *** " << endl;
	// stampiamo la lista
	cout << "* INIZIO STAMPA *" << endl;
	print_list(cout, my_list);
	cout << "* FINE STAMPA *" << endl;
	cout << "\nLa tua funzione 2 e' corretta se subito sopra, tra INIZIO STAMPA e FINE STAMPA, ha stampato: " << endl;
	cout << "1, Polpa Pronta Rica, subtotale 50" << endl;
    cout << "2, Olio Carli, subtotale 100" << endl;
    cout << "3, Dell cartoni, subtotale 150" << endl;
    cout << "FINE" << endl;
    
    cout << "\n*** FUNZIONE 3 *** " << endl;
    if (compute_total(my_list) == 366)
      cout << "il caso di test e' PASSATO" << endl;
    else
      cout << "il caso di test e' FALLITO" << endl;
    return 0;
}