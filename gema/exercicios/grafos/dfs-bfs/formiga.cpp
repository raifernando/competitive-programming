// Dona Formiga (Maior Número de Salões)
// https://neps.academy/br/exercise/1008

#include <bits/stdc++.h>
using namespace std;

int const MAX = 1e5;

vector<int> adj[MAX];
int visitado[MAX] = {0};

void dfs(int s) {
    if (visitado[s])
        return;
        
    visitado[s] = 1;
    for (auto u: adj[s]) 
        dfs(u);
}

int main() {
    int s, t, p; // qnt saloes, qnt tuneis, salao que parte
    cin >> s >> t >> p;

    vector<int> altura(s+1);

    for (int i = 1; i <= s; i++) {
        int h;
        cin >> h;

        altura[i] = h;
    }

    for (int i = 1; i <= t; i++) {
        int a, b;
        cin >> a >> b;

        if (altura[a] > altura[b])
            adj[a].push_back(b);
        else
            adj[b].push_back(a);
    }

    dfs(p);

    int quantidade = -1;
    for (int i = 1; i <= s; i++) {
        if (visitado[i])
            quantidade++;
    }

    cout << quantidade << endl;

    return 0;
}