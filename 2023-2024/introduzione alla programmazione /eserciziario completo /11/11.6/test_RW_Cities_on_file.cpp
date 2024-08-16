#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

struct city {
    string name;
    int inhabitants;
};
typedef vector<city> cities;

void write_cities_to_file(cities &C, string fileName) {
    ifstream infile;
    infile.open(fileName);
    string data;
    infile >> data;
    int num = stoi(data); // per trasformare il contenuto di una stringa (che rappresenta un int) in un int
    for (int i = 0; i < num; ++i) {
        city c;
        infile >> c.name >> c.inhabitants;
        C.push_back(c); // ?????
    }
    infile.close();
}

void read_cities_to_file(cities &C, string fileName) {
    ofstream outfile;
    outfile.open("citiesToRead.txt");
    outfile << C.size() << endl;
    for (unsigned long i = 0; i < C.size(); ++i) {
        outfile << C.at(i).name << " " << C.at(i).inhabitants << endl;
    }
    outfile.close();
}

int main () {
    cities C;
    read_cities_to_file(C,"citiesToRead.txt");
    write_cities_to_file(C,"citiesToWrite.txt");
}