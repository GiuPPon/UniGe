// File Main
// Compilare con g++ -Wall ASD-queue-list.cpp ASD-queue-test.cpp -o ASD-queue-test

// NON MODIFICARE QUESTO FILE

#include <iostream>
#include "ASD-queue-list.h"

using namespace std;
using namespace queue;

int main(){
  Queue q;
  string old,req_res,res;
  bool resb,excep;
  Elem rese, req_rese;
  cout << boolalpha;

  unsigned i=1;
  cout<<"*************** Test "<<i<<": createEmpty ****************"<<endl;
  q=createEmpty();
  res=tostring(q);
  req_res="{}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: q=createEmpty()"<<endl;
    cout<<"  Risultato aspettato q="<<req_res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty ****************"<<endl;
  old=tostring(q);
  resb=isEmpty(q);
  if(resb) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: isEmpty(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato: "<<"true"<<endl;
    cout<<"  Risultato ottenuto: "<<resb<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": enqueue ****************"<<endl;
  old=tostring(q);
  enqueue(1,q);
  res=tostring(q);
  req_res="{1}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: enqueue(1,q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato q="<<req_res<<endl;
    cout<<"  Risultato ottenuto q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty ****************"<<endl;
  old=tostring(q);
  resb=isEmpty(q);
  if(!resb) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: isEmpty(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato: "<<"false"<<endl;
    cout<<"  Risultato ottenuto: "<<resb<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": enqueue ****************"<<endl;
  old=tostring(q);
  enqueue(2,q);
  res=tostring(q);
  req_res="{2,1}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: enqueue(2,q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato q="<<req_res<<endl;
    cout<<"  Risultato ottenuto q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty ****************"<<endl;
  old=tostring(q);
  resb=isEmpty(q);
  if(!resb) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: isEmpty(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato: "<<"false"<<endl;
    cout<<"  Risultato ottenuto: "<<resb<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": enqueue ****************"<<endl;
  old=tostring(q);
  enqueue(3,q);
  res=tostring(q);
  req_res="{3,2,1}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: enqueue(3,q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato q="<<req_res<<endl;
    cout<<"  Risultato ottenuto q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": dequeue ****************"<<endl;
  old=tostring(q);
  rese=dequeue(q);
  req_rese=1;
  res=tostring(q);
  req_res="{3,2}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: dequeue(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty ****************"<<endl;
  old=tostring(q);
  resb=isEmpty(q);
  if(!resb) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: isEmpty(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato: "<<"false"<<endl;
    cout<<"  Risultato ottenuto: "<<resb<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": dequeue ****************"<<endl;
  old=tostring(q);
  rese=dequeue(q);
  req_rese=2;
  res=tostring(q);
  req_res="{3}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: dequeue(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": dequeue ****************"<<endl;
  old=tostring(q);
  rese=dequeue(q);
  req_rese=3;
  res=tostring(q);
  req_res="{}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: dequeue(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty ****************"<<endl;
  old=tostring(q);
  resb=isEmpty(q);
  if(resb) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: isEmpty(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato: "<<"true"<<endl;
    cout<<"  Risultato ottenuto: "<<resb<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": enqueue ****************"<<endl;
  old=tostring(q);
  enqueue(1000,q);
  res=tostring(q);
  req_res="{1000}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: enqueue(1000,q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato q="<<req_res<<endl;
    cout<<"  Risultato ottenuto q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": first ****************"<<endl;
  old=tostring(q);
  rese=first(q);
  req_rese=1000;
  res=tostring(q);
  req_res="{1000}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: first(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": enqueue ****************"<<endl;
  old=tostring(q);
  enqueue(900,q);
  res=tostring(q);
  req_res="{900,1000}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: enqueue(900,q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato q="<<req_res<<endl;
    cout<<"  Risultato ottenuto q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": first ****************"<<endl;
  old=tostring(q);
  rese=first(q);
  req_rese=1000;
  res=tostring(q);
  req_res="{900,1000}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: first(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": enqueue ****************"<<endl;
  old=tostring(q);
  enqueue(950,q);
  res=tostring(q);
  req_res="{950,900,1000}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: enqueue(950,q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato q="<<req_res<<endl;
    cout<<"  Risultato ottenuto q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": first ****************"<<endl;
  old=tostring(q);
  rese=first(q);
  req_rese=1000;
  res=tostring(q);
  req_res="{950,900,1000}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: first(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": dequeue ****************"<<endl;
  old=tostring(q);
  rese=dequeue(q);
  req_rese=1000;
  res=tostring(q);
  req_res="{950,900}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: dequeue(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": first ****************"<<endl;
  old=tostring(q);
  rese=first(q);
  req_rese=900;
  res=tostring(q);
  req_res="{950,900}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: first(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": enqueue ****************"<<endl;
  old=tostring(q);
  enqueue(950,q);
  res=tostring(q);
  req_res="{950,950,900}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: enqueue(950,q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato q="<<req_res<<endl;
    cout<<"  Risultato ottenuto q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": enqueue ****************"<<endl;
  old=tostring(q);
  enqueue(800,q);
  res=tostring(q);
  req_res="{800,950,950,900}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: enqueue(800,q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato q="<<req_res<<endl;
    cout<<"  Risultato ottenuto q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": enqueue ****************"<<endl;
  old=tostring(q);
  enqueue(850,q);
  res=tostring(q);
  req_res="{850,800,950,950,900}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: enqueue(850,q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato q="<<req_res<<endl;
    cout<<"  Risultato ottenuto q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": enqueue ****************"<<endl;
  old=tostring(q);
  enqueue(700,q);
  res=tostring(q);
  req_res="{700,850,800,950,950,900}";
  if(res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: enqueue(700,q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato q="<<req_res<<endl;
    cout<<"  Risultato ottenuto q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": first ****************"<<endl;
  old=tostring(q);
  rese=first(q);
  req_rese=900;
  res=tostring(q);
  req_res="{700,850,800,950,950,900}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: first(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": dequeue ****************"<<endl;
  old=tostring(q);
  rese=dequeue(q);
  req_rese=900;
  res=tostring(q);
  req_res="{700,850,800,950,950}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: dequeue(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": first ****************"<<endl;
  old=tostring(q);
  rese=first(q);
  req_rese=950;
  res=tostring(q);
  req_res="{700,850,800,950,950}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: first(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": dequeue ****************"<<endl;
  old=tostring(q);
  rese=dequeue(q);
  req_rese=950;
  res=tostring(q);
  req_res="{700,850,800,950}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: dequeue(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": dequeue ****************"<<endl;
  old=tostring(q);
  rese=dequeue(q);
  req_rese=950;
  res=tostring(q);
  req_res="{700,850,800}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: dequeue(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": dequeue ****************"<<endl;
  old=tostring(q);
  rese=dequeue(q);
  req_rese=800;
  res=tostring(q);
  req_res="{700,850}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: dequeue(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": first ****************"<<endl;
  old=tostring(q);
  rese=first(q);
  req_rese=850;
  res=tostring(q);
  req_res="{700,850}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: first(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": dequeue ****************"<<endl;
  old=tostring(q);
  rese=dequeue(q);
  req_rese=850;
  res=tostring(q);
  req_res="{700}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: dequeue(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": first ****************"<<endl;
  old=tostring(q);
  rese=first(q);
  req_rese=700;
  res=tostring(q);
  req_res="{700}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: first(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": dequeue ****************"<<endl;
  old=tostring(q);
  rese=dequeue(q);
  req_rese=700;
  res=tostring(q);
  req_res="{}";
  if(rese==req_rese && res==req_res) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: dequeue(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato "<<req_rese<<endl;
    cout<<"  Risultato ottenuto "<<rese<<endl;
    cout<<"  Queue aspettata q="<<req_res<<endl;
    cout<<"  Queue ottenuta q="<<res<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty ****************"<<endl;
  old=tostring(q);
  resb=isEmpty(q);
  if(resb) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: isEmpty(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato: "<<"false"<<endl;
    cout<<"  Risultato ottenuto: "<<resb<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": dequeue ****************"<<endl;
  old=tostring(q);
  excep=false;
  try{
    rese=dequeue(q);
  }
  catch(string exc){
    excep=true;
  }
  if(excep) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: dequeue(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato: Exception"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": first ****************"<<endl;
  old=tostring(q);
  excep=false;
  try{
    rese=first(q);
  }
  catch(string exc){
    excep=true;
  }
  if(excep) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Funzione chiamata: first(q)"<<endl;
    cout<<"  con q="<<old<<endl;
    cout<<"  Risultato aspettato: Exception"<<endl;
  }
  cout<<endl;
  ++i;

}