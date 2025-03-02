// Desafio Cartográfico
// https://neps.academy/br/exercise/532

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000010

int n;
vector<int> grafo[MAX];
int d[MAX];
pair<int, int> maior = {0, 0};

void dfs(int s, int p) {
    for (auto u: grafo[s]) {
        if (u == p)
            continue;

        d[u] = d[s] + 1;
        if (maior.first < d[u]) {
            maior = {d[u], u};
        }

        dfs(u, s);
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

    dfs(1, 1);

    int v = maior.second;
    d[v] = 0;
    maior = {0, 0};

    dfs(v, v);

    cout << maior.first << endl;

    return 0;
}