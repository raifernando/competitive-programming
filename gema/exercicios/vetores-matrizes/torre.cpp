// TORRE
// https://neps.academy/br/exercise/45

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int tabuleiro[n][n], linhas[n] = {0}, colunas[n] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            tabuleiro[i][j] = x;

            linhas[i] += x;
            colunas[j] += x;
        }
    }

    int maximo = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int peso = linhas[i] + colunas[j] - 2*tabuleiro[i][j];

            if (peso > maximo) maximo = peso;
        }
    } 

    cout << maximo;

    return 0;
}