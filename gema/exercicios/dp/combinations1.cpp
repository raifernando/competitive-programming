// Coins Combinations 1
// https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 105, maxx = 1e6 + 5;
const ll modulo = 1e9 + 7;

vector<int> m(maxn);
vector<ll> qnt(maxx);

int n, x;

ll contar_quantidades() {
    for (int i = 0; i <= x; i++) {
        for (int moeda = 0; moeda < n; moeda++) {
            int soma = i + m[moeda];

            if (soma > x)
                continue;

            qnt[soma] = (qnt[soma] + qnt[i]) % modulo;
        }
    }

    return qnt[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> m[i];
        qnt[m[i]] = 1;
    }

    cout << contar_quantidades() << endl;

    return 0;
}