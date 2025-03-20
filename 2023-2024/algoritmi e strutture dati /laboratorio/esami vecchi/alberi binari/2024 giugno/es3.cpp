#include "trinary-tree.h"

using namespace std;

std::string leavesToString(const triTree& tr){

  if (tr == nullptr) {
    return ""; // Se il nodo è nullo, ritorna 0
  }

  string result = "";

  if (tr -> child1 != nullptr) {
    leavesToString(tr -> child1);
  } 

  if (tr -> child2 != nullptr) {
    leavesToString(tr -> child2);
  } 

  if (tr -> child3 != nullptr) {
    leavesToString(tr -> child3);
  } 

  result += to_string(tr -> el);

  return result;
  
}

