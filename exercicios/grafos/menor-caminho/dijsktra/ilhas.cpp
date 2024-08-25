// ILhas
// https://neps.academy/br/exercise/183

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

#define INF 10000000

int main() {
    int n, m;
    cin >> n >> m;

    const int MAX = n+10;

    vector<pii> grafo[MAX];

    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;

        grafo[a].push_back({b, p});
        grafo[b].push_back({a, p});
    }

    int servidor;
    cin >> servidor;

    int min_ping = INF, max_ping = 0, ping[MAX];
    bool vis[MAX];

    for (int i = 0; i < MAX; i++) {
        ping[i] = INF;
        vis[i] = false;
    }

    priority_queue<pii, vector<pii>, greater<pii>> fila;
    fila.push({0, servidor});

    ping[servidor] = 0;

    while (!fila.empty()) {
        int s = fila.top().second;
        fila.pop();

        if (vis[s])
            continue;

        vis[s] = true;

        for (auto u: grafo[s]) {
            int p = u.second, ilha = u.first;

            if (ping[ilha] > ping[s] + p) {
                ping[ilha] = ping[s] + p;
                fila.push({ping[ilha], ilha});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == servidor)
            continue;

        min_ping = min(min_ping, ping[i]);
        max_ping = max(max_ping, ping[i]);
    }

    cout << max_ping - min_ping << endl;

    return 0;
}