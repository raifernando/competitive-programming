// Shortest Routes I
// https://cses.fi/problemset/task/1671/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pll;

#define INF (ll) 2e50

int main() {
    int n, m;
    cin >> n >> m;

    const int maxn = n+2;

    vector<pil> grafo[maxn];

    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;

        grafo[a].push_back({b, p});
    }

    ll d[maxn];
    bool vis[maxn];

    fill(d, d+maxn, INF);
    fill(vis, vis+maxn, false);

    priority_queue<pll, vector<pll>, greater<pll>> fila;

    fila.push({0, 1});
    d[1] = 0;

    while(!fila.empty()) {
        int s = fila.top().second;
        fila.pop();

        if (vis[s])
            continue;
        
        vis[s] = true;

        for (auto u: grafo[s]) {
            int v = u.first, p = u.second;

            if (d[v] > d[s] + p) {
                d[v] = d[s] + p;

                fila.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i] << ' ';
    }
    cout << endl;

    return 0;
}