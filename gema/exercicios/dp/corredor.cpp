// Corredor (OBI)
// https://neps.academy/br/exercise/306

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int max_vida = 0;

    int soma = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        soma += x;
        max_vida = max(max_vida, soma);

        if (soma < 0)
            soma = 0;

    }

    cout << max_vida << endl;

    return 0;
}