// Message Route
// https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n, m;
vector<int> adj[MAXN];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    vector<pair<int,int>> caminho;
    bool vis[n+1] = {false};

    q.push(1);
    vis[1] = true;
    caminho.push_back({1,0});

    int achado = false;
    while(!q.empty()) {
        int s = q.front();
        q.pop();

        for (auto u: adj[s]) {
            if (vis[u])
                continue;

            vis[u] = true;
            q.push(u);
            caminho.push_back({u, s});

            if(u == n)
                achado = true;
        }

        if (achado)
            break;
    }

    if (!achado) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    stack<int> pilha;
    int anterior = caminho[((int) caminho.size()) - 1].second;
    pilha.push(n);

    for (int i = (int) caminho.size() - 1; i >= 0; i--) {
        if (caminho[i].first == anterior) {
            pilha.push(anterior);
            anterior = caminho[i].second;
        }
    }

    cout << pilha.size() << endl;
    while(!pilha.empty()) {
        cout << pilha.top() << ' ';
        pilha.pop();
    }

    cout << endl;

    return 0;
}