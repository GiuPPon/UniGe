// File Main
// Compilare con g++ -Wall ASD-doubly-linked-list.cpp ASD-main-manual.cpp -o ASD-main-manual

// NON MODIFICARE QUESTO FILE

#include <iostream>
#include "ASD-doubly-linked-list.h"

using namespace std;
using namespace list;


int main(){
  List li;
  string old;
  bool resb;
  string res;
  string req_res;
  unsigned int resu;
  unsigned int req_resu;
  int resi;
  int req_resi;
  bool excep;

  unsigned i=1;
  cout<<"*************** Test "<<i<<": createEmpty ****************"<<endl;
  createEmpty(li);
  res=tostring(li);
  req_res="vuota";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: createEmpty(li)"<<endl;
    cout<<"  con li non inizializato"<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty ****************"<<endl;
  old=tostring(li);
  resb=isEmpty(li);
  if(resb) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: isEmpty(li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: "<<"true"<<endl;
    cout<<"  Risultato ottenuto: "<<resb<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": size ****************"<<endl;
  old=tostring(li);
  resu=size(li);
  req_resu=0;
  if(resu==req_resu) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: size(li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: "<<req_resu<<endl;
    cout<<"  Risultato ottenuto: "<<resu<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": add ****************"<<endl;
  old=tostring(li);
  add(0, 10,li);
  res=tostring(li);
  req_res="10";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: add(0, 10,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": size ****************"<<endl;
  old=tostring(li);
  resu=size(li);
  req_resu=1;
  if(resu==req_resu) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: size(li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: "<<req_resu<<endl;
    cout<<"  Risultato ottenuto: "<<resu<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": add ****************"<<endl;
  old=tostring(li);
  add(0, 20,li);
  res=tostring(li);
  req_res="20 <-> 10";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: add(0, 20,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;


  cout<<"*************** Test "<<i<<": add ****************"<<endl;
  old=tostring(li);
  add(2, 30,li);
  res=tostring(li);
  req_res="20 <-> 10 <-> 30";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: add(2, 30,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": size ****************"<<endl;
  old=tostring(li);
  resu=size(li);
  req_resu=3;
  if(resu==req_resu) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: size(li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: "<<req_resu<<endl;
    cout<<"  Risultato ottenuto: "<<resu<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": add ****************"<<endl;
  old=tostring(li);
  add(1, 40,li);
  res=tostring(li);
  req_res="20 <-> 40 <-> 10 <-> 30";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: add(1, 40,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": add ****************"<<endl;
  old=tostring(li);
  add(3, 50,li);
  res=tostring(li);
  req_res="20 <-> 40 <-> 10 <-> 50 <-> 30";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: add(3, 50,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": size ****************"<<endl;
  old=tostring(li);
  resu=size(li);
  req_resu=5;
  if(resu==req_resu) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: size(li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: "<<req_resu<<endl;
    cout<<"  Risultato ottenuto: "<<resu<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": clear ****************"<<endl;
  old=tostring(li);
  clear(li);
  res=tostring(li);
  req_res="vuota";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: clear(li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addRear ****************"<<endl;
  old=tostring(li);
  addRear(10,li);
  res=tostring(li);
  req_res="10";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: addRear(10,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addRear ****************"<<endl;
  old=tostring(li);
  addRear(20,li);
  res=tostring(li);
  req_res="10 <-> 20";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: addRear(20,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addRear ****************"<<endl;
  old=tostring(li);
  addRear(5,li);
  res=tostring(li);
  req_res="10 <-> 20 <-> 5";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: addRear(5,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addRear ****************"<<endl;
  old=tostring(li);
  addRear(-1,li);
  res=tostring(li);
  req_res="10 <-> 20 <-> 5 <-> -1";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: addRear(-1,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addFront ****************"<<endl;
  old=tostring(li);
  addFront(0,li);
  res=tostring(li);
  req_res="0 <-> 10 <-> 20 <-> 5 <-> -1";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: addFront(0,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addFront ****************"<<endl;
  old=tostring(li);
  addFront(100,li);
  res=tostring(li);
  req_res="100 <-> 0 <-> 10 <-> 20 <-> 5 <-> -1";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: addFront(100,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": size ****************"<<endl;
  old=tostring(li);
  resu=size(li);
  req_resu=6;
  if(resu==req_resu) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: size(li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: "<<req_resu<<endl;
    cout<<"  Risultato ottenuto: "<<resu<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": clear ****************"<<endl;
  old=tostring(li);
  clear(li);
  res=tostring(li);
  req_res="vuota";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: clear(li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addFront ****************"<<endl;
  old=tostring(li);
  addFront(15,li);
  res=tostring(li);
  req_res="15";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: addFront(15,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addFront ****************"<<endl;
  old=tostring(li);
  addFront(-2,li);
  res=tostring(li);
  req_res="-2 <-> 15";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: addFront(-2,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addFront ****************"<<endl;
  old=tostring(li);
  addFront(20,li);
  res=tostring(li);
  req_res="20 <-> -2 <-> 15";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: addFront(20,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addFront ****************"<<endl;
  old=tostring(li);
  addFront(100,li);
  res=tostring(li);
  req_res="100 <-> 20 <-> -2 <-> 15";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: addFront(100,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addFront ****************"<<endl;
  old=tostring(li);
  addFront(100,li);
  res=tostring(li);
  req_res="100 <-> 100 <-> 20 <-> -2 <-> 15";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: addFront(100,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": removePos ****************"<<endl;
  old=tostring(li);
  removePos(0,li);
  res=tostring(li);
  req_res="100 <-> 20 <-> -2 <-> 15";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removePos(0,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": removePos ****************"<<endl;
  old=tostring(li);
  removePos(3,li);
  res=tostring(li);
  req_res="100 <-> 20 <-> -2";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removePos(3,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": removePos ****************"<<endl;
  old=tostring(li);
  removePos(1,li);
  res=tostring(li);
  req_res="100 <-> -2";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removePos(1,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": removeEl ****************"<<endl;
  old=tostring(li);
  removeEl(50,li);
  res=tostring(li);
  req_res="100 <-> -2";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removeEl(50,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": removeEl ****************"<<endl;
  old=tostring(li);
  removeEl(100,li);
  res=tostring(li);
  req_res="-2";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removeEl(100,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": removeEl ****************"<<endl;
  old=tostring(li);
  removeEl(-2,li);
  res=tostring(li);
  req_res="vuota";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removeEl(-2,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  addFront(10,li);
  addFront(10,li);
  addFront(5,li);
  addFront(5,li);
  addFront(15,li);
  addFront(5,li);
  addFront(20,li);
  addFront(5,li);
  addFront(5,li);
  addFront(25,li);
  addFront(35,li);
  addFront(45,li);
  addFront(30,li);
  addFront(30,li);
  addFront(30,li);
  addFront(55,li);

  cout<<"*************** Test "<<i<<": removeEl ****************"<<endl;
  old=tostring(li);
  removeEl(55,li);
  res=tostring(li);
  req_res="30 <-> 30 <-> 30 <-> 45 <-> 35 <-> 25 <-> 5 <-> 5 <-> 20 <-> 5 <-> 15 <-> 5 <-> 5 <-> 10 <-> 10";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removeEl(55,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": removeEl ****************"<<endl;
  old=tostring(li);
  removeEl(20,li);
  res=tostring(li);
  req_res="30 <-> 30 <-> 30 <-> 45 <-> 35 <-> 25 <-> 5 <-> 5 <-> 5 <-> 15 <-> 5 <-> 5 <-> 10 <-> 10";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removeEl(20,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": removeEl ****************"<<endl;
  old=tostring(li);
  removeEl(5,li);
  res=tostring(li);
  req_res="30 <-> 30 <-> 30 <-> 45 <-> 35 <-> 25 <-> 15 <-> 10 <-> 10";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removeEl(5,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": removeEl ****************"<<endl;
  old=tostring(li);
  removeEl(10,li);
  res=tostring(li);
  req_res="30 <-> 30 <-> 30 <-> 45 <-> 35 <-> 25 <-> 15";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removeEl(10,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": removeEl ****************"<<endl;
  old=tostring(li);
  removeEl(30,li);
  res=tostring(li);
  req_res="45 <-> 35 <-> 25 <-> 15";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removeEl(30,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": get ****************"<<endl;
  old=tostring(li);
  resi=get(0,li);
  req_resi=45;
  if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: get(0,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: "<<req_resi<<endl;
    cout<<"  Risultato ottenuto: "<<resi<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": get ****************"<<endl;
  old=tostring(li);
  resi=get(3,li);
  req_resi=15;
  if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: get(3,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: "<<req_resi<<endl;
    cout<<"  Risultato ottenuto: "<<resi<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": get ****************"<<endl;
  old=tostring(li);
  resi=get(1,li);
  req_resi=35;
  if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: get(1,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: "<<req_resi<<endl;
    cout<<"  Risultato ottenuto: "<<resi<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": get ****************"<<endl;
  old=tostring(li);
  resi=get(2,li);
  req_resi=25;
  if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: get(2,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: "<<req_resi<<endl;
    cout<<"  Risultato ottenuto: "<<resi<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": set ****************"<<endl;
  old=tostring(li);
  set(0,100,li);
  res=tostring(li);
  req_res="100 <-> 35 <-> 25 <-> 15";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: set(0,100,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": set ****************"<<endl;
  old=tostring(li);
  set(3,200,li);
  res=tostring(li);
  req_res="100 <-> 35 <-> 25 <-> 200";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: set(0,100,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": set ****************"<<endl;
  old=tostring(li);
  set(1,300,li);
  res=tostring(li);
  req_res="100 <-> 300 <-> 25 <-> 200";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: set(0,100,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": set ****************"<<endl;
  old=tostring(li);
  set(2,400,li);
  res=tostring(li);
  req_res="100 <-> 300 <-> 400 <-> 200";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: set(0,100,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": removePos ****************"<<endl;
  old=tostring(li);
  removePos(0,li);
  res=tostring(li);
  req_res="300 <-> 400 <-> 200";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removePos(0,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": removePos ****************"<<endl;
  old=tostring(li);
  removePos(0,li);
  res=tostring(li);
  req_res="400 <-> 200";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removePos(0,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": set ****************"<<endl;
  old=tostring(li);
  set(0,50,li);
  res=tostring(li);
  req_res="50 <-> 200";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: set(0,50,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": set ****************"<<endl;
  old=tostring(li);
  set(1,-50,li);
  res=tostring(li);
  req_res="50 <-> -50";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: set(1,-50,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": removePos ****************"<<endl;
  old=tostring(li);
  removePos(0,li);
  res=tostring(li);
  req_res="-50";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removePos(0,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": set ****************"<<endl;
  old=tostring(li);
  set(0,1,li);
  res=tostring(li);
  req_res="1";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: set(0,1,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": set ****************"<<endl;
  old=tostring(li);
  set(0,1,li);
  res=tostring(li);
  req_res="1";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: set(0,1,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato li="<<req_res<<endl;
    cout<<"  Risultato ottenuto li="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": set ****************"<<endl;
  old=tostring(li);
  excep=false;
  try{
    set(1,10,li);
  }
  catch(string exc){
    excep=true;
  }
  if(excep) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: set(1,10,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: Exception"<<endl;
  }
  cout<<endl;
  ++i;

  clear(li);
  addFront(5,li);

  cout<<"*************** Test "<<i<<": get ****************"<<endl;
  old=tostring(li);
  excep=false;
  try{
    resi=get(1,li);
  }
  catch(string exc){
    excep=true;
  }
  if(excep) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: get(1,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: Exception"<<endl;
  }
  cout<<endl;
  ++i;

  clear(li);
  addFront(5,li);

  cout<<"*************** Test "<<i<<": add ****************"<<endl;
  old=tostring(li);
  excep=false;
  try{
    add(2,10,li);
  }
  catch(string exc){
    excep=true;
  }
  if(excep) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: add(2,10,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: Exception"<<endl;
  }
  cout<<endl;
  ++i;

  clear(li);
  addFront(20,li);

  cout<<"*************** Test "<<i<<": removePos ****************"<<endl;
  old=tostring(li);
  excep=false;
  try{
    removePos(1,li);
  }
  catch(string exc){
    excep=true;
  }
  if(excep) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removePos(1,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: Exception"<<endl;
  }
  cout<<endl;
  ++i;

  clear(li);
  addFront(1,li);
  addFront(2,li);
  addFront(3,li);
  addFront(4,li);
  addFront(5,li);
  addFront(6,li);

  cout<<"*************** Test "<<i<<": set ****************"<<endl;
  old=tostring(li);
  excep=false;
  try{
    set(6,10,li);
  }
  catch(string exc){
    excep=true;
  }
  if(excep) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: set(6,10,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: Exception"<<endl;
  }
  cout<<endl;
  ++i;

  clear(li);
  addFront(1,li);
  addFront(2,li);
  addFront(3,li);
  addFront(4,li);
  addFront(5,li);
  addFront(6,li);

  cout<<"*************** Test "<<i<<": get ****************"<<endl;
  old=tostring(li);
  excep=false;
  try{
    resi=get(6,li);
  }
  catch(string exc){
    excep=true;
  }
  if(excep) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: get(6,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: Exception"<<endl;
  }
  cout<<endl;
  ++i;

  clear(li);
  addFront(1,li);
  addFront(2,li);
  addFront(3,li);
  addFront(4,li);
  addFront(5,li);
  addFront(6,li);

  cout<<"*************** Test "<<i<<": add ****************"<<endl;
  old=tostring(li);
  excep=false;
  try{
    add(7,10,li);
  }
  catch(string exc){
    excep=true;
  }
  if(excep) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: add(7,10,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: Exception"<<endl;
  }
  cout<<endl;
  ++i;

  clear(li);
  addFront(1,li);
  addFront(2,li);
  addFront(3,li);
  addFront(4,li);
  addFront(5,li);
  addFront(6,li);

  cout<<"*************** Test "<<i<<": removePos ****************"<<endl;
  old=tostring(li);
  excep=false;
  try{
    removePos(6,li);
  }
  catch(string exc){
    excep=true;
  }
  if(excep) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: removePos(6,li)"<<endl;
    cout<<"  con li="<<old<<endl;
    cout<<"  Risultato aspettato: Exception"<<endl;
  }
  cout<<endl;
}
