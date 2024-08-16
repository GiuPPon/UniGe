#include "phoneBook.h"
#include <iostream>

int main () {
    phoneBook namePhoneBook;

    push_contact_in_phoneBook(namePhoneBook, "Einstein", "Albert", "012334454");
    push_contact_in_phoneBook(namePhoneBook, "Tesla", "Nikola", "088388831");
    push_contact_in_phoneBook(namePhoneBook, "Gauss", "Carl-Friedrich", "03966776111");

    cout << "Rubrica iniziale: " << endl;
    print_phoneBook(namePhoneBook);
    cout << "\n";

    sort_phoneBook_by_surnames(namePhoneBook);

    cout << "Rubrica ordinata per cognome:" << endl;
    print_phoneBook(namePhoneBook);
    cout << "\n";

    string searchSurname;
    cout << "Inserire contatto da cercare: ";
    cin >> searchSurname;

    unsigned long int pos;
    if (find_phoneBook_contact_by_surname(namePhoneBook, searchSurname, pos)) {
        cout << "Il contatto con cognome " << searchSurname << " si trova alla posizione " << pos << endl;
    } else {
        cout << "Contatto con cognome " << searchSurname << " non trovato." << endl;
    }
    cout << "\n";

    cout << "Rubrica prima di shift:" << endl;
    print_phoneBook(namePhoneBook);
    
    unsigned long int posizione;
    cout << "Inserire posizione in cui eseguire lo shift: ";
    cin >> posizione;

    shift_phoneBook(namePhoneBook, posizione);
    print_phoneBook(namePhoneBook);
    cout << "\n";

    add_contact_to_phoneBook(namePhoneBook, "Fibonacci", "Leonardo", "11235813");

    cout << "Rubrica aggiornata: " << endl;
    print_phoneBook(namePhoneBook);
    cout << "\n";

    write_phoneBook_to_file(namePhoneBook, "fileName.txt");

    read_phoneBook_from_file(namePhoneBook, "fileName.txt");

    cout << "Rubrica letta da file:" << endl;
    print_phoneBook(namePhoneBook);
    cout << "\n";
}