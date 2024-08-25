// Flight Discount
// https://cses.fi/problemset/task/1195/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii, int> ppi;
typedef pair<ll,ll> pll;
typedef pair<pll, int> ppl;

#define INF (ll) 2e50

int main() {
    int n, m;
    cin >> n >> m;

    const int MAX = n+1;

    vector<pii> grafo[MAX];

    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;

        grafo[b].push_back({a,p});
    }

    pll preco[MAX];
    bool vis[MAX];

    for (int i = 1; i <= n; i++) {
        preco[i] = {INF, INF};
        vis[i] = false;
    }

    // sair de n e chegar em 1
    int ini = n;
    preco[ini] = {0, 0}; // com cupom, sem cupom

    priority_queue<ppl, vector<ppl>, greater<ppl>> fila;
    
    fila.push({{preco[ini]}, ini});

    while (!fila.empty()) {
        int s = fila.top().second;
        fila.pop();

        if (vis[s])
            continue;

        vis[s] = true;

        for (auto u: grafo[s]) {
            int f = u.first, p = u.second;

            pll preco_atual;

            ll p_sc = p + preco[s].first, p_cc = p/2 + preco[s].second;

            if (p_sc > p_cc) {
                preco_atual = {p_cc, (ll) p + preco[s].second};
            }
            else {
                preco_atual = {p_sc, (ll) p + preco[s].second};
            }

            if (preco[f] > preco_atual) {
                preco[f] = preco_atual;
                fila.push({preco_atual, f});
            }
        }
    }

    cout << preco[1].first << endl;

    return 0;
}