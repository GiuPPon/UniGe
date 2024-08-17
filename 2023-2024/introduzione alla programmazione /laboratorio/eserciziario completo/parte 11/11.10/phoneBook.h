#ifndef phoneBook_H
#define phoneBook_H

#include <vector>
#include <string>
using namespace std;

struct contact{
    string surname;
    string name;
    string phoneNumber;
};
typedef vector<contact> phoneBook;

void push_contact_in_phoneBook(phoneBook &B, string surname, string name, string number);
void print_phoneBook(const phoneBook &B);
void read_phoneBook_from_file(phoneBook &B, string fileName);
void write_phoneBook_to_file(const phoneBook &B, string fileName);
void sort_phoneBook_by_surnames(phoneBook &B);
bool find_phoneBook_contact_by_surname(const phoneBook &B, string s, unsigned long int &pos);
void shift_phoneBook(phoneBook &B, unsigned long int pos);
void add_contact_to_phoneBook(phoneBook &B, string surname, string name, string number);

#endif