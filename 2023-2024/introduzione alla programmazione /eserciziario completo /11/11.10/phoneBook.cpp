#include "phoneBook.h"
#include <iostream>
#include <fstream>
using namespace std;

void push_contact_in_phoneBook(phoneBook &B, string surname, string name, string number) {
    contact C = {surname, name, number};
    B.push_back(C);
}

void print_phoneBook(const phoneBook &B) {
    for (unsigned long i = 0; i < B.size(); i++) {
        cout << B[i].surname << " " << B[i].name << " " << B[i].phoneNumber << endl;
    }
}

void read_phoneBook_from_file(phoneBook &B, string fileName) {
    ifstream infile;
    infile.open(fileName);
    string data;
    infile >> data;
    int num = stoi(data);
    for (int i = 0; i < num; ++i) {
        contact contatto;
        infile >> contatto.surname;
        infile >> contatto.name;
        infile >> contatto.phoneNumber;
        B.push_back(contatto);
    }
    infile.close();
}

void write_phoneBook_to_file(const phoneBook &B, string fileName) {
    ofstream outfile;
    outfile.open(fileName);
    outfile << B.size() << endl;
    for (unsigned long i = 0; i < B.size(); ++i) {
        outfile << B.at(i).surname << " " << B.at(i).name << " " << B.at(i).phoneNumber << endl;
    }
    outfile.close();
}

void sort_phoneBook_by_surnames(phoneBook &B) {
    for (unsigned int i = 0; i < B.size() - 1; i++) {
        for (unsigned int j = i + 1; j < B.size(); j++) {
            if ( B[i].surname > B[j].surname ) {
            swap(B[i].surname, B[j].surname);
            swap(B[i].name, B[j].name);
            swap(B[i].phoneNumber, B[j].phoneNumber);
            }
        }
    }
}

bool find_phoneBook_contact_by_surname(const phoneBook &B, string s, unsigned long int &pos) {
    pos = B.size();
    int left = 0;
    int right = B.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (B[mid].surname == s) {
            pos = mid;
            return true;
        } else if (B[mid].surname < s) {
            left = mid + 1;
        } else {
            pos = mid;
            right = mid - 1;
        }
    }
    return false;
}

void shift_phoneBook(phoneBook &B, unsigned long int pos) {
    if (pos < B.size()) {
        B.push_back(B.back()); 
        for (unsigned long int i = B.size() - 1; i > pos; --i) {
            B[i] = B[i - 1]; 
        }   
    }
    B.pop_back();
}

void add_contact_to_phoneBook(phoneBook &B, string surname, string name, string number) {
    sort_phoneBook_by_surnames(B); 
    unsigned long int pos;
    if (find_phoneBook_contact_by_surname(B, surname, pos)) {
        shift_phoneBook(B, pos); 
        B[pos] = {surname, name, number}; 
    } else {
        push_contact_in_phoneBook(B, surname, name, number); 
    }
}