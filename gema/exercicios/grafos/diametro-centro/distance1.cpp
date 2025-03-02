// Tree Distances I
// https://cses.fi/problemset/task/1132

#include <bits/stdc++.h>
using namespace std;

#define MAX (int) 1e6

typedef pair<int,int> pii;

int n;
vector<int> grafo[MAX];
int d[3][MAX];
pii melhor = {0, 0};

void dfs(int s, int p, int i) {
    for (auto u: grafo[s]) {
        if (u == p)
            continue;

        d[i][u] = d[i][s] + 1;
        if (melhor.first < d[i][u])
            melhor = {d[i][u], u};

        dfs(u, s, i);
    }
}

int main() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    int fim1;
    dfs(1, 1, 0);

    fim1 = melhor.second;

    melhor = {0, 0};
    dfs(fim1, fim1, 1);

    int fim2 = melhor.second;

    melhor = {0, 0};
    dfs(fim2, fim2, 2);

    for (int i = 1; i <= n; i++) {
        cout << max(d[1][i], d[2][i]) << ' ';
    }
    
    cout << endl;

    return 0;

}