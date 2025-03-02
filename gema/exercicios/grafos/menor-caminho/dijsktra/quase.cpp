// Quase menor caminho
// https://br.spoj.com/problems/QUASEMEN/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, ll> pil;
typedef pair<pii, int> ppi;
typedef pair<ll,ll> pll;
typedef pair<pll, int> ppl;

#define INF 100000000

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;

        if (n + m == 0)
            break;

        int ini, fim;
        cin >> ini >> fim;

        const int maxn = n + 2;

        vector<pii> grafo_ida[maxn], grafo_volta[maxn];

        for (int i = 0; i < m; i++) {
            int a, b, p;
            cin >> a >> b >> p;

            grafo_ida[a].push_back({b,p});
            grafo_volta[b].push_back({a,p});
        }

        priority_queue<pii, vector<pii>, greater<pii>> fila;      
        
        // ini -> fim
        fila.push({0, ini});

        bool vis[maxn];
        int d[2][maxn];

        for (int i = 0; i < maxn; i++) {
            vis[i] = false;
            d[0][i] = INF;
            d[1][i] = INF;
        }

        d[0][ini] = 0;

        while(!fila.empty()) {
            int s = fila.top().second;
            fila.pop();

            if (vis[s])
                continue;

            vis[s] = true;

            for (auto u: grafo_ida[s]) {
                int v = u.first, p = u.second;

                if (d[0][v] > d[0][s] + p) {
                    d[0][v] = d[0][s] + p;

                    fila.push({d[0][v], v});
                }
            }
        }

        int caminho_min = d[0][fim];

        // fim -> ini
        for (int i = 0; i < maxn; i++) {
            vis[i] = false;
        }

        fila.push({0, fim});
        d[1][fim] = 0;

        while(!fila.empty()) {
            int s = fila.top().second;
            fila.pop();

            if (vis[s])
                continue;

            vis[s] = true;

            for (auto u: grafo_volta[s]) {
                int v = u.first, p = u.second;

                if (d[1][v] > d[1][s] + p) {
                    d[1][v] = d[1][s] + p;

                    fila.push({d[1][v], v});
                }
            }
        }

        // ini -> fim, sem passar por caminhos minimos
        fila.push({0, ini});

        int d_min[maxn];

        for (int i = 0; i < maxn; i++) {
            vis[i] = false;
            d_min[i] = INF;
        }

        d_min[ini] = 0;


        while(!fila.empty()) {
            int s = fila.top().second;
            fila.pop();

            if (vis[s])
                continue;

            vis[s] = true;

            for (auto u: grafo_ida[s]) {
                int v = u.first, p = u.second;

                if (s == ini and v == fim)
                    continue;

                if (d[0][s] + d[1][v] + p == caminho_min)
                    continue;

                if (d_min[v] > d_min[s] + p) {
                    d_min[v] = d_min[s] + p;

                    fila.push({d_min[v], v});
                }
            }
        }

        if (d_min[fim] == INF)
            cout << -1 << endl;
        else
            cout << d_min[fim] << endl;
    }

    return 0;
}