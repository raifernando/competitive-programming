// PREENCHIMENTO DE VETOR
// https://judge.beecrowd.com/pt/problems/view/1173

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int vetor[10] = {n};

    for (int i = 1; i < 10; i++) {
        vetor[i] = vetor[i-1] * 2;
    }

    for (int i = 0; i < 10; i++) {
        cout << "N[" << i << "] = " << vetor[i] << endl;
    }

    return 0;
}