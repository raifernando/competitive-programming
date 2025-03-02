// DESAFIO DO MAIOR NUMERO
// https://neps.academy/br/exercise/323

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int maior = 0;

    while (n != 0) {
        cin >> n;
        if (n > maior) maior = n;
    }

    cout << maior;

    return 0;
}