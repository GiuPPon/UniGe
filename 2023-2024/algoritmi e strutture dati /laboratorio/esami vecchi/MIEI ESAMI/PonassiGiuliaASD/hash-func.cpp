/*NON MODIFICARE*/
#include "double-hash.h"

unsigned int h1(Elem el){
  return el%10;
}

unsigned int h2(Elem el){
  return (el/10)%10;
}
