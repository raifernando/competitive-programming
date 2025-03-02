// Dijsktra?
// https://codeforces.com/problemset/problem/20/C

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define INF (ll) 2e50

int main() {
    int n, m;
    cin >> n >> m;

    const int MAX = n+1;

    vector<pii> adj[MAX];
    vector<int> origem(MAX);

    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;

        adj[a].push_back({b, p});
        adj[b].push_back({a, p});
    }

    ll dist[MAX];
    bool vis[MAX];

    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
        vis[i] = false;
    }

    priority_queue<pii, vector<pii>, greater<pii>> fila;

    fila.push({0, 1});
    dist[1] = 0;
    origem[1] = 0;

    while (!fila.empty()) {
        int s = fila.top().second;
        fila.pop();

        if (vis[s])
            continue;

        vis[s] = true;

        for (auto u: adj[s]) {
            int v = u.first, p = u.second;

            if (dist[v] > dist[s] + p) {
                dist[v] = dist[s] + p;
                origem[v] = s;

                fila.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << endl;
        return 0;
    }

    stack<int> s;

    s.push(n);

    int pos = n;
    while(pos != 1) {
        pos = origem[pos];
        s.push(pos);
    }

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

    cout << endl;

    return 0;
}