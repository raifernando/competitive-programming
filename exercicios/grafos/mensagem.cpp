// Message Route
// https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> fila;
    fila.push(1);

    bool visitados[n+1];
    visitados[1] = true;

    int distancia[n+1] = {0};
    distancia[1] = 0;

    vector<int> ordem;

    while (!fila.empty()) {
        int s = fila.front(); 
        fila.pop();

        for (auto u: adj[s]) {
            if (visitados[u] == true) continue;
            visitados[u] = true;

            distancia[u] = distancia[s] + 1;
            fila.push(u);

            ordem.push_back(u);
        }
    }

    int min_dist = distancia[n];

    if (min_dist == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << min_dist + 1 << endl;

    auto it = find(ordem.begin(), ordem.end(), n);
    advance(it, -(min_dist -1));

    cout << 1 << ' ';
    for (int i = 0; i < min_dist; i++) {
        cout << *it << ' ';
        it++;
    }
    cout << endl;

    for (int i = 0; i < (int) ordem.size(); i++) {
        cout << ordem[i] << endl;
    }

}