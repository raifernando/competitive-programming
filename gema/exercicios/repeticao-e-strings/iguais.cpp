// CONSECUTIVOS
// https://neps.academy/br/exercise/110

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, maiorseq = 0, sequencia = 1;
    long long int anterior = 0, atual;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> atual;

        if (i == 0) {
            anterior = atual;
            continue;
        }

        if (anterior == atual) {sequencia++;}
        else if (sequencia > maiorseq) {
            maiorseq = sequencia;
            sequencia = 1;
        }
        else {sequencia=1;}

        anterior = atual;
    }

    cout << max(maiorseq, sequencia);

    return 0;
}