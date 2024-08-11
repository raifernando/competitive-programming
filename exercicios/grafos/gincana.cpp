// GINCANA
// https://neps.academy/br/exercise/309

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1010

int n, m, qnt = 0;
vector<int> adj[MAX_N];
bool visitado[MAX_N];

void dfs(int s) {
    if (visitado[s])
        return;

    visitado[s] = true;
    for (auto u: adj[s])
        dfs(u);
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (visitado[i] == false)
            qnt++;
        dfs(i);
    }

    cout << qnt << "\n";

    return 0;
}