// Coins Combinations 2
// https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 102, maxx = 1e6 + 2;
const ll modulo = 1e9 + 7;

vector<int> m(maxn);
ll qnt[maxx];

int n, x;

ll contar_quantidades() {
    for (int moeda = 1; moeda <= n; moeda++) {
        qnt[m[moeda]] = (qnt[m[moeda]] + 1) % modulo;
        for (int v = m[moeda]; v <= x; v++) {
            qnt[v] = (qnt[v] + qnt[v-m[moeda]]) % modulo;
        }
    }

    return qnt[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }

    cout << contar_quantidades() << endl;

    return 0;
}