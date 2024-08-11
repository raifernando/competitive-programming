// Móbile
// https://neps.academy/br/exercise/354

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
int n;
vector<int> adj[MAXN];
bool vis[MAXN];
vector<int> qnt_pendurados(MAXN, 0);

void dfs(int s) {
    if (vis[s])
        return;

    vis[s] = true;
    for (auto u: adj[s]) {
        dfs(u);
        qnt_pendurados[s] += (qnt_pendurados[u]+1);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    int v_ini = 0;
    dfs(v_ini);

    queue<int> q;
    q.push(v_ini);

    bool ok = true;

    while (!q.empty() and ok) {
        int s = q.front();
        q.pop();

        set<int> pendurados;
        for (auto u: adj[s]) {
            q.push(u);
            pendurados.insert(qnt_pendurados[u]);
        }

        if (pendurados.size() > 1)
            ok = false;
    }

    if (ok) 
        cout << "bem\n"; 
    else
        cout << "mal\n";

    return 0;
}