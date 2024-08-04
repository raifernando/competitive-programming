// CÓDIGO
// https://neps.academy/br/course/programacao-basica-(codcad)/lesson/codigo-(obi-2015)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int seq[n];

    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    int soma = 0;

    for (int i = 0; i < n-2; i++) {
        if (seq[i] == 1 && seq[i+1] == 0 && seq[i+2] == 0) soma++;
    }

    cout << soma;

    return 0;
}