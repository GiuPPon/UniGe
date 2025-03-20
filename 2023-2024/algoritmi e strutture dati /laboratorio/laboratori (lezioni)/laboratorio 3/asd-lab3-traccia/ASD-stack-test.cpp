// File Main
// Compilare con g++ -Wall ASD-stack-array.cpp ASD-stack-test.cpp -o ASD-stack-test

// NON MODIFICARE QUESTO FILE

#include <iostream>
#include "ASD-stack-array.h"

using namespace std;
using namespace stack;

int main(){
  Stack st;
  string old,req_res,res;
  bool resb,excep;
  Elem rese, req_rese;
  cout << boolalpha;

  unsigned i=1;
  cout<<"*************** Test "<<i<<": createEmpty ****************"<<endl;
  st=createEmpty();
  res=tostring(st);
  req_res="{}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: st=createEmpty()"<<endl;
    cout<<"  Risultato aspettato st="<<req_res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty ****************"<<endl;
  old=tostring(st);
  resb=isEmpty(st);
  if(resb) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: isEmpty(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato: "<<"true"<<endl;
    cout<<"  Risultato ottenuto: "<<resb<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": push ****************"<<endl;
  old=tostring(st);
  push(1,st);
  res=tostring(st);
  req_res="{1}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: push(1,st)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato st="<<req_res<<endl;
    cout<<"  Risultato ottenuto st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty ****************"<<endl;
  old=tostring(st);
  resb=isEmpty(st);
  if(!resb) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: isEmpty(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato: "<<"false"<<endl;
    cout<<"  Risultato ottenuto: "<<resb<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": push ****************"<<endl;
  old=tostring(st);
  push(2,st);
  res=tostring(st);
  req_res="{1,2}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: push(2,st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato st="<<req_res<<endl;
    cout<<"  Risultato ottenuto st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty ****************"<<endl;
  old=tostring(st);
  resb=isEmpty(st);
  if(!resb) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: isEmpty(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato: "<<"false"<<endl;
    cout<<"  Risultato ottenuto: "<<resb<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": push ****************"<<endl;
  old=tostring(st);
  push(3,st);
  res=tostring(st);
  req_res="{1,2,3}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: push(3,st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato st="<<req_res<<endl;
    cout<<"  Risultato ottenuto st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=3;
  res=tostring(st);
  req_res="{1,2}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;


  cout<<"*************** Test "<<i<<": isEmpty ****************"<<endl;
  old=tostring(st);
  resb=isEmpty(st);
  if(!resb) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: isEmpty(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato: "<<"false"<<endl;
    cout<<"  Risultato ottenuto: "<<resb<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": push ****************"<<endl;
  old=tostring(st);
  push(4,st);
  res=tostring(st);
  req_res="{1,2,4}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: push(4,st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato st="<<req_res<<endl;
    cout<<"  Risultato ottenuto st="<<res<<endl;
  }
  cout<<endl;
  ++i;


  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=4;
  res=tostring(st);
  req_res="{1,2}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": top ****************"<<endl;
  old=tostring(st);
  rese=top(st);
  req_rese=2;
  res=tostring(st);
  req_res="{1,2}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: top(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=2;
  res=tostring(st);
  req_res="{1}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": top ****************"<<endl;
  old=tostring(st);
  rese=top(st);
  req_rese=1;
  res=tostring(st);
  req_res="{1}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: top(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=1;
  res=tostring(st);
  req_res="{}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty ****************"<<endl;
  old=tostring(st);
  resb=isEmpty(st);
  if(resb) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: isEmpty(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato: "<<"true"<<endl;
    cout<<"  Risultato ottenuto: "<<resb<<endl;
  }
  cout<<endl;
  ++i;
  

  push(10,st);
  push(15,st);
  push(20,st);
  push(25,st);
  push(30,st);
  push(35,st);
  push(40,st);
  push(45,st);
  push(50,st);
  push(55,st);

  cout<<"*************** Test "<<i<<": push ****************"<<endl;
  old=tostring(st);
  push(60,st);
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: push(60,st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato st="<<req_res<<endl;
    cout<<"  Risultato ottenuto st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": push ****************"<<endl;
  old=tostring(st);
  push(65,st);
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: push(65,st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato st="<<req_res<<endl;
    cout<<"  Risultato ottenuto st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": push ****************"<<endl;
  old=tostring(st);
  push(70,st);
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: push(70,st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato st="<<req_res<<endl;
    cout<<"  Risultato ottenuto st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  push(75,st);
  push(80,st);
  push(85,st);
  push(90,st);
  push(95,st);
  push(100,st);
  push(105,st);

  cout<<"*************** Test "<<i<<": push ****************"<<endl;
  old=tostring(st);
  push(110,st);
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: push(110,st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato st="<<req_res<<endl;
    cout<<"  Risultato ottenuto st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": top ****************"<<endl;
  old=tostring(st);
  rese=top(st);
  req_rese=110;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: top(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=110;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": top ****************"<<endl;
  old=tostring(st);
  rese=top(st);
  req_rese=105;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: top(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=105;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": top ****************"<<endl;
  old=tostring(st);
  rese=top(st);
  req_rese=100;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: top(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=100;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": top ****************"<<endl;
  old=tostring(st);
  rese=top(st);
  req_rese=95;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: top(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=95;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=90;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=85;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70,75,80}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": top ****************"<<endl;
  old=tostring(st);
  rese=top(st);
  req_rese=80;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70,75,80}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: top(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=80;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70,75}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=75;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65,70}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=70;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": top ****************"<<endl;
  old=tostring(st);
  rese=top(st);
  req_rese=65;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60,65}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: top(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=65;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55,60}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=60;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50,55}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=55;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45,50}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=50;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40,45}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=45;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": top ****************"<<endl;
  old=tostring(st);
  rese=top(st);
  req_rese=40;
  res=tostring(st);
  req_res="{10,15,20,25,30,35,40}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: top(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=40;
  res=tostring(st);
  req_res="{10,15,20,25,30,35}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=35;
  res=tostring(st);
  req_res="{10,15,20,25,30}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=30;
  res=tostring(st);
  req_res="{10,15,20,25}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=25;
  res=tostring(st);
  req_res="{10,15,20}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=20;
  res=tostring(st);
  req_res="{10,15}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=15;
  res=tostring(st);
  req_res="{10}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  rese=pop(st);
  req_rese=10;
  res=tostring(st);
  req_res="{}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata st="<<req_res<<endl;
    cout<<"  Queue ottenuta st="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": pop ****************"<<endl;
  old=tostring(st);
  excep=false;
  try{
    rese=pop(st);
  }
  catch(string exc){
    excep=true;
  }
  if(excep) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: pop(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato: Exception"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": top ****************"<<endl;
  old=tostring(st);
  excep=false;
  try{
    rese=top(st);
  }
  catch(string exc){
    excep=true;
  }
  if(excep) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: top(st)"<<endl;
    cout<<"  con st="<<old<<endl;
    cout<<"  Risultato aspettato: Exception"<<endl;
  }
  cout<<endl;
  ++i;
}