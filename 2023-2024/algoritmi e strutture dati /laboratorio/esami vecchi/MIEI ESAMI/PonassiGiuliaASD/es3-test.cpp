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

bool xyz_wellformed_list(const dllist& li){
  if(li==nullptr){return true;}
  if(li->prev!=nullptr){
    return false;}
  dllist cur=li;
  while(cur!=nullptr){
    if(cur->next!=nullptr && cur->next->prev!=cur){
      return false;
    }
    cur=cur->next;
  }
  return true;                        
}

bool xyz_wellformed(const dhash_table& dht){
  for(unsigned int i=0;i<tableDim;++i){
    if(!xyz_wellformed_list(dht.T1[i])){  
      string err="Errore: la lista T1["+to_string(i)+"] non rispetta la struttura di lista doppiamente collegata!";
        throw err;
    }
    if(!xyz_wellformed_list(dht.T2[i])){
      string err="Errore: la lista T2["+to_string(i)+"] non rispetta la struttura di lista doppiamente collegata!";
        throw err;
    }
  }
  return true;
}

bool xyz_equal_list(const dllist& li1,const dllist& li2){
  if(li1==nullptr || li2==nullptr){
    if(li1==nullptr && li2==nullptr){
      return true;
    }else{
      return false;
    }
  }else{
    return (li1->elem==li2->elem && xyz_equal_list(li1->next,li2->next)); 
  }
}

bool xyz_equal(const dhash_table& dht1,const dhash_table& dht2){
  for(unsigned int i=0;i<tableDim;++i){
    if(!xyz_equal_list(dht1.T1[i],dht2.T1[i]) || !xyz_equal_list(dht1.T2[i],dht2.T2[i])) {
      return false;
    }
  }
  return true;
}

  
////////////////////////////////////////////////////////////////////////////

int main(){
  int ret=0;
 
  cout << std::boolalpha;
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
  cout << "\n****   TEST  insert(...)                 *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 21 TEST DA SUPERARE !!!!";
  int nTest = 1;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,5)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    insert(dht,5);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,10)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);    
    insert(dht,10);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,15)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    insert(dht,15);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,115)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    insert(dht,115);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,10)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    insert(dht,10);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,115)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    insert(dht,115);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,110)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    insert(dht,110);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,410)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    insert(dht,410);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,610)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    xyz_insert(dht,410);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    xyz_insert(reqdht,610);
    insert(dht,610);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,610)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    xyz_insert(dht,410);
    xyz_insert(dht,610);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    xyz_insert(reqdht,610);
    xyz_insert(reqdht,310);
    insert(dht,310);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,510)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    xyz_insert(dht,410);
    xyz_insert(dht,610);
    xyz_insert(dht,310);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    xyz_insert(reqdht,610);
    xyz_insert(reqdht,310);
    xyz_insert(reqdht,510);
    insert(dht,510);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,313)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    xyz_insert(dht,410);
    xyz_insert(dht,610);
    xyz_insert(dht,310);
    xyz_insert(dht,510);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    xyz_insert(reqdht,610);
    xyz_insert(reqdht,310);
    xyz_insert(reqdht,510);
    xyz_insert(reqdht,313);
    insert(dht,313);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,113)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    xyz_insert(dht,410);
    xyz_insert(dht,610);
    xyz_insert(dht,310);
    xyz_insert(dht,510);
    xyz_insert(dht,313);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    xyz_insert(reqdht,610);
    xyz_insert(reqdht,310);
    xyz_insert(reqdht,510);
    xyz_insert(reqdht,313);
    xyz_insert(reqdht,113);
    insert(dht,113);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,613)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    xyz_insert(dht,410);
    xyz_insert(dht,610);
    xyz_insert(dht,310);
    xyz_insert(dht,510);
    xyz_insert(dht,313);
    xyz_insert(dht,113);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    xyz_insert(reqdht,610);
    xyz_insert(reqdht,310);
    xyz_insert(reqdht,510);
    xyz_insert(reqdht,313);
    xyz_insert(reqdht,113);
    xyz_insert(reqdht,613);
    insert(dht,613);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,113)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    xyz_insert(dht,410);
    xyz_insert(dht,610);
    xyz_insert(dht,310);
    xyz_insert(dht,510);
    xyz_insert(dht,313);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    xyz_insert(reqdht,610);
    xyz_insert(reqdht,310);
    xyz_insert(reqdht,510);
    xyz_insert(reqdht,313);
    xyz_insert(reqdht,113);
    insert(dht,113);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,210)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    xyz_insert(dht,410);
    xyz_insert(dht,610);
    xyz_insert(dht,310);
    xyz_insert(dht,510);
    xyz_insert(dht,313);
    xyz_insert(dht,113);
    xyz_insert(dht,613);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    xyz_insert(reqdht,610);
    xyz_insert(reqdht,310);
    xyz_insert(reqdht,510);
    xyz_insert(reqdht,313);
    xyz_insert(reqdht,113);
    xyz_insert(reqdht,613);
    xyz_insert(reqdht,210);
    insert(dht,210);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,13)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    xyz_insert(dht,410);
    xyz_insert(dht,610);
    xyz_insert(dht,310);
    xyz_insert(dht,510);
    xyz_insert(dht,313);
    xyz_insert(dht,113);
    xyz_insert(dht,613);
    xyz_insert(dht,210);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    xyz_insert(reqdht,610);
    xyz_insert(reqdht,310);
    xyz_insert(reqdht,510);
    xyz_insert(reqdht,313);
    xyz_insert(reqdht,113);
    xyz_insert(reqdht,613);
    xyz_insert(reqdht,210);
     xyz_insert(reqdht,13);
    insert(dht,13);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,80)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    xyz_insert(dht,410);
    xyz_insert(dht,610);
    xyz_insert(dht,310);
    xyz_insert(dht,510);
    xyz_insert(dht,313);
    xyz_insert(dht,113);
    xyz_insert(dht,613);
    xyz_insert(dht,210);
    xyz_insert(dht,13);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    xyz_insert(reqdht,610);
    xyz_insert(reqdht,310);
    xyz_insert(reqdht,510);
    xyz_insert(reqdht,313);
    xyz_insert(reqdht,113);
    xyz_insert(reqdht,613);
    xyz_insert(reqdht,210);
    xyz_insert(reqdht,13);
    xyz_insert(reqdht,80);
    insert(dht,80);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,50)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    xyz_insert(dht,410);
    xyz_insert(dht,610);
    xyz_insert(dht,310);
    xyz_insert(dht,510);
    xyz_insert(dht,313);
    xyz_insert(dht,113);
    xyz_insert(dht,613);
    xyz_insert(dht,210);
    xyz_insert(dht,13);
    xyz_insert(dht,80);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    xyz_insert(reqdht,610);
    xyz_insert(reqdht,310);
    xyz_insert(reqdht,510);
    xyz_insert(reqdht,313);
    xyz_insert(reqdht,113);
    xyz_insert(reqdht,613);
    xyz_insert(reqdht,210);
    xyz_insert(reqdht,13);
    xyz_insert(reqdht,80);
    xyz_insert(reqdht,50);
    insert(dht,50);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,55)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    xyz_insert(dht,410);
    xyz_insert(dht,610);
    xyz_insert(dht,310);
    xyz_insert(dht,510);
    xyz_insert(dht,313);
    xyz_insert(dht,113);
    xyz_insert(dht,613);
    xyz_insert(dht,210);
    xyz_insert(dht,13);
    xyz_insert(dht,80);
    xyz_insert(dht,50);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    xyz_insert(reqdht,610);
    xyz_insert(reqdht,310);
    xyz_insert(reqdht,510);
    xyz_insert(reqdht,313);
    xyz_insert(reqdht,113);
    xyz_insert(reqdht,613);
    xyz_insert(reqdht,210);
    xyz_insert(reqdht,13);
    xyz_insert(reqdht,80);
    xyz_insert(reqdht,50);
    xyz_insert(reqdht,55);
    insert(dht,55);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": insert(dht,84)  ";
    cout << "\n-----------------------------------------";

    dhash_table dht;
    xyz_init(dht);
    xyz_insert(dht,5);
    xyz_insert(dht,10);
    xyz_insert(dht,15);
    xyz_insert(dht,115);
    xyz_insert(dht,110);
    xyz_insert(dht,410);
    xyz_insert(dht,610);
    xyz_insert(dht,310);
    xyz_insert(dht,510);
    xyz_insert(dht,313);
    xyz_insert(dht,113);
    xyz_insert(dht,613);
    xyz_insert(dht,210);
    xyz_insert(dht,13);
    xyz_insert(dht,80);
    xyz_insert(dht,50);
    xyz_insert(dht,55);
    cout << "\ncon dht uguale a:"<<endl;
    xyz_printTable(dht);
    dhash_table reqdht;
    xyz_init(reqdht);
    xyz_insert(reqdht,5);
    xyz_insert(reqdht,10);
    xyz_insert(reqdht,15);
    xyz_insert(reqdht,115);
    xyz_insert(reqdht,110);
    xyz_insert(reqdht,410);
    xyz_insert(reqdht,610);
    xyz_insert(reqdht,310);
    xyz_insert(reqdht,510);
    xyz_insert(reqdht,313);
    xyz_insert(reqdht,113);
    xyz_insert(reqdht,613);
    xyz_insert(reqdht,210);
    xyz_insert(reqdht,13);
    xyz_insert(reqdht,80);
    xyz_insert(reqdht,50);
    xyz_insert(reqdht,55);
    xyz_insert(reqdht,84);
    insert(dht,84);
    bool ans=true;
    bool wf=true;
    try{
      xyz_wellformed(dht);
    }catch(string& exc){
      cout<<"\n"<<exc<<endl;
      wf=false;
      ans=false;
    }
    bool areq=true;
    if(wf){
      areq=xyz_equal(reqdht,dht);
      if(!areq){
        cout<<"\ndht e' cambiato in:\n";
        xyz_printTable(dht);
        ans=false;
      }
    }
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(!areq){
      cout << "\ndht doveva essere cambiato in:\n";
      xyz_printTable(reqdht);
    }
    if(ans) ++ret;
  }
 
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
