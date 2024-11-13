#include <iostream>
#include <string>
#include "array.h"

using namespace std;

int main(){
    try {
        int ar[]={1, 5, 8, 3, -4};
        unsigned int dim = 5;
        
        cout<<'"'<<stampa(ar, dim)<<'"'<<endl;
        cout<<'"'<<stampaKelementi(ar, dim, 0)<<'"'<<endl;
        cout<<'"'<<stampaKelementi(ar, dim, 1)<<'"'<<endl;
        cout<<'"'<<stampaKelementi(ar, dim, 2)<<'"'<<endl;
        cout<<'"'<<stampaKelementi(ar, dim, 3)<<'"'<<endl;
        cout<<'"'<<stampaKelementi(ar, dim, 4)<<'"'<<endl;
        cout<<'"'<<stampaKelementi(ar, dim, 6)<<'"'<<endl;

        sort(ar, dim);
        cout << stampa(ar,dim);
    }
    catch (string err) {
        cout<<err<<endl;
    }
}