// Graph Girth
// https://cses.fi/problemset/task/1707

#include <bits/stdc++.h>
using namespace std;

#define MAXN 2510
#define inf 1e9
#define sp ' '

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+10];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int min_ciclo = inf;
    for (int i = 1; i <= n; i++) {
        vector<int> dist(n+10, -1);
        queue<int> q;

        q.push(i);
        dist[i] = 0;

        while(!q.empty()) {
            int s = q.front();
            q.pop();

            for (auto u: adj[s]) {
                if (dist[u] == -1) {
                    dist[u] = dist[s] + 1;
                    q.push(u);
                }
                else if (dist[u] >= dist[s]) {
                    min_ciclo = min(min_ciclo, 1 + dist[u] + dist[s]);
                }
            }
        }
    }

    if (min_ciclo != inf)
        cout << min_ciclo << endl;
    else    
        cout << "-1\n";

    return 0;
}