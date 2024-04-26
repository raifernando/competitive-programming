// MENOR E POSIÇÃO
// https://judge.beecrowd.com/pt/problems/view/1180

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int x[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int menor = x[0], pos = 0;

    for (int i = 0; i < n; i++) {
        if (x[i] < menor) {
            menor = x[i]; 
            pos = i;
        }
    }

    cout << "Menor valor: " << menor << endl << "Posicao: " << pos << endl;

    return 0;
}
