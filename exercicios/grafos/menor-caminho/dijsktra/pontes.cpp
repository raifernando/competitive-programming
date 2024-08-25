// Caminho das pontes
// https://neps.academy/br/exercise/297

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

#define INF 10000000

int main() {
    int n, m;
    cin >> n >> m;

    vector<pii> grafo[n+5];

    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;

        grafo[a].push_back({b,p});
        grafo[b].push_back({a,p});
    }

    int dist[n+5];
    bool vis[n+5];

    for (int i = 0; i < (n+5); i++) {
        dist[i] = INF;
        vis[i] = false;
    }

    priority_queue<pii, vector<pii>, greater<pii>> fila;
    fila.push({0,0});
    dist[0] = 0;
    
    while (!fila.empty()) {
        int pai = fila.top().second;
        fila.pop();

        if (vis[pai])
            continue;

        vis[pai] = true;

        for (auto u: grafo[pai]) {
            int f_dist = u.second, filho = u.first;

            if (dist[filho] > dist[pai] + f_dist) {
                dist[filho] = dist[pai] + f_dist;
                fila.push({dist[filho], filho});
            }
        }
    }

    cout << dist[n+1] << endl;

    return 0;
}   