////////////////////////////////////////////////////////////////////////
// COMPILAZIONE:
// g++  -std=c++11 -Wall list-array.cpp graph.cpp graph-test.cpp -o graph-test
////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <iostream>
#include <fstream> 
#include "graph.h"

using namespace graph;
using namespace list;
using namespace std;

int main(){
  cout<<boolalpha;
  Graph g;
  List l;
  unsigned i=1;
  bool bres=false;
  bool breq=false;
  unsigned ires=0;
  unsigned ireq=0;
  

  cout<<"*************** Test "<<i<<": g=createEmptyGraph(); ****************"<<endl;
  g=createEmptyGraph();
 
  if(g==emptyGraph) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty(g) ****************"<<endl;
  bres=isEmpty(g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Genova\",g) ****************"<<endl;
  bres=addVertex("Genova",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": isEmpty(g) ****************"<<endl;
  bres=isEmpty(g);
  breq=false;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Genova\",g) ****************"<<endl;
  bres=addVertex("Genova",g);
  breq=false;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Camogli\",g) ****************"<<endl;
  bres=addVertex("Camogli",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

   cout<<"*************** Test "<<i<<": addVertex(\"Camogli\",g) ****************"<<endl;
  bres=addVertex("Camogli",g);
  breq=false;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Genova\",\"Camogli\",30,g) ****************"<<endl;
  bres=addEdge("Genova","Camogli",30,g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

   cout<<"*************** Test "<<i<<": addEdge(\"Genova\",\"Camogli\",10,g) ****************"<<endl;
  bres=addEdge("Genova","Camogli",10,g);
  breq=false;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Camogli\",\"Genova\",20,g) ****************"<<endl;
  bres=addEdge("Camogli","Genova",20,g);
  breq=false;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Camogli\",\"Deiva\",5,g) ****************"<<endl;
  bres=addEdge("Camogli","Deiva",5,g);
  breq=false;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Torino\",g) ****************"<<endl;
  bres=addVertex("Torino",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Cuneo\",g) ****************"<<endl;
  bres=addVertex("Cuneo",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Torino\",\"Cuneo\",60,g) ****************"<<endl;
  bres=addEdge("Torino","Cuneo",60,g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Torino\",\"Genova\",110,g) ****************"<<endl;
  bres=addEdge("Torino","Genova",110,g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Sassari\",g) ****************"<<endl;
  bres=addVertex("Sassari",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Cagliari\",g) ****************"<<endl;
  bres=addVertex("Cagliari",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Sassari\",\"Cagliari\",150,g) ****************"<<endl;
  bres=addEdge("Cagliari","Sassari",150,g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Olbia\",g) ****************"<<endl;
  bres=addVertex("Olbia",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Sassari\",\"Olbia\",120,g) ****************"<<endl;
  bres=addEdge("Sassari","Olbia",120,g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Olbia\",\"Cagliari\",200,g) ****************"<<endl;
  bres=addEdge("Olbia","Cagliari",200,g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Oristano\",g) ****************"<<endl;
  bres=addVertex("Oristano",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Oristano\",g) ****************"<<endl;
  bres=addVertex("Oristano",g);
  breq=false;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Oristano\",\"Sassari\",45,g) ****************"<<endl;
  bres=addEdge("Oristano","Sassari",45,g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Sassari\",\"Oristano\",35,g) ****************"<<endl;
  bres=addEdge("Sassari","Oristano",35,g);
  breq=false;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Olbia\",\"Oristano\",90,g) ****************"<<endl;
  bres=addEdge("Olbia","Oristano",90,g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Cagliari\",\"Oristano\",70,g) ****************"<<endl;
  bres=addEdge("Cagliari","Oristano",70,g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": numVertices(g) ****************"<<endl;
  ires=numVertices(g);
  ireq=8;
  if(ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Bari\",g) ****************"<<endl;
  bres=addVertex("Bari",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": numVertices(g) ****************"<<endl;
  ires=numVertices(g);
  ireq=9;
  if(ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": numEdges(g) ****************"<<endl;
  ires=numEdges(g);
  ireq=9;
  if(ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Lecce\",g) ****************"<<endl;
  bres=addVertex("Lecce",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": numVertices(g) ****************"<<endl;
  ires=numVertices(g);
  ireq=10;
  if(ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": numEdges(g) ****************"<<endl;
  ires=numEdges(g);
  ireq=9;
  if(ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Bari\",\"Lecce\",45,g) ****************"<<endl;
  bres=addEdge("Bari","Lecce",45,g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": numEdges(g) ****************"<<endl;
  ires=numEdges(g);
  ireq=10;
  if(ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Monopoli\",g) ****************"<<endl;
  bres=addVertex("Monopoli",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": numVertices(g) ****************"<<endl;
  ires=numVertices(g);
  ireq=11;
  if(ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Monopoli\",\"Lecce\",37,g) ****************"<<endl;
  bres=addEdge("Monopoli","Lecce",37,g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": numEdges(g) ****************"<<endl;
  ires=numEdges(g);
  ireq=11;
  if(ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": nodeDegree(\"Genova\",ires,g) ****************"<<endl;
  bres=nodeDegree("Genova",ires,g);
  breq=true;
  ireq=2;
  if(ires==ireq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Degree: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Degree: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": nodeDegree(\"Milano\",ires,g) ****************"<<endl;
  bres=nodeDegree("Milano",ires,g);
  breq=false;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
  }
  cout<<endl;
  ++i;

   cout<<"*************** Test "<<i<<": nodeDegree(\"Camogli\",ires,g) ****************"<<endl;
  bres=nodeDegree("Camogli",ires,g);
  breq=true;
  ireq=1;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Degree: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Degree: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": nodeDegree(\"Cuneo\",ires,g) ****************"<<endl;
  bres=nodeDegree("Cuneo",ires,g);
  breq=true;
  ireq=1;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Degree: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Degree: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": nodeDegree(\"Sassari\",ires,g) ****************"<<endl;
  bres=nodeDegree("Sassari",ires,g);
  breq=true;
  ireq=3;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Degree: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Degree: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": nodeDegree(\"Cagliari\",ires,g) ****************"<<endl;
  bres=nodeDegree("Cagliari",ires,g);
  breq=true;
  ireq=3;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Degree: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Degree: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": nodeDegree(\"Olbia\",ires,g) ****************"<<endl;
  bres=nodeDegree("Olbia",ires,g);
  breq=true;
  ireq=3;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Degree: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Degree: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": nodeDegree(\"Oristano\",ires,g) ****************"<<endl;
  bres=nodeDegree("Oristano",ires,g);
  breq=true;
  ireq=3;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Degree: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Degree: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": nodeDegree(\"Bari\",ires,g) ****************"<<endl;
  bres=nodeDegree("Bari",ires,g);
  breq=true;
  ireq=1;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Degree: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Degree: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": nodeDegree(\"Lecce\",ires,g) ****************"<<endl;
  bres=nodeDegree("Lecce",ires,g);
  breq=true;
  ireq=2;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Degree: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Degree: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addVertex(\"Martina Franca\",g) ****************"<<endl;
  bres=addVertex("Martina Franca",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": nodeDegree(\"Martina Franca\",ires,g) ****************"<<endl;
  bres=nodeDegree("Martina Franca",ires,g);
  breq=true;
  ireq=0;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Degree: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Degree: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": addEdge(\"Martina Franca\",\"Lecce\",12,g) ****************"<<endl;
  bres=addEdge("Martina Franca","Lecce",12,g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": nodeDegree(\"Lecce\",ires,g) ****************"<<endl;
  bres=nodeDegree("Lecce",ires,g);
  breq=true;
  ireq=3;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Degree: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Degree: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": areAdjacent(\"Genova\",\"Camogli\",g) ****************"<<endl;
  bres=areAdjacent("Genova","Camogli",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": areAdjacent(\"Camogli\",\"Genova\",g) ****************"<<endl;
  bres=areAdjacent("Camogli","Genova",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": areAdjacent(\"Genova\",\"Cuneo\",g) ****************"<<endl;
  bres=areAdjacent("Genova","Cuneo",g);
  breq=false;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": areAdjacent(\"Cuneo\",\"Genova\",g) ****************"<<endl;
  bres=areAdjacent("Cuneo","Genova",g);
  breq=false;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

   cout<<"*************** Test "<<i<<": areAdjacent(\"Milano\",\"Genova\",g) ****************"<<endl;
  bres=areAdjacent("Milano","Genova",g);
  breq=false;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  cout<<"*************** Test "<<i<<": areAdjacent(\"Oristano\",\"Cagliari\",g) ****************"<<endl;
  bres=areAdjacent("Oristano","Cagliari",g);
  breq=true;
  if(bres==breq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
  }
  cout<<endl;
  ++i;

  l=createEmpty();
  cout<<"*************** Test "<<i<<": findPath(\"Genova\",\"Genova\",l,ires,g) ****************"<<endl;
  bres=findPath("Genova","Genova",l,ires,g);
  breq=true;
  ireq=0;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Weight: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Weight: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  clear(l);
  cout<<"*************** Test "<<i<<": findPath(\"Genova\",\"Camogli\",l,ires,g) ****************"<<endl;
  bres=findPath("Genova","Camogli",l,ires,g);
  breq=true;
  ireq=30;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Weight: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Weight: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  clear(l);
  cout<<"*************** Test "<<i<<": findPath(\"Genova\",\"Cuneo\",l,ires,g) ****************"<<endl;
  bres=findPath("Genova","Cuneo",l,ires,g);
  breq=true;
  ireq=170;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Weight: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Weight: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  clear(l);
  cout<<"*************** Test "<<i<<": findPath(\"Cuneo\",\"Camogli\",l,ires,g) ****************"<<endl;
  bres=findPath("Cuneo","Camogli",l,ires,g);
  breq=true;
  ireq=200;
  if(bres==breq && ires==ireq) cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Weight: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Weight: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  clear(l);
  cout<<"*************** Test "<<i<<": findPath(\"Bari\",\"Martina Franca\",l,ires,g) ****************"<<endl;
  bres=findPath("Bari","Martina Franca",l,ires,g);
  breq=true;
  ireq=57;
  if(bres==breq && ires==ireq)
    cout<<"  Result: PASSED"<<endl;
  else{
    cout<<"  Result: FAILED"<<endl;
    cout<<"  Expected Returned Value: "<<breq<<endl;
    cout<<"  Expected Weight: "<<ireq<<endl;
    cout<<"  Obtained Returned Value: "<<bres<<endl;
    cout<<"  Obtained Weight: "<<ires<<endl;
  }
  cout<<endl;
  ++i;

  clear(l);
  cout<<"*************** Test "<<i<<": l=adjacentList(\"Genova\",g) ****************"<<endl;
  l=adjacentList("Genova",g);
  cout<<"  Returned List: ";
  printList(l);
  cout<<endl;
  cout<<"  Expected List: Camogli; Torino;"<<endl;
  cout<<"  If the two lists contain the same label ---> OK"<<endl;
  cout<<endl;
  ++i;

  clear(l);
  cout<<"*************** Test "<<i<<": l=adjacentList(\"Cuneo\",g) ****************"<<endl;
  l=adjacentList("Cuneo",g);
  cout<<"  Returned List: ";
  printList(l);
  cout<<endl;
  cout<<"  Expected List: Torino;"<<endl;
  cout<<"  If the two lists contain the same label ---> OK"<<endl;
  cout<<endl;
  ++i;

  clear(l);
  cout<<"*************** Test "<<i<<": l=adjacentList(\"Oristano\",g) ****************"<<endl;
  l=adjacentList("Oristano",g);
  cout<<"  Returned List: ";
  printList(l);
  cout<<endl;
  cout<<"  Expected List: Sassari; Cagliari; Olbia;"<<endl;
  cout<<"  If the two lists contain the same label ---> OK"<<endl;
  cout<<endl;
  ++i;

  clear(l);
  cout<<"*************** Test "<<i<<": l=adjacentList(\"Lecce\",g) ****************"<<endl;
  l=adjacentList("Lecce",g);
  cout<<"  Returned List: ";
  printList(l);
  cout<<endl;
  cout<<"  Expected List: Bari; Monopoli; Martina Franca;"<<endl;
  cout<<"  If the two lists contain the same label ---> OK"<<endl;
  cout<<endl;
  ++i;
  
  
}
