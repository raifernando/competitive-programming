// Móbile
// https://neps.academy/br/exercise/354

#include <bits/stdc++.h>
using namespace std;

int const MAX = 100000;
vector<int> adj[MAX + 5];
int visitados[MAX + 5];
queue<pair<int, int>> fila;

void dfs(int s) {
    if (visitados[s]) {
        return;
    }
    visitados[s] = 1;

    fila.push({s, adj[s].size()});

    for (auto u : adj[s]) {
        dfs(u);
        // dfs(u);
    } 
}

bool checar(int s) {
    if (adj[s].size() == 0)
        return true;
    
    bool balanceado = 1;
        set<int> qnt_filhos;
        for (auto u: adj[s]) {
            int tam = adj[u].size();
            qnt_filhos.insert(tam);
            balanceado = checar(u);
        }

        if (qnt_filhos.size() > 1) {
            return false;
        }


    

    return balanceado;
}

int main() {
    int n;
    cin >> n;

    int raiz;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;

        if (b == 0) {
            raiz = a;
            continue;
        }

        adj[b].push_back(a);
    }

    dfs(raiz);

    bool balanceado = checar(raiz);
    // for (int i = 0; i < n; i ++) {
    //     set<int> qnt_filhos;
    //     for (auto u: adj[raiz]) {
    //         int tam = adj[u].size();
    //         qnt_filhos.insert(u);
    //     }

    //     if (qnt_filhos.size() != 1) {
    //         balanceado = 0;
    //         break;
    //     }
    // }

    if (!balanceado)
        cout << "mal\n";
    else
        cout << "bem\n";

    return 0;
}
