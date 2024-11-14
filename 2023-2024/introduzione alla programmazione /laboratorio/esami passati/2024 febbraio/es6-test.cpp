#include <iostream>

#include "list.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
*/
string siOrNo(bool b){
    if(b) return "SI";
    else return "NO";
}
////////////////////////////////////////////////////////////////////////////
// funzione utilizzata per test **non modificare**
std::string printList(List list)
{
    std::string out = "";
    int i = 0;

    while (list != nullptr) {

        if (i>0) out = out + "->";
        out = out + to_string(list->elem);

        list = list->next;
        i++;
    }
    if(i>0) out=out+"->";
    out=out+"nullptr";
    return out;
}

std::string printCircList(List list)
{
    List h=list;
    std::string out = "";
    if(list==nullptr){
        out="nullptr";
        return out;
    }
    out = out+to_string(list->elem);
    list=list->next;
    while (list != h) {
        out = out + "->";
        out = out + to_string(list->elem);
        list = list->next;
    }
    out=out+"->(beginning of the list)";
    return out;
}

////////////////////////////////////////////////////////////////////////////
int main(){
    int ret=0;
    cout << std::boolalpha;
    cout << "\n";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    cout << "\n***** TEST deleteAllCircList(...) *****";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

    cout << "\n";
    cout << "\n!!!! ATTENZIONE: 16 TEST DA SUPERARE !!!!";
    int nTest = 1;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=nullptr;
        int v=0;
        std::string corr="nullptr";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=1;
        l->next=l;
        int v=0;
        std::string corr="1->(beginning of the list)";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=1;
        l->next=l;
        int v=1;
        std::string corr="nullptr";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=1;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=2;
        l2->next=l;
        int v=0;
        std::string corr="1->2->(beginning of the list)";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=1;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=2;
        l2->next=l;
        int v=1;
        std::string corr="2->(beginning of the list)";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=1;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=2;
        l2->next=l;
        int v=2;
        std::string corr="1->(beginning of the list)";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=3;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=3;
        l2->next=l;
        int v=3;
        std::string corr="nullptr";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=1;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=7;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=-5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=4;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=10;
        l2->next=l;
        int v=0;
        std::string corr="1->2->3->5->7->-5->4->2->10->(beginning of the list)";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=1;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=7;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=-5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=4;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=10;
        l2->next=l;
        int v=10;
        std::string corr="1->2->3->5->7->-5->4->2->(beginning of the list)";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=1;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=7;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=-5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=4;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=10;
        l2->next=l;
        int v=1;
        std::string corr="2->3->5->7->-5->4->2->10->(beginning of the list)";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=1;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=7;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=-5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=4;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=10;
        l2->next=l;
        int v=-5;
        std::string corr="1->2->3->5->7->4->2->10->(beginning of the list)";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=1;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=7;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=-5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=4;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=10;
        l2->next=l;
        int v=2;
        std::string corr="1->5->5->7->-5->4->10->(beginning of the list)";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=10;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=7;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=-5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=4;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=10;
        l2->next=l;
        int v=10;
        std::string corr="2->3->5->7->-5->4->2->(beginning of the list)";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }

    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=1;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=4;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=2;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=10;
        l2->next=l;
        int v=3;
        std::string corr="1->2->4->2->10->(beginning of the list)";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=1;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=l;
        int v=1;
        std::string corr="5->(beginning of the list)";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }
    nTest++;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=new Cell;
        l->elem=1;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=l;
        int v=1;
        std::string corr="nullptr";
        cout << "\nDelete "<<v<<" nella lista: " << printCircList(l);
        cout << "\nLa lista cambiata deve essere: "<<corr;
        deleteAllCircList(l,v);
        std::string res=printCircList(l);
        cout << "\nLa funzione cambia la lista in: "<<res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? "
            "================================> "
            << siOrNo(ans)<<endl;
        if(ans) ++ret;
    }


    cout<<"\n";
    cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
    return ret;

} 
