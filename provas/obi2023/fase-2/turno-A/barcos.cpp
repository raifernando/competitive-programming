// Problema: Barcos da Nlogônia
// https://neps.academy/br/exercise/2439 

// Submissão com TLE

#include <bits/stdc++.h>
using namespace std;

#define sp ' '
#define INF 1000000007

typedef long long ll;
typedef pair<int,int> pii;

#define MAX 100010

int pessoas[MAX];
bool vis[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, b;
    cin >> n >> b;

    vector<pii> adj[n+5];

    for (int i = 0; i < b; i++) {
        int x, y, p;
        cin >> x >> y >> p;

        adj[x].push_back({y, p});
        adj[y].push_back({x, p});
    }   

    int t;
    cin >> t;

    while (t--) {
        int ini, fim;
        cin >> ini >> fim;

        for (int i = 0; i < (n+5); i++) {
            pessoas[i] = -1;
            vis[i] = false;
        }

        queue<int> q;
        q.push(ini);
        vis[ini] = true;

        while (!q.empty()) {
            int pai = q.front();
            q.pop();
            
            for (auto u: adj[pai]) {
                int vertice = u.first, q_pessoas = u.second;
                
                if (vertice == ini)
                    continue;

                if (pai == ini) {
                    q.push(vertice);
                    pessoas[vertice] = q_pessoas;
                    vis[vertice] = true;
                    continue;
                }

                if (vis[vertice]) {
                    if (min(pessoas[vertice], q_pessoas) > pessoas[pai]) {
                        pessoas[pai] = max(pessoas[pai], min(pessoas[vertice], q_pessoas));
                        q.push(pai);
                    }
                    
                    if (min(pessoas[pai], q_pessoas) > pessoas[vertice]) {
                        pessoas[vertice] = max(pessoas[vertice], min(pessoas[pai], q_pessoas));
                        q.push(vertice);
                    }
                }
                else {
                    vis[vertice] = true;
                    pessoas[vertice] = min(pessoas[pai], q_pessoas);
                    q.push(vertice);
                }
            }
        }

        cout << pessoas[fim] << endl;
    }

    return 0;
}