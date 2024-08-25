// Tarzan
// https://neps.academy/br/exercise/520

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define MAX 1010

int n, d;

vector<pii> grafo;
vector<bool> vis;

int dist(int i, int j, int a, int b) {
    double r = sqrt(pow(i-a, 2) + pow(j - b, 2));
    return ceil(r);
}

void dfs(int i, int j, int pos) {
    if (vis[pos])
        return;

    vis[pos] = true;

    for (int k = 0; k < n; k++) {
        if (k == pos)
            continue;
        
        if (dist(i, j, grafo[k].first, grafo[k].second) <= d)
            dfs(grafo[k].first, grafo[k].second, k);
    }
}

int main() {
    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        grafo.push_back({a,b});
        vis.push_back(false);
    }

    dfs(grafo[0].first, grafo[0].second, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << "N\n";
            return 0;
        }
    }

    cout << "S\n";
    return 0;
}