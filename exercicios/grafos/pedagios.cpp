// Pedágio (OBI 2002)
// https://neps.academy/br/exercise/643

#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, e, l, p;
    cin >> c >> e >> l >> p;
    int id_teste = 1;

    while (true) {
        if ((c+e+l+p) == 0)
            break;

        vector<int> adj[c+5];
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bool vis[c+5] = {false};
        queue<pair<int,int>> q;

        vis[l] = true;
        q.push({l, 0});

        set<int> cidades;

        while (!q.empty()) {
            int s = q.front().first, bloco = q.front().second;
            q.pop();

            for (auto u: adj[s]) {
                if (vis[u])
                    continue;
                
                vis[u] = true;

                if (bloco < p) {
                    q.push({u, bloco+1});

                    cidades.insert(u);
                }
            }
        }

        cout << "Teste " << id_teste << endl;
        for (auto it = cidades.begin(); it != cidades.end(); it++) {
            cout << *it << ' ';
        }
        cout << endl << endl;

        id_teste++;
        cin >> c >> e >> l >> p;
    }

    return 0;
}