#include <iostream>
#include "bow.h"
#include "movestack.h"
using namespace std;

void add ( BagOfWords & b , std :: string w ) {
    bool found = false;
    for (unsigned int i = 0; i < b.size(); ++i) {
        if (b[i].word == w) {
            ++b[i].num;
            found = true;
        }
    }
    if (!found) {
        Entry newEntry;
        newEntry.num = 1;
        newEntry.word = w;
        b.push_back(newEntry);
    }
}

void del ( BagOfWords & b, string w ) {
    unsigned int count = 0;
    for (unsigned int i = 0; i < b.size(); ++i) {
        if (b[i].word == w && b[i].num > 1) {
            --b[i].num;
        } else if (b[i].word == w && b[i].num == 1) {
            for (int k = i; k < b.size(); ++k) {
                b[k].word = b[k + 1].word;
            }
            b.pop_back();
        }
    }
}

int count ( const BagOfWords & b , std :: string w ) {
    for (unsigned int i = 0; i < b.size(); ++i) {
        if (b[i].word == w) {
            return b[i].num;
        }
    }
    return 0;
}

void push ( MoveStack & ms , char cmd ) {
    Move *command = new Move;
    command -> cmd = cmd;
    command -> next = ms;
    ms = command;
}

char pop ( MoveStack & ms ) {
    Move *cur = ms;
    char move = cur -> cmd;
    ms = cur -> next;
    delete cur;
    return move;
}

void doMove (int &x , int &y , char cmd ) {
    MoveStack commands = nullptr;
    switch (cmd) {
        case 'N': 
            --y;
            push(commands, cmd);
            break;
        case 'S':
            ++y; 
            push(commands, cmd);
            break;
        case 'W':
            --x;
            push(commands, cmd);
            break;
        case 'E':
            ++x;
            push(commands, cmd);
            break;
        case 'B':
            pop(commands);
            break;
        default: 
            break;
    }
}
