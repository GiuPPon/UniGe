#include <iostream>
#include <string>
#include "double-hash.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
 */
string siOrNo(bool b){
  if(b) return "SI"; 
  else return "NO";
}

void xyz_printList(const dllist& li){
  cout<<"{";
  dllist cur=li;
  while(cur!=nullptr){
    cout<<cur->elem;
    if(cur->next!=nullptr){
      cout<<",";
    }
    cur=cur->next;
  }
  cout<<"}";
}

void xyz_printTable(const dhash_table& dht){
  cout<<"  T1=[";
  for(unsigned int i=0;i<tableDim;++i){
    xyz_printList(dht.T1[i]);
    if(i+1!=tableDim){
      cout<<"|";
    }
  }
  cout<<"]"<<endl;
  cout<<"  T2=[";
  for(unsigned int i=0;i<tableDim;++i){
    xyz_printList(dht.T2[i]);
    if(i+1!=tableDim){
      cout<<"|";
    }
  }
  cout<<"]"<<endl;
}

void xyz_init(dhash_table& dht){
  dht.T1=new dllist[tableDim];
  dht.T2=new dllist[tableDim];
  for(unsigned int i=0;i<tableDim;++i){
    dht.T1[i]=nullptr;
    dht.T2[i]=nullptr;
  }
}

int xyz_presOrLength(const dllist& li,Elem e){
  int count=0;
  dllist cur=li;
  while(cur!=nullptr){
    if(cur->elem==e){
      return -1;
    }
    ++count;
    cur=cur->next;
  }
  return count;
}

void xyz_insertli(dllist& li,Elem e){
  if(li==nullptr){
    li=new cell{e,nullptr,nullptr};
  }else if(li->elem>=e){
    li=new cell{e,li,li->prev};
    li->next->prev=li;
    if(li->prev!=nullptr){
      li->prev->next=li;
    }
  } else if(li->next==nullptr){
    li->next=new cell{e,nullptr,li};
  } else{
    xyz_insertli(li->next,e);
  }
}

void xyz_insert(dhash_table& dht,Elem e){
  int count1=xyz_presOrLength(dht.T1[h1(e)],e);
  int count2=xyz_presOrLength(dht.T2[h2(e)],e);
  if(count1!=-1 && count2!=-1){
    if(count2<count1){
      xyz_insertli(dht.T2[h2(e)],e);
    }else{
      xyz_insertli(dht.T1[h1(e)],e);
    }
  }
}
  
////////////////////////////////////////////////////////////////////////////

int main(){
  int ret=0;
 
  cout << std::boolalpha;
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
  cout << "\n****   TEST  isPresent(...)             *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 23 TEST DA SUPERARE !!!!";
  int nTest = 1;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,65) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    bool breq=false; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,65);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,65) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    bool breq=false; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,65);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,5) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,5);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,15) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,15);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,15);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,115) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,115);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,15) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,15);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,115) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,1015);
    xyz_insert(dht,1115);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,115);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,115) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,1015);
    xyz_insert(dht,1115);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,115);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,3) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T1[5],5);
    xyz_insertli(dht.T1[5],15);
    xyz_insertli(dht.T1[5],25);
    bool breq=false; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,3);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,25) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T1[5],5);
    xyz_insertli(dht.T1[5],15);
    xyz_insertli(dht.T1[5],25);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,25);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,5) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T1[5],5);
    xyz_insertli(dht.T1[5],15);
    xyz_insertli(dht.T1[5],25);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,5);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,102) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T2[h2(5)],5);
    xyz_insertli(dht.T2[h2(100)],100);
    xyz_insertli(dht.T2[h2(101)],101);
    xyz_insertli(dht.T2[h2(105)],105);
    bool breq=false; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,102);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,100) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T2[h2(5)],5);
    xyz_insertli(dht.T2[h2(100)],100);
    xyz_insertli(dht.T2[h2(101)],101);
    xyz_insertli(dht.T2[h2(105)],105);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,100);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,101) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T2[h2(5)],5);
    xyz_insertli(dht.T2[h2(100)],100);
    xyz_insertli(dht.T2[h2(101)],101);
    xyz_insertli(dht.T2[h2(105)],105);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,101);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,105) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T2[h2(5)],5);
    xyz_insertli(dht.T2[h2(100)],100);
    xyz_insertli(dht.T2[h2(101)],101);
    xyz_insertli(dht.T2[h2(105)],105);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,105);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,6) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T1[h1(0)],0);
    xyz_insertli(dht.T1[h1(10)],10);
    xyz_insertli(dht.T1[h1(20)],20);
    xyz_insertli(dht.T1[h1(1)],1);
    xyz_insertli(dht.T1[h1(11)],11);
    xyz_insertli(dht.T1[h1(21)],21);
    xyz_insertli(dht.T1[h1(41)],41);
    xyz_insertli(dht.T1[h1(29)],29);
    xyz_insertli(dht.T1[h1(49)],49);
    
    xyz_insertli(dht.T2[h2(5)],5);
    xyz_insertli(dht.T2[h2(100)],100);
    xyz_insertli(dht.T2[h2(101)],101);
    xyz_insertli(dht.T2[h2(105)],105);

    xyz_insertli(dht.T2[h2(35)],35);
    xyz_insertli(dht.T2[h2(37)],37);
    xyz_insertli(dht.T2[h2(132)],132);
    xyz_insertli(dht.T2[h2(138)],138);
    xyz_insertli(dht.T2[h2(39)],39);
    xyz_insertli(dht.T2[h2(34)],34);
    xyz_insertli(dht.T2[h2(139)],139);
    xyz_insertli(dht.T2[h2(136)],136);
    xyz_insertli(dht.T2[h2(191)],191);
    bool breq=false; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,6);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,49) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T1[h1(0)],0);
    xyz_insertli(dht.T1[h1(10)],10);
    xyz_insertli(dht.T1[h1(20)],20);
    xyz_insertli(dht.T1[h1(1)],1);
    xyz_insertli(dht.T1[h1(11)],11);
    xyz_insertli(dht.T1[h1(21)],21);
    xyz_insertli(dht.T1[h1(41)],41);
    xyz_insertli(dht.T1[h1(29)],29);
    xyz_insertli(dht.T1[h1(49)],49);
    
    xyz_insertli(dht.T2[h2(5)],5);
    xyz_insertli(dht.T2[h2(100)],100);
    xyz_insertli(dht.T2[h2(101)],101);
    xyz_insertli(dht.T2[h2(105)],105);

    xyz_insertli(dht.T2[h2(35)],35);
    xyz_insertli(dht.T2[h2(37)],37);
    xyz_insertli(dht.T2[h2(132)],132);
    xyz_insertli(dht.T2[h2(138)],138);
    xyz_insertli(dht.T2[h2(39)],39);
    xyz_insertli(dht.T2[h2(34)],34);
    xyz_insertli(dht.T2[h2(139)],139);
    xyz_insertli(dht.T2[h2(136)],136);
    xyz_insertli(dht.T2[h2(191)],191);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,49);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,132) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T1[h1(0)],0);
    xyz_insertli(dht.T1[h1(10)],10);
    xyz_insertli(dht.T1[h1(20)],20);
    xyz_insertli(dht.T1[h1(1)],1);
    xyz_insertli(dht.T1[h1(11)],11);
    xyz_insertli(dht.T1[h1(21)],21);
    xyz_insertli(dht.T1[h1(41)],41);
    xyz_insertli(dht.T1[h1(29)],29);
    xyz_insertli(dht.T1[h1(49)],49);
    
    xyz_insertli(dht.T2[h2(5)],5);
    xyz_insertli(dht.T2[h2(100)],100);
    xyz_insertli(dht.T2[h2(101)],101);
    xyz_insertli(dht.T2[h2(105)],105);

    xyz_insertli(dht.T2[h2(35)],35);
    xyz_insertli(dht.T2[h2(37)],37);
    xyz_insertli(dht.T2[h2(132)],132);
    xyz_insertli(dht.T2[h2(138)],138);
    xyz_insertli(dht.T2[h2(39)],39);
    xyz_insertli(dht.T2[h2(34)],34);
    xyz_insertli(dht.T2[h2(139)],139);
    xyz_insertli(dht.T2[h2(136)],136);
    xyz_insertli(dht.T2[h2(191)],191);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,132);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,5) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T1[h1(0)],0);
    xyz_insertli(dht.T1[h1(10)],10);
    xyz_insertli(dht.T1[h1(20)],20);
    xyz_insertli(dht.T1[h1(1)],1);
    xyz_insertli(dht.T1[h1(11)],11);
    xyz_insertli(dht.T1[h1(21)],21);
    xyz_insertli(dht.T1[h1(41)],41);
    xyz_insertli(dht.T1[h1(29)],29);
    xyz_insertli(dht.T1[h1(49)],49);
    
    xyz_insertli(dht.T2[h2(5)],5);
    xyz_insertli(dht.T2[h2(100)],100);
    xyz_insertli(dht.T2[h2(101)],101);
    xyz_insertli(dht.T2[h2(105)],105);

    xyz_insertli(dht.T2[h2(35)],35);
    xyz_insertli(dht.T2[h2(37)],37);
    xyz_insertli(dht.T2[h2(132)],132);
    xyz_insertli(dht.T2[h2(138)],138);
    xyz_insertli(dht.T2[h2(39)],39);
    xyz_insertli(dht.T2[h2(34)],34);
    xyz_insertli(dht.T2[h2(139)],139);
    xyz_insertli(dht.T2[h2(136)],136);
    xyz_insertli(dht.T2[h2(191)],191);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,5);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,0) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T1[h1(0)],0);
    xyz_insertli(dht.T1[h1(10)],10);
    xyz_insertli(dht.T1[h1(20)],20);
    xyz_insertli(dht.T1[h1(1)],1);
    xyz_insertli(dht.T1[h1(11)],11);
    xyz_insertli(dht.T1[h1(21)],21);
    xyz_insertli(dht.T1[h1(41)],41);
    xyz_insertli(dht.T1[h1(29)],29);
    xyz_insertli(dht.T1[h1(49)],49);
    
    xyz_insertli(dht.T2[h2(5)],5);
    xyz_insertli(dht.T2[h2(100)],100);
    xyz_insertli(dht.T2[h2(101)],101);
    xyz_insertli(dht.T2[h2(105)],105);

    xyz_insertli(dht.T2[h2(35)],35);
    xyz_insertli(dht.T2[h2(37)],37);
    xyz_insertli(dht.T2[h2(132)],132);
    xyz_insertli(dht.T2[h2(138)],138);
    xyz_insertli(dht.T2[h2(39)],39);
    xyz_insertli(dht.T2[h2(34)],34);
    xyz_insertli(dht.T2[h2(139)],139);
    xyz_insertli(dht.T2[h2(136)],136);
    xyz_insertli(dht.T2[h2(191)],191);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,0);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,191) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T1[h1(0)],0);
    xyz_insertli(dht.T1[h1(10)],10);
    xyz_insertli(dht.T1[h1(20)],20);
    xyz_insertli(dht.T1[h1(1)],1);
    xyz_insertli(dht.T1[h1(11)],11);
    xyz_insertli(dht.T1[h1(21)],21);
    xyz_insertli(dht.T1[h1(41)],41);
    xyz_insertli(dht.T1[h1(29)],29);
    xyz_insertli(dht.T1[h1(49)],49);
    
    xyz_insertli(dht.T2[h2(5)],5);
    xyz_insertli(dht.T2[h2(100)],100);
    xyz_insertli(dht.T2[h2(101)],101);
    xyz_insertli(dht.T2[h2(105)],105);

    xyz_insertli(dht.T2[h2(35)],35);
    xyz_insertli(dht.T2[h2(37)],37);
    xyz_insertli(dht.T2[h2(132)],132);
    xyz_insertli(dht.T2[h2(138)],138);
    xyz_insertli(dht.T2[h2(39)],39);
    xyz_insertli(dht.T2[h2(34)],34);
    xyz_insertli(dht.T2[h2(139)],139);
    xyz_insertli(dht.T2[h2(136)],136);
    xyz_insertli(dht.T2[h2(191)],191);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,191);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,29) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T1[h1(0)],0);
    xyz_insertli(dht.T1[h1(10)],10);
    xyz_insertli(dht.T1[h1(20)],20);
    xyz_insertli(dht.T1[h1(1)],1);
    xyz_insertli(dht.T1[h1(11)],11);
    xyz_insertli(dht.T1[h1(21)],21);
    xyz_insertli(dht.T1[h1(41)],41);
    xyz_insertli(dht.T1[h1(29)],29);
    xyz_insertli(dht.T1[h1(49)],49);
    
    xyz_insertli(dht.T2[h2(5)],5);
    xyz_insertli(dht.T2[h2(100)],100);
    xyz_insertli(dht.T2[h2(101)],101);
    xyz_insertli(dht.T2[h2(105)],105);

    xyz_insertli(dht.T2[h2(35)],35);
    xyz_insertli(dht.T2[h2(37)],37);
    xyz_insertli(dht.T2[h2(132)],132);
    xyz_insertli(dht.T2[h2(138)],138);
    xyz_insertli(dht.T2[h2(39)],39);
    xyz_insertli(dht.T2[h2(34)],34);
    xyz_insertli(dht.T2[h2(139)],139);
    xyz_insertli(dht.T2[h2(136)],136);
    xyz_insertli(dht.T2[h2(191)],191);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,29);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": isPresent(dht,39) ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insertli(dht.T1[h1(0)],0);
    xyz_insertli(dht.T1[h1(10)],10);
    xyz_insertli(dht.T1[h1(20)],20);
    xyz_insertli(dht.T1[h1(1)],1);
    xyz_insertli(dht.T1[h1(11)],11);
    xyz_insertli(dht.T1[h1(21)],21);
    xyz_insertli(dht.T1[h1(41)],41);
    xyz_insertli(dht.T1[h1(29)],29);
    xyz_insertli(dht.T1[h1(49)],49);
    
    xyz_insertli(dht.T2[h2(5)],5);
    xyz_insertli(dht.T2[h2(100)],100);
    xyz_insertli(dht.T2[h2(101)],101);
    xyz_insertli(dht.T2[h2(105)],105);

    xyz_insertli(dht.T2[h2(35)],35);
    xyz_insertli(dht.T2[h2(37)],37);
    xyz_insertli(dht.T2[h2(132)],132);
    xyz_insertli(dht.T2[h2(138)],138);
    xyz_insertli(dht.T2[h2(39)],39);
    xyz_insertli(dht.T2[h2(34)],34);
    xyz_insertli(dht.T2[h2(139)],139);
    xyz_insertli(dht.T2[h2(136)],136);
    xyz_insertli(dht.T2[h2(191)],191);
    bool breq=true; 
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    bool bres = isPresent(dht,39);
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!ans){
      cout << "Il risultato aspettato era: "<<breq<<endl;
    }
    if(ans) ++ret;
  }
  
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
