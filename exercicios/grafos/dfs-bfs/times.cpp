// Building Teams
// https://cses.fi/problemset/task/1668/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, char> pic;

#define INF 1e9
#define MAXN 100010

int n;
vector<int> grafo[MAXN];
int times[MAXN];
bool vis[MAXN];

bool possivel = true;

void dfs(int s, int time) {
    if (vis[s])
        return;

    vis[s] = true;

    for (auto u: grafo[s]) {
        if (times[u] == time) {
            possivel = false;
            return;
        }

        int outro_time = (time == 1) ? 2 : 1;
        
        times[u] = outro_time;
        dfs(u, outro_time);
    }
}

int main() {
    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (times[i] != 0)
            continue;

        times[i] = 1;
        dfs(i, 1);
    }

    if (possivel) {
        for (int i = 1; i <= n; i++) {
            cout << times[i] << ' ';
        }
        cout << endl;
    }
    else 
        cout << "IMPOSSIBLE\n";
    
    return 0;
}