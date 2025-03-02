// Uiquipédia
// https://neps.academy/br/exercise/606

#include <bits/stdc++.h>
using namespace std;

#define MAXN 5050

map<string, int> m;
int d[MAXN];
bool vis[MAXN];

vector<int> grafo[MAXN];
vector<pair<string, int>> palavras;

int main() {
    int n, id = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        if (m.find(a) == m.end()) {
            m[a] = id;
            palavras.push_back({a, id});
            id++; 

        }
        if (m.find(b) == m.end()) {
            m[b] = id;
            palavras.push_back({b, id});
            id++; 
        }

        grafo[m[a]].push_back(m[b]);
    }

    sort(palavras.begin(), palavras.end());

    string ini, fim;
    cin >> ini >> fim;

    if (m.find(ini) == m.end()) {
        m[ini] = id;
        palavras.push_back({ini, id});
        id++; 
    }

    if (m.find(fim) == m.end()) {
        m[fim] = id;
        palavras.push_back({fim, id});
        id++; 
    }

    int pi = m[ini], pf = m[fim];

    for (int i = 1; i < (int) palavras.size(); i++) {
        grafo[palavras[i].second].push_back(palavras[i-1].second);
        grafo[palavras[i-1].second].push_back(palavras[i].second);
    }

    for (int i = 0; i <= (id+1); i++) 
        d[i] = 1e9;

    queue<int> q;
    q.push(pi);

    d[pi] = 0;

    while (!q.empty()) {
        int s = q.front();
        q.pop();

        if (vis[s])
            continue;
        
        vis[s] = true;

        for (auto u: grafo[s]) {
            d[u] = min(d[u], d[s] + 1);
            q.push(u);
        }
    }

    cout << d[pf] << endl;

    return 0;
}