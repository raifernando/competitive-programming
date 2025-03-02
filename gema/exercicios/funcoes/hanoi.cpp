// TORRES DE HANOI
// https://neps.academy/br/exercise/337

#include <bits/stdc++.h>
using namespace std;

int hanoi (int n, int orig, int dest, int temp) {
    int passos = 0;

    if (n == 1) 
        return 1;
    else 
        passos += 2*hanoi(n-1, orig, temp, dest) + 1;
    
    return passos;
}

int main() {
    int n;
    cin >> n;

    int cont = 1;
    while (n) {
        cout << "Teste " << cont << endl;
        cout << hanoi(n, 1, 3, 2);
        cont++;

        cin >> n;
        if (n) cout << endl << endl;
    }

    return 0;
}