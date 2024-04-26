// CAMPO MINADO
// https://neps.academy/br/exercise/241

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int vet[n+5] = {0};

    for (int i = 1; i <= n; i++) {
        cin >> vet[i];
    }

    for (int i = 1; i <= n; i++) {
        int minas = 0;
        
        minas = vet[i-1] + vet [i] + vet[i + 1];

        cout << minas << endl;
    }

    return 0;
}