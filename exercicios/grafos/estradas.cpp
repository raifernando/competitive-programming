// Building Roads
// https://cses.fi/problemset/task/1666/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000 + 10

vector<int> adj[MAXN];
bool vis[MAXN];
int grupo[MAXN];
int qnt_grupos = 0;

void dfs(int s) {
    if (vis[s])
        return;

    vis[s] = true;
    grupo[s] = qnt_grupos;
    for (auto u: adj[s]) {
        dfs(u);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> cidades;
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;

        qnt_grupos++;
        dfs(i);
        cidades.push_back(i);
    }

    cout << (qnt_grupos-1) << endl;
    for (int i = 1; i < qnt_grupos; i++) {
        cout << cidades[0] << ' ' << cidades[i] << endl;
    }

    return 0;
}