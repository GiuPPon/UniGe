/////////////////////////////////////////////////////////////////////////////
//
// COME COMPILARE IL PROGRAMMA
//
// g++ -std=c++11 -Wall dictionary-bst.cpp string-utility.cpp dictionary-test.cpp -o dictionary-test
//
/////////////////////////////////////////////////////////////////////////////

#include "dictionary.h"

using namespace dict;
using namespace std;

int main(){
  Dictionary d;
  unsigned i=1;
  bool bres=false;
  bool breq=false;
  Error eres=OK;
  Error ereq=OK;
  string sres="";
  string sreq="";
  
  cout<<"*************** Test "<<i<<": d=createEmptyDict() ****************"<<endl;
  d=createEmptyDict();
 
  if(d==emptyDictionary) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":isEmpty(d) ****************"<<endl;
  bres=isEmpty(d);
  breq=true;
  if(bres==breq) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":insertElem(\"Dog\",\"Dog is an animal\",d) ***************"<<endl;
  eres=insertElem("Dog","Dog is an animal",d);
  ereq=OK;
  if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":isEmpty(d) ****************"<<endl;
  bres=isEmpty(d);
  breq=false;
  if(bres==breq) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":search(\"Dog\",d) ***************"<<endl;
  sres=search("Dog",d);
  sreq="Dog is an animal";
  if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl; 
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":insertElem(\"Dog\",\"Best friend\",d) ***************"<<endl;
  eres=insertElem("Dog","Best Friend",d);
  ereq=FAIL;
  if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":isEmpty(d) ****************"<<endl;
  bres=isEmpty(d);
  breq=false;
  if(bres==breq) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":search(\"Dog\",d) ***************"<<endl;
  sres=search("Dog",d);
  sreq="Dog is an animal";
  if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl; 
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":search(\"Cat\",d) ***************"<<endl;
  sres=search("Cat",d);
  sreq=emptyValue;
  if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;   
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl; 
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":insertElem(\"Cat\",\"Cat is an animal\",d) ***************"<<endl;
  eres=insertElem("Cat","Cat is an animal",d);
  ereq=OK;
  if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":search(\"Cat\",d) ***************"<<endl;
  sres=search("Cat",d);
  sreq="Cat is an animal";
  if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;  
    cout<<"  Expected Returned Value: "<<sreq<<endl;
    cout<<"  Obtained Returned Value: "<<sres<<endl; 
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":insertElem(\"Giraffe\",\"Giraffe is an animal\",d) ***************"<<endl;
  eres=insertElem("Giraffe","Giraffe is an animal",d);
  ereq=OK;
  if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<":search(\"Giraffe\",d) ***************"<<endl;
  sres=search("Giraffe",d);
  sreq="Giraffe is an animal";
  if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
  else{
    cout<<"  Risultato: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<sreq<<endl;
                                               cout<<"  Obtained Returned Value: "<<sres<<endl;    
  }
      cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Cat\",d) ***************"<<endl;
    sres=search("Cat",d);
    sreq="Cat is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Dog\",d) ***************"<<endl;
    sres=search("Dog",d);
    sreq="Dog is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Anaconda\",\"Anaconda is an animal\",d) ***************"<<endl;
    eres=insertElem("Anaconda","Anaconda is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Ananconda\",d) ***************"<<endl;
    sres=search("Anaconda",d);
    sreq="Anaconda is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Camel\",\"Camel is an animal\",d) ***************"<<endl;
    eres=insertElem("Camel","Camel is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Camel\",d) ***************"<<endl;
    sres=search("Camel",d);
    sreq="Camel is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Cheetah\",\"Cheetah is an animal\",d) ***************"<<endl;
    eres=insertElem("Cheetah","Cheetah is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Cheetah\",d) ***************"<<endl;
    sres=search("Cheetah",d);
    sreq="Cheetah is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Elephant\",\"Elephant is an animal\",d) ***************"<<endl;
    eres=insertElem("Elephant","Elephant is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Elephant\",d) ***************"<<endl;
    sres=search("Elephant",d);
    sreq="Elephant is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Cheetah\",d) ***************"<<endl;
    sres=search("Cheetah",d);
    sreq="Cheetah is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Camel\",d) ***************"<<endl;
    sres=search("Camel",d);
    sreq="Camel is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Ananconda\",d) ***************"<<endl;
    sres=search("Anaconda",d);
    sreq="Anaconda is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Giraffe\",d) ***************"<<endl;
    sres=search("Giraffe",d);
    sreq="Giraffe is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;    
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Cat\",d) ***************"<<endl;
    sres=search("Cat",d);
    sreq="Cat is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Dog\",d) ***************"<<endl;
    sres=search("Dog",d);
    sreq="Dog is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;
  
    cout<<"*************** Test "<<i<<":insertElem(\"Goat\",\"Goat is an animal\",d) ***************"<<endl;
    eres=insertElem("Goat","Goat is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Goat\",d) ***************"<<endl;
    sres=search("Goat",d);
    sreq="Goat is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Mosquito\",\"Mosquito is an animal\",d) ***************"<<endl;
    eres=insertElem("Mosquito","Mosquito is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Mosquito\",d) ***************"<<endl;
    sres=search("Mosquito",d);
    sreq="Mosquito is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Goat\",\"Are wild\",d) ***************"<<endl;
    eres=insertElem("Goat","Are wild",d);
    ereq=FAIL;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Flatworm\",\"Flatworm is an animal\",d) ***************"<<endl;
    eres=insertElem("Flatworm","Flatworm is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Flatworm\",d) ***************"<<endl;
    sres=search("Flatworm",d);
    sreq="Flatworm is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Eagle\",\"Eagle is an animal\",d) ***************"<<endl;
    eres=insertElem("Eagle","Eagle is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Eagle\",d) ***************"<<endl;
    sres=search("Eagle",d);
    sreq="Eagle is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Capybara\",\"Capybara is an animal\",d) ***************"<<endl;
    eres=insertElem("Capybara","Capybara is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Capybara\",d) ***************"<<endl;
    sres=search("Capybara",d);
    sreq="Capybara is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Earthworm\",\"Earthworm is an animal\",d) ***************"<<endl;
    eres=insertElem("Earthworm","Earthworm is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Earthworm\",d) ***************"<<endl;
    sres=search("Earthworm",d);
    sreq="Earthworm is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Albatross\",\"Albatross is an animal\",d) ***************"<<endl;
    eres=insertElem("Albatross","Albatross is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Albatross\",d) ***************"<<endl;
    sres=search("Albatross",d);
    sreq="Albatross is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Chameleon\",\"Chameleon is an animal\",d) ***************"<<endl;
    eres=insertElem("Chameleon","Chameleon is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Chameleon\",d) ***************"<<endl;
    sres=search("Chameleon",d);
    sreq="Chameleon is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Ape\",\"Ape is an animal\",d) ***************"<<endl;
    eres=insertElem("Ape","Ape is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Ape\",d) ***************"<<endl;
    sres=search("Ape",d);
    sreq="Ape is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Chinchilla\",\"Chinchilla is an animal\",d) ***************"<<endl;
    eres=insertElem("Chinchilla","Chinchilla is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Chinchilla\",d) ***************"<<endl;
    sres=search("Chinchilla",d);
    sreq="Chinchilla is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Allosaurus\",\"Allosaurus is an animal\",d) ***************"<<endl;
    eres=insertElem("Allosaurus","Allosaurus is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Allosaurus\",d) ***************"<<endl;
    sres=search("Allosaurus",d);
    sreq="Allosaurus is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Alligator\",\"Alligator is an animal\",d) ***************"<<endl;
    eres=insertElem("Alligator","Alligator is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Alligator\",d) ***************"<<endl;
    sres=search("Alligator",d);
    sreq="Alligator is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Antelope\",\"Antelope is an animal\",d) ***************"<<endl;
    eres=insertElem("Antelope","Antelope is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Antelope\",d) ***************"<<endl;
    sres=search("Antelope",d);
    sreq="Antelope is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Ant\",\"Ant is an animal\",d) ***************"<<endl;
    eres=insertElem("Ant","Ant is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Ant\",\"Ant is an insect\",d) ***************"<<endl;
    eres=insertElem("Ant","Ant is an insect",d);
    ereq=FAIL;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Ant\",d) ***************"<<endl;
    sres=search("Ant",d);
    sreq="Ant is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Mamba\",\"Mamba is an animal\",d) ***************"<<endl;
    eres=insertElem("Mamba","Mamba is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Mamba\",d) ***************"<<endl;
    sres=search("Mamba",d);
    sreq="Mamba is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Llama\",\"Llama is an animal\",d) ***************"<<endl;
    eres=insertElem("Llama","Llama is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Llama\",d) ***************"<<endl;
    sres=search("Llama",d);
    sreq="Llama is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Lion\",\"Lion is an animal\",d) ***************"<<endl;
    eres=insertElem("Lion","Lion is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Lion\",d) ***************"<<endl;
    sres=search("Lion",d);
    sreq="Lion is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Turtle\",\"Turtle is an animal\",d) ***************"<<endl;
    eres=insertElem("Turtle","Turtle is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Turtle\",d) ***************"<<endl;
    sres=search("Turtle",d);
    sreq="Turtle is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Walrus\",\"Walrus is an animal\",d) ***************"<<endl;
    eres=insertElem("Walrus","Walrus is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Walrus\",d) ***************"<<endl;
    sres=search("Walrus",d);
    sreq="Walrus is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Termite\",\"Termite is an animal\",d) ***************"<<endl;
    eres=insertElem("Termite","Termite is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Termite\",d) ***************"<<endl;
    sres=search("Termite",d);
    sreq="Termite is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Tiger\",\"Tiger is an animal\",d) ***************"<<endl;
    eres=insertElem("Tiger","Tiger is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Tiger\",d) ***************"<<endl;
    sres=search("Tiger",d);
    sreq="Tiger is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Pig\",\"Pig is an animal\",d) ***************"<<endl;
    eres=insertElem("Pig","Pig is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Pig\",d) ***************"<<endl;
    sres=search("Pig",d);
    sreq="Pig is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Raccoon\",\"Raccoon is an animal\",d) ***************"<<endl;
    eres=insertElem("Raccoon","Raccoon is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Raccoon\",d) ***************"<<endl;
    sres=search("Raccoon",d);
    sreq="Raccoon is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Salmon\",\"Salmon is an animal\",d) ***************"<<endl;
    eres=insertElem("Salmon","Salmon is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Salmon\",d) ***************"<<endl;
    sres=search("Salmon",d);
    sreq="Salmon is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":deleteElem(\"Chinchilla\",d) ***************"<<endl;
    eres=deleteElem("Chinchilla",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Chinchilla\",d) ***************"<<endl;
    sres=search("Chinchilla",d);
    sreq= emptyValue;
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":deleteElem(\"Chinchilla\",d) ***************"<<endl;
    eres=deleteElem("Chinchilla",d);
    ereq=FAIL;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Chinchilla\",\"Chinchilla is an animal\",d) ***************"<<endl;
    eres=insertElem("Chinchilla","Chinchilla is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Chinchilla\",d) ***************"<<endl;
    sres=search("Chinchilla",d);
    sreq="Chinchilla is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":deleteElem(\"Ape\",d) ***************"<<endl;
    eres=deleteElem("Ape",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Ape\",d) ***************"<<endl;
    sres=search("Ape",d);
    sreq= emptyValue;
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":deleteElem(\"Ape\",d) ***************"<<endl;
    eres=deleteElem("Ape",d);
    ereq=FAIL;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Antelope\",d) ***************"<<endl;
    sres=search("Antelope",d);
    sreq="Antelope is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Ant\",d) ***************"<<endl;
    sres=search("Ant",d);
    sreq="Ant is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":insertElem(\"Ape\",\"Ape is an animal\",d) ***************"<<endl;
    eres=insertElem("Ape","Ape is an animal",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Ape\",d) ***************"<<endl;
    sres=search("Ape",d);
    sreq="Ape is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":deleteElem(\"Albatross\",d) ***************"<<endl;
    eres=deleteElem("Albatross",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Albatross\",d) ***************"<<endl;
    sres=search("Albatross",d);
    sreq= emptyValue;
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":deleteElem(\"Albatross\",d) ***************"<<endl;
    eres=deleteElem("Albatross",d);
    ereq=FAIL;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Allosaurus\",d) ***************"<<endl;
    sres=search("Allosaurus",d);
    sreq="Allosaurus is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Alligator\",d) ***************"<<endl;
    sres=search("Alligator",d);
    sreq="Alligator is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":deleteElem(\"Anaconda\",d) ***************"<<endl;
    eres=deleteElem("Anaconda",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Anaconda\",d) ***************"<<endl;
    sres=search("Anaconda",d);
    sreq= emptyValue;
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":deleteElem(\"Anaconda\",d) ***************"<<endl;
    eres=deleteElem("Anaconda",d);
    ereq=FAIL;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Ant\",d) ***************"<<endl;
    sres=search("Ant",d);
    sreq="Ant is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Antelope\",d) ***************"<<endl;
    sres=search("Antelope",d);
    sreq="Antelope is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Ape\",d) ***************"<<endl;
    sres=search("Ape",d);
    sreq="Ape is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Camel\",d) ***************"<<endl;
    sres=search("Camel",d);
    sreq="Camel is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Capybara\",d) ***************"<<endl;
    sres=search("Capybara",d);
    sreq="Capybara is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":deleteElem(\"Mosquito\",d) ***************"<<endl;
    eres=deleteElem("Mosquito",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Mosquito\",d) ***************"<<endl;
    sres=search("Mosquito",d);
    sreq= emptyValue;
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":deleteElem(\"Mosquito\",d) ***************"<<endl;
    eres=deleteElem("Mosquito",d);
    ereq=FAIL;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Pig\",d) ***************"<<endl;
    sres=search("Pig",d);
    sreq="Pig is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Raccoon\",d) ***************"<<endl;
    sres=search("Raccoon",d);
    sreq="Raccoon is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Salmon\",d) ***************"<<endl;
    sres=search("Salmon",d);
    sreq="Salmon is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Termite\",d) ***************"<<endl;
    sres=search("Termite",d);
    sreq="Termite is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Tiger\",d) ***************"<<endl;
    sres=search("Tiger",d);
    sreq="Tiger is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Turtle\",d) ***************"<<endl;
    sres=search("Turtle",d);
    sreq="Turtle is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Walrus\",d) ***************"<<endl;
    sres=search("Walrus",d);
    sreq="Walrus is an animal";
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":deleteElem(\"Dog\",d) ***************"<<endl;
    eres=deleteElem("Dog",d);
    ereq=OK;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":search(\"Dog\",d) ***************"<<endl;
    sres=search("Dog",d);
    sreq= emptyValue;
    if(sres==sreq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
      cout<<"  Expected Returned Value: "<<sreq<<endl;
      cout<<"  Obtained Returned Value: "<<sres<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":deleteElem(\"Dog\",d) ***************"<<endl;
    eres=deleteElem("Dog",d);
    ereq=FAIL;
    if(eres==ereq) cout<<"  Risultato: PASSED"<<endl;
    else{
      cout<<"  Risultato: FAILED"<<endl;
    }
    cout<<endl;
    ++i;

    cout<<"*************** Test "<<i<<":print(d) ***************"<<endl;
    cout<<"  Expected result of the form:"<<endl;
    cout<<"  #########################################"<<endl;
    cout<<"     Alligator: Alligator is an animal"<<endl;
    cout<<"     Allosaurus: Allosaurus is an animal"<<endl;
    cout<<"     Ant: Ant is an animal"<<endl;
    cout<<"     Antelope: Antelope is an animal"<<endl;
    cout<<"     Ape: Ape is an animal"<<endl;
    cout<<"     Camel: Camel is an animal"<<endl;
    cout<<"     Capybara: Capybara is an animal"<<endl;
    cout<<"     Cat: Cat is an animal"<<endl;
    cout<<"     Chameleon: Chameleon is an animal"<<endl;
    cout<<"     Cheetah: Cheetah is an animal"<<endl;
    cout<<"     Chinchilla: Chinchilla is an animal"<<endl;
    cout<<"     Eagle: Eagle is an animal"<<endl;
    cout<<"     Earthworm: Earthworm is an animal"<<endl;
    cout<<"     Elephant: Elephant is an animal"<<endl;
    cout<<"     Flatworm: Flatworm is an animal"<<endl;
    cout<<"     Giraffe: Giraffe is an animal"<<endl;
    cout<<"     Goat: Goat is an animal"<<endl;
    cout<<"     Lion: Lion is an animal"<<endl;
    cout<<"     Llama: Llama is an animal"<<endl;
    cout<<"     Mamba: Mamba is an animal"<<endl;
    cout<<"     Pig: Pig is an animal"<<endl;
    cout<<"     Raccoon: Raccoon is an animal"<<endl;
    cout<<"     Salmon: Salmon is an animal"<<endl;
    cout<<"     Termite: Termite is an animal"<<endl;
    cout<<"     Tiger: Tiger is an animal"<<endl;
    cout<<"     Turtle: Turtle is an animal"<<endl;
    cout<<"     Walrus: Walrus is an animal"<<endl;
    cout<<"  #########################################"<<endl;
    cout<<"\n  Obtained result:\n"<<endl;
    print(d);
}
