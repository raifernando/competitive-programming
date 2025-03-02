// G - Longest Path
// https:/  /atcoder.jp/contests/dp/tasks/dp_g

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int grau[n + 1];
    vector<int> grafo[n+1];

    fill(grau, grau+n+1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        grafo[a].push_back(b);
        grau[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (grau[i] == 0)
            q.push(i);
    }

    int maior_r = 0;

    int caminho[n+1];
    fill(caminho, caminho + n + 1, 0);

    while (!q.empty()) {
        int s = q.front();
        q.pop();

        for (auto u: grafo[s]) {
            caminho[u] = max(caminho[u], caminho[s] + 1);

            grau[u]--;

            if (grau[u] == 0)
                q.push(u);

            maior_r = max(maior_r, caminho[u]);
        }
    }

    cout << maior_r << endl;

    return 0;
}