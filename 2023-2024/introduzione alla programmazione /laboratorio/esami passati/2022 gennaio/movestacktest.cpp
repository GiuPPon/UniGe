#include <iostream>
#include <fstream>
#include <string>

#include "movestack.h"

void printpos(int x, int y)
{
  std::cout << "(" << x << ", "<< y <<")\n";
}
void doTest(std::string filename)
{
  std::ifstream pathFile(filename);
  int x = 0, y = 0;
  MoveStack path = nullptr;

  std::cout << "Inizio\n";
  printpos(x,y);
  while (!pathFile.eof()) {
	 char cmd = '\0';
    pathFile >> cmd;
	 if (cmd!='\0') {
	   switch (cmd) {
		  case 'N':
		  case 'S':
		  case 'E':
		  case 'W':
		    doMove(x, y, cmd);
			 std::cout << cmd << "  ";
			 printpos(x,y);
			 push(path, cmd);
			 break;
		  case 'B':
		    if (!path) {
			   std::cout << "TROPPI PASSI ALL'INDIETRO\n";
			 }
			 else {
			   int move = pop(path);
				std::cout << cmd << "  ";
				// invert move
				switch (move) {
				  case 'N': move = 'S'; break;
				  case 'S': move = 'N'; break;
				  case 'E': move = 'W'; break;
				  case 'W': move = 'E';
				}
				doMove(x, y, move);
				printpos(x,y);
			 }
		}
	 }
  }
  pathFile.close();
  std::cout << "Fine\n\n";
}

int main()
{
  std::cout << "Test percorso 1 (deve finire in (0, 0) )\n";
  doTest("path1");
  std::cout << "Test percorso 2 (deve finire in (2, 0) )\n";
  doTest("path2");
  std::cout << "Test percorso 3 (deve finire in (1, 0) )\n";
  doTest("path3");
}
