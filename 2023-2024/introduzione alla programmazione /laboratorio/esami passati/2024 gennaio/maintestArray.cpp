#include <iostream>
#include "array.h"
using namespace std;

////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
 */

std::string printArray(int* arrayInteri, unsigned int size) {
	std::string out = "[";
	for (unsigned int i = 0; i < size; i++) {
	if (i > 0) out = out + ",";
	out = out + std::to_string(arrayInteri[i]);
  }
  out += "]";
  return out;
}


//////////////////////////////////////////////////////////////////////////// 
// funzione utilizzata per test **non modificare**
/* confronta due array della stessa size
*/

bool compareArray(int* nums1, int* nums2, unsigned int size)
{
	bool res = true;
	if (size > 0)
		for(unsigned int i = 0 ; i <= size-1 ; i++)
		{
		   res = res & (nums1[i] == nums2[i]);
		}
	return res;
}



////////////////////////////////////////////////////////////////////////////
// funzione utilizzata per test **non modificare**
bool testResult(std::string s1, std::string s2) { return s1 == s2; }

////////////////////////////////////////////////////////////////////////////
// main utilizzato per test **non modificare**
int main() {
  int scelta;
  cout << endl
	   << " Quale funzione vuoi testare. Digita un numero:\n\n"
	   << " 1 per testare arrayContainsFibonacciSeries(...)\n"
	   << " 2 per testare reverseArray(...)\n"
	   << " 3 per testare findEquilibriumIndex(...)\n\n"
	   << " Inserisci un numero e premi invio: ";
  cin >> scelta;

  switch (scelta) {
  case 1: {

	cout << std::boolalpha;

	cout << "\n";
	cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
	cout << "\n*** TEST arrayContainsFibonacciSeries(...)  *****";
	cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

	cout << "\n";
	cout << "\n!!!! ATTENZIONE: 10 TEST DA SUPERARE !!!!";
	int nTest = 1;

	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 0 elementi	******";
		cout << "\n--------------------------------------";
		
		string res1, res2 = "";
		unsigned int size;
		
		int array[] = {0}; // array di interi statico
		size = 0;

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nLa funzione deve ritornare TRUE in quanto l'array è vuoto";
		cout << "\nIl test e' superato? "
				"================================> "
			 << (arrayContainsFibonacciSeries(array,size) == true);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n---------------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 1 elementi (positivo) ******";
		cout << "\n---------------------------------------------";
		
		string res1, res2 = "";
		unsigned int size;
		
		int array[] = {0}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nLa funzione deve ritornare TRUE in quanto l'array rappresenta una serie di Fibonacci";
		cout << "\nIl test e' superato? "
				"================================> "
			 << (arrayContainsFibonacciSeries(array,size) == true);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n---------------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 1 elementi (negativo) ******";
		cout << "\n---------------------------------------------";

		string res1, res2 = "";
		unsigned int size;
		
		int array[] = {1}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nLa funzione deve ritornare FALSE in quanto l'array NON rappresenta una serie di Fibonacci";
		cout << "\nIl test e' superato? "
				"================================> "
			 << (arrayContainsFibonacciSeries(array,size) == false);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n---------------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 2 elementi (positivo) ******";
		cout << "\n---------------------------------------------";
		string res1, res2 = "";
		unsigned int size;
		int array[] = {0,1}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nLa funzione deve ritornare TRUE in quanto l'array rappresenta una serie di Fibonacci";
		cout << "\nIl test e' superato? "
				"================================> "
			 << (arrayContainsFibonacciSeries(array,size) == true);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n---------------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 2 elementi (negativo) ******";
		cout << "\n---------------------------------------------";
		string res1, res2 = "";
		unsigned int size;
		int array[] = {1,1}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nLa funzione deve ritornare FALSE in quanto l'array NON rappresenta una serie di Fibonacci";
		cout << "\nIl test e' superato? "
				"================================> "
			 << (arrayContainsFibonacciSeries(array,size) == false);
			 
	}
nTest++;
	{
		cout << "\n";
		cout << "\n---------------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array N elementi (positivo) ******";
		cout << "\n---------------------------------------------";
		string res1, res2 = "";
		unsigned int size;
		int array[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nLa funzione deve ritornare TRUE in quanto l'array rappresenta una serie di Fibonacci";
		cout << "\nIl test e' superato? "
				"================================> "
			 << (arrayContainsFibonacciSeries(array,size) == true);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n---------------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array N elementi (negativo1) ******";
		cout << "\n---------------------------------------------";
		string res1, res2 = "";
		unsigned int size;
		int array[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 9999, 233, 377, 610, 987, 1597, 2584, 4181, 6765}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nLa funzione deve ritornare FALSE in quanto l'array NON rappresenta una serie di Fibonacci";
		cout << "\nIl test e' superato? "
				"================================> "
			 << (arrayContainsFibonacciSeries(array,size) == false);
 	}
nTest++;
	{
		cout << "\n";
		cout << "\n---------------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array N elementi (negativo2) ******";
		cout << "\n---------------------------------------------";
		string res1, res2 = "";
		unsigned int size;
		int array[] = {9999, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nLa funzione deve ritornare FALSE in quanto l'array NON rappresenta una serie di Fibonacci";
		cout << "\nIl test e' superato? "
				"================================> "
			 << (arrayContainsFibonacciSeries(array,size) == false);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n---------------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array N elementi (negativo3) ******";
		cout << "\n---------------------------------------------";
		string res1, res2 = "";
		unsigned int size;
		int array[] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 9999}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nLa funzione deve ritornare FALSE in quanto l'array NON rappresenta una serie di Fibonacci";
		cout << "\nIl test e' superato? "
				"================================> "
			 << (arrayContainsFibonacciSeries(array,size) == false);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n---------------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array N elementi (negativo4) ******";
		cout << "\n---------------------------------------------";
		string res1, res2 = "";
		unsigned int size;
		int array[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nLa funzione deve ritornare FALSE in quanto l'array NON rappresenta una serie di Fibonacci";
		cout << "\nIl test e' superato? "
				"================================> "
			 << (arrayContainsFibonacciSeries(array,size) == false);
	}
	cout << "\n";
	cout << "\n*****   TEST della FUNZIONE CONCLUSI  ******";
	cout << "\n";
	break;
  }

  case 2: {
	cout << std::boolalpha;

	cout << "\n";
	cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
	cout << "\n*** TEST reverseArray(...)  *****";
	cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

	cout << "\n";
	cout << "\n!!!! ATTENZIONE: 5 TEST DA SUPERARE !!!!";
	int nTest = 1;
	
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 0 elementi	******";
		cout << "\n--------------------------------------";
		string res1, res2 = "";
		unsigned int size;
		int array[] = {0}; // array di interi statico
		int arrayexp[] = {0}; // array di interi statico
		size = 0;

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nEseguo la funzione";
		reverseArray(array,size);
		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nIl test e' superato? ================================> "
			 << compareArray(array, arrayexp, size);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n---------------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 1 elementi ******";
		cout << "\n---------------------------------------------";
		string res1, res2 = "";
		unsigned int size;
		int array[] = {34}; // array di interi statico
		int arrayexp[] = {34}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nEseguo la funzione";
		reverseArray(array,size);
		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nIl test e' superato? ================================> "
			 << compareArray(array, arrayexp, size);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n---------------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array N dispari elementi ******";
		cout << "\n---------------------------------------------";
		string res1, res2 = "";
		unsigned int size;
		int array[] = {1,5,7}; // array di interi statico
		int arrayexp[] = {7,5,1}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nEseguo la funzione";
		reverseArray(array,size);
		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nIl test e' superato? ================================> "
			 << compareArray(array, arrayexp, size);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n---------------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array N pari elementi ******";
		cout << "\n---------------------------------------------";
		string res1, res2 = "";
		unsigned int size;
		int array[] = {1,5,7,23}; // array di interi statico
		int arrayexp[] = {23,7,5,1}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nEseguo la funzione";
		reverseArray(array,size);
		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nIl test e' superato? ================================> "
			 << compareArray(array, arrayexp, size);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n---------------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array N (grande) elementi ******";
		cout << "\n---------------------------------------------";
		string res1, res2 = "";
		unsigned int size;
		int array[] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765}; // array di interi statico
		int arrayexp[] = {6765,4181,2584,1597,987,610,377,233,144,89,55,34,21,13,8,5,3,2,1,1,0}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nEseguo la funzione";
		reverseArray(array,size);
		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		cout << "\nIl test e' superato? ================================> "
			 << compareArray(array, arrayexp, size);
	}
	cout << "\n";
	cout << "\n*****   TEST della FUNZIONE CONCLUSI  ******";
	cout << "\n";
	break;
  }
  
  case 3: {
	cout << std::boolalpha;

	cout << "\n";
	cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
	cout << "\n*** TEST findEquilibriumIndex(...)  *****";
	cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

	cout << "\n";
	cout << "\n!!!! ATTENZIONE: 14 TEST DA SUPERARE !!!!";
	int nTest = 1;
	
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 0 elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {0}; // array di interi statico
		size = 0;

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == -1);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 1 elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {5}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == 0);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 2 elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {2,2}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == -1);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 2 elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {0,0}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == 0);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 3 elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {1,2,1}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == 1);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 3 elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {1,2,3}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == -1);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 3 elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {0,0,0}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == 0);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 4 elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {1,2,2,1}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == -1);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 4 elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {0,0,0,0}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == 0);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 4 elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {1,0,0,0}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == 0);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 4 elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {0,1,0,0}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == 1);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 4 elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {0,0,1,0}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == 2);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array 4 elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {0,0,0,1}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == 3);
	}
nTest++;
	{
		cout << "\n";
		cout << "\n--------------------------------------";
		cout << "\n*****  TEST " << nTest << " Array N (dispari) elementi	******";
		cout << "\n--------------------------------------";
		string res1 = "";
		int out = 0;
		unsigned int size;
		int array[] = {-7, 1, 5, 2, -4, 3, 0}; // array di interi statico
		size = sizeof(array) / sizeof(array[0]);

		res1 = printArray(array, size);
		cout << "\nIl contenuto dell'array e': " << res1;
		out = findEquilibriumIndex(array,size);
		cout << "\nEseguo la funzione: il risultato restituito e': " << out;
		cout << "\nIl test e' superato? ================================> "
			 << (out == 3);
	}
	cout << "\n";
	cout << "\n*****   TEST della FUNZIONE CONCLUSI  ******";
	cout << "\n";
	break;
  }

 

  default: {
	cout << "Scelta NON valida \n";
	break;
  }
  }

  return 0;
}