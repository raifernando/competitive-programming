// Toca do Saci
// https://neps.academy/br/exercise/57

#include <bits/stdc++.h>
using namespace std;

#define MAX 1010

typedef pair<int,int> pii;

int grafo[MAX][MAX];
int d[MAX][MAX];
bool vis[MAX][MAX];

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

int n, m;

void dfs(int i, int j) {
    if(vis[i][j]) 
        return;

    vis[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int posi = i + di[k], posj = j + dj[k];

        if (posi < 0 or posj < 0 or posi >= n or posj >= m)
            continue;

        if (grafo[posi][posj] == 0)
            continue;

        if (vis[posi][posj])
            continue;

        d[posi][posj] = d[i][j] + 1;

        dfs(posi, posj);
    }
}

int main() {
    cin >> n >> m;

    pii ini, fim;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;

            if (x == 2) 
                ini = {i, j};
            
            if (x == 3)
                fim = {i, j};

            grafo[i][j] = x;
        }
    }

    d[ini.first][ini.second] = 1;
    dfs(ini.first, ini.second);

    cout << d[fim.first][fim.second] << endl;

    return 0;
}