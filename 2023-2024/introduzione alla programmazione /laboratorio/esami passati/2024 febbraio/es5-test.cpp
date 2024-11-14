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
    cout << "\n***** TEST allDiffInCircList(...) *****";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

    cout << "\n";
    cout << "\n!!!! ATTENZIONE: 14 TEST DA SUPERARE !!!!";
    int nTest = 1;
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << nTest;
        cout << "\n-----------------------------------------";

        List l=nullptr;
        bool res=allDiffInCircList(l);
        bool corr=true;
        cout << "\nLa lista data e': " << printList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
        l->elem=2;
        l->next=l;
        bool res=allDiffInCircList(l);
        bool corr=true;
        cout << "\nLa lista data e': " << printCircList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
        l->elem=2;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=-1;
        l2->next=l;
        bool res=allDiffInCircList(l);
        bool corr=true;
        cout << "\nLa lista data e': " << printCircList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
        l->elem=2;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=2;
        l2->next=l;
        bool res=allDiffInCircList(l);
        bool corr=false;
        cout << "\nLa lista data e': " << printCircList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
        l->elem=2;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=l;
        bool res=allDiffInCircList(l);
        bool corr=true;
        cout << "\nLa lista data e': " << printCircList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
        l->elem=2;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=2;
        l2->next=l;
        bool res=allDiffInCircList(l);
        bool corr=false;
        cout << "\nLa lista data e': " << printCircList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
        l->elem=5;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=2;
        l2->next=l;
        bool res=allDiffInCircList(l);
        bool corr=false;
        cout << "\nLa lista data e': " << printCircList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
        l->elem=2;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=1;
        l2->next=l;
        bool res=allDiffInCircList(l);
        bool corr=false;
        cout << "\nLa lista data e': " << printCircList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
        l->elem=2;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=7;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=4;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=11;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=-1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=12;
        l2->next=l;
        bool res=allDiffInCircList(l);
        bool corr=true;
        cout << "\nLa lista data e': " << printCircList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
        l->elem=12;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=7;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=4;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=11;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=-1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=12;
        l2->next=l;
        bool res=allDiffInCircList(l);
        bool corr=false;
        cout << "\nLa lista data e': " << printCircList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
        l->elem=2;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=7;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=11;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=-1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=12;
        l2->next=l;
        bool res=allDiffInCircList(l);
        bool corr=false;
        cout << "\nLa lista data e': " << printCircList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
        l->elem=2;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=7;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=4;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=11;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=12;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=12;
        l2->next=l;
        bool res=allDiffInCircList(l);
        bool corr=false;
        cout << "\nLa lista data e': " << printCircList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
        l->elem=2;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=7;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=4;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=4;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=11;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=-1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=12;
        l2->next=l;
        bool res=allDiffInCircList(l);
        bool corr=false;
        cout << "\nLa lista data e': " << printCircList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
        l->elem=2;
        l->next=new Cell;
        List l2=l->next;
        l2->elem=1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=7;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=3;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=11;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=-1;
        l2->next=new Cell;
        l2=l2->next;
        l2->elem=5;
        l2->next=l;
        bool res=allDiffInCircList(l);
        bool corr=false;
        cout << "\nLa lista data e': " << printCircList(l);;
        cout << "\nLa funzione deve ritornare "<<corr;
        cout << "\nLa funzione ritorna "<<res;
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
