// QUADRADO MAGICO 3X3
// https://neps.academy/br/exercise/198

#include <bits/stdc++.h>
using namespace std;

int main() {
    int numeros = 0, diagonais = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x; cin >> x;

            numeros += x;
            
            if (i == j) diagonais += x;
            if (i + j == 2) diagonais += x;
        }
    }

    if (diagonais == (2 * (numeros / 3))) cout << "SIM";
    else cout << "NAO";

    return 0;
}