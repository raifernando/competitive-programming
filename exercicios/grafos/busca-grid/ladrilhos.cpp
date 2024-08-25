// Ladrinhos
// https://neps.academy/br/exercise/122

#include <bits/stdc++.h>
using namespace std;

#define MAX 210

int n, m, grafo[MAX][MAX], area[MAX*MAX], id = 0;
bool vis[MAX][MAX];

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

void dfs(int i, int j) {
    if (vis[i][j])
        return;
        
    vis[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int posi = i + di[k], posj = j + dj[k];

        if (posi < 0 or posj < 0 or posi >= n or posj >= m)
            continue;

        if (grafo[posi][posj] != grafo[i][j]) 
            continue;

        if (vis[posi][posj])
            continue;

        area[id]++;
        dfs(posi, posj);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grafo[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j])
                continue;

            area[id] = 1;
            dfs(i, j);
            id++;
        }
    }

    int area_min = 1e9;
    for (int i = 0; i < id; i++) {
        area_min = min(area_min, area[i]);
    }

    cout << area_min << endl;

    return 0;
}