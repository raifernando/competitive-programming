// C - Vacation
// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 1e5 + 5;

int atividades[maxn][3];

int maior_pontos() {
    for (int i = 1; i < n; i++) {
        atividades[i][0] = max(atividades[i][0] + atividades[i-1][1], atividades[i][0] + atividades[i-1][2]);
        atividades[i][1] = max(atividades[i][1] + atividades[i-1][0], atividades[i][1] + atividades[i-1][2]);
        atividades[i][2] = max(atividades[i][2] + atividades[i-1][0], atividades[i][2] + atividades[i-1][1]);
    }

    int r = 0;
    for (int i = 0; i < 3; i++) {
        r = max(r, atividades[n-1][i]);
    }

    return r;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> atividades[i][j];
        }
    }

    cout << maior_pontos() << endl;

    return 0;
}