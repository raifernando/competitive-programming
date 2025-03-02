// Desvio de Rota
// https://neps.academy/br/exercise/296

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

#define INF 10000000

int main() {
    while(true) {
        int n, m, c, k;
        cin >> n >> m >> c >> k;

        if (n + m + c + k == 0)
            break;

        vector<pii> grafo[n];

        for (int i = 0; i < m; i++) {
            int a, b, p;
            cin >> a >> b >> p;

            grafo[a].push_back({b, p});
            grafo[b].push_back({a, p});
        }

        priority_queue<pii, vector<pii>, greater<pii>> fila;
        bool vis[n];
        int dist[n];
        
        for (int i = 0; i < n; i++) {
            vis[i] = false;
            dist[i] = INF;
        }
        
        fila.push({0, k});
        dist[k] = 0;

        while (!fila.empty()) {
            int s = fila.top().second;
            fila.pop();

            if (vis[s]) 
                continue;

            vis[s] = true;

            for (auto u: grafo[s]) {
                int p = u.second, f = u.first;

                if (s <= c-1 and f > s+1)
                    continue;

                if (dist[f] > dist[s] + p) {
                    dist[f] = dist[s] + p;
                    fila.push({dist[f], f});
                }
            }
        }

        int p_rota[c];
        p_rota[c-1] = 0;

        for (int i = c-1; i >= 0; i--) {
            for (auto u: grafo[i]) {
                if (u.first == i - 1) {
                    p_rota[i-1] = p_rota[i] + u.second;
                    break;
                }
            }
        }

        int min_caminho = INF;

        for (int i = 0; i < c; i++) {
            min_caminho = min(min_caminho, dist[i] + p_rota[i]);
        }

        cout << min_caminho << endl;
    }

    return 0;
}