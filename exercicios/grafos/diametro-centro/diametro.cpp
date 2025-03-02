// Tree Diameter
// https://cses.fi/problemset/task/1131/

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

int n;
vector<int> grafo[MAX];
int d[MAX];

void dfs(int s, int p) {
    for (auto u: grafo[s]) {
        if (u == p)
            continue;

        d[u] = d[s] + 1;
        dfs(u, s);
    }
}

int main() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    dfs(1, 1);

    pair<int,int> ponta1 = {0, 0}, ponta2 = {0, 0};
    
    for (int i = 0; i <= n; i++) {
        if (d[i] > ponta1.first) 
            ponta1 = {d[i], i};
        d[i] = 0;
    }

    dfs(ponta1.second, ponta1.second);
    
    for (int i = 0; i <= n; i++) {
        if (d[i] > ponta2.first) 
            ponta2 = {d[i], i};
    }

    cout << ponta2.first << endl;

}