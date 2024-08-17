/* Definire un tipo struct Student per mantenere informazioni riguardanti uno studente, ed in 
particolare matricola, nome, cognome, data di nascita, voto medio.
[SUGGERIMENTO: Usate delle stringhe (tipo std::string) per rappresentare nome e cognome.]
Scrivere un programma che legga le informazioni relative ad almeno N studenti con N > 2, e le stampi
in ordine decrescente di età. [SUGGERIMENTO: Usate array di struct.] [ File students.cpp ] */

#include <iostream>
#include <string>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    int ID;
    string firstName;
    string lastName;
    Date birthDate;
    double averageGrade;
};

int main() {
    int N;
    cout << "Inserisci il numero di studenti (maggiore di 2): ";
    cin >> N;

    if (N <= 2) {
        cout << "Errore: Devono essere inseriti almeno 3 studenti." << endl;
        return 0;
    }

    Student students[N];

    for (int i = 0; i < N; ++i) {
        cout << "Studente " << i + 1 << ":" << endl;
        cout << "Matricola: ";
        cin >> students[i].ID;
        cout << "Nome: ";
        cin >> students[i].firstName;
        cout << "Cognome: ";
        cin >> students[i].lastName;
        cout << "Data di nascita (giorno, mese, anno): ";
        cin >> students[i].birthDate.day;
        cin >> students[i].birthDate.month;
        cin >> students[i].birthDate.year;
        cout << "Voto medio: ";
        cin >> students[i].averageGrade;
        cout << endl;
    }

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (students[j].birthDate.year < students[j + 1].birthDate.year ||
            (students[j].birthDate.year == students[j + 1].birthDate.year &&
             students[j].birthDate.month < students[j + 1].birthDate.month) ||
            (students[j].birthDate.year == students[j + 1].birthDate.year &&
             students[j].birthDate.month == students[j + 1].birthDate.month &&
             students[j].birthDate.day < students[j + 1].birthDate.day)) {

                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    cout << "Studenti in ordine decrescente di eta':" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Matricola: " << students[i].ID << endl;
        cout << "Nome: " << students[i].firstName << " " << students[i].lastName << endl;
        cout << "Data di nascita: " << students[i].birthDate.day << "/" << students[i].birthDate.month 
             << "/" << students[i].birthDate.year << endl;
        cout << "Voto medio: " << students[i].averageGrade << endl;
    }

    return 0;
}