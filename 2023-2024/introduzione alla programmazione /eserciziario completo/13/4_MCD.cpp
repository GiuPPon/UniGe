/* Scrivere una funzione ricorsiva unsigned MCD(unsigned m, unsigned n) che dati due numeri interi m 
ed n calcola il massimo comune divisore utilizzando l’algoritmo di Euclide, descritto nel seguente 
modo:
MCD(m,n) = m se m==n
MCD(m,n) = MCD(m-n, n) se m > n
MCD(m,n) = MCD(m, n-m) se n > m */

unsigned MCD(unsigned m, unsigned n) {
    if (m == n) {
        return m;
    } else if (m > n) {
        return MCD(m - n, n);
    } else if (n > m) {
        return MCD(m, n - m);
    }
}