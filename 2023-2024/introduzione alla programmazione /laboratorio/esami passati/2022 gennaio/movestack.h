struct Move {
  char cmd;
  Move *next;
};

typedef Move* MoveStack;

// Aggiungi in testa
void push(MoveStack & ms, char cmd);

// Leggi e rimuovi dalla testa
char pop(MoveStack & ms);

// Esegue mossa
void doMove(int &x, int&y, char cmd);
