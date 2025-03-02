// Escalonamento Ótimo
// https://neps.academy/br/exercise/331

#include <bits/stdc++.h>
using namespace std;

#define MAXN 50010

int n, m;
vector<int> grafo[MAXN];
bool vis[MAXN], ciclo = false;
int grau[MAXN];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        grau[b]++;
        grafo[a].push_back(b);
    }

    priority_queue<int, vector<int>, greater<int>> fila;
    for (int i = 0; i < n; i++) {
        if (grau[i] == 0) {
            fila.push(i);
        }
    }

    if (fila.empty()) {
        cout << "*\n";
        return 0;
    }

    bool vis[n+1];
    fill (vis, vis+n+1, false);

    queue<int> r;

    while (!fila.empty()) {
        int s = fila.top();
        fila.pop();

        r.push(s);

        if (vis[s]) {
            ciclo = true;
            break;
        }
        
        vis[s] = true;

        for (auto u: grafo[s]) {
            grau[u]--;

            if (grau[u] == 0)
                fila.push(u);
        }
    }

    bool possivel = true;

    for (int i = 0; i < n; i++) {
        if (grau[i] != 0)
            possivel = false;
    }

    if (ciclo or !possivel) {
        cout << "*\n";
        return 0;
    }

    while(!r.empty()) {
        cout << r.front() << endl;
        r.pop();
    }

    return 0;
}


