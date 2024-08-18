// Coleção de Upas
// https://neps.academy/br/exercise/568

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

    set<int> cores;
    vector<int> proibidas(n+1);

    int qnt = 0;

    for (int i = n; i > 0; i--) {
        if (i == n) {
            cores.insert(n);
            for (auto it = adj[n].begin(); it != adj[n].end(); it++) 
                proibidas[*it] = 1;
            
            qnt++;
            continue;
        }

        if (proibidas[i] == 1) 
            continue;

        cores.insert(i);
        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
            proibidas[*it] = 1;

        qnt++;
    }

    cout << qnt << endl;
    for (auto it = cores.begin(); it != cores.end(); it++)
        cout << *it << ' ';
    cout << endl;

    return 0;
}