// GINCANA
// https://neps.academy/br/exercise/309

#include <bits/stdc++.h>
using namespace std;

int const MAXN = 1000;
int const MAXM = 5000;

vector<int> adj[MAXN];
int visitado[MAXN + 10] = {0};

void dfs(int s) {
    if (visitado[s] == 1) return;
    visitado[s] = 1;

    for (auto u: adj[s]) {
        dfs(u);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    set<int> alunos;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);

        alunos.insert(a);
        alunos.insert(b);
    }

    int qnt = 0;
    dfs(*(alunos.begin()));
    qnt++;

    for (int i = 1; i <= n; i++) {
        if (alunos.find(i) == alunos.end()) {
            qnt++;
            continue;
        }

        if (visitado[i] == 0) {
            dfs(i);
            qnt++;
        }
    }
    
    cout << qnt << endl;

    return 0;
}