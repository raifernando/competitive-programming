// Counting Rooms
// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
using namespace std;

#define MAX 1010

typedef pair<int,int> pii;

int n, m;
char mat[MAX][MAX];
bool vis[MAX][MAX];

vector<pii> chao;

int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};

void dfs(pii coord) {
    int i = coord.first, j = coord.second;

    if (vis[i][j])
        return;

    vis[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int posi = i + di[k], posj = j + dj[k];

        if (posi < 0 or posj < 0 or posi >= n or posj >= m)
            continue;

        char c = mat[posi][posj];

        if (c == '.')
            dfs({posi, posj});    
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;

            mat[i][j] = c;

            if (c == '.')
                chao.push_back({i, j});
        }
    }

    int tam = chao.size(), grupos = 0;

    for (int i = 0; i < tam; i++) {
        pii coord = chao[i];
        if (vis[coord.first][coord.second])
            continue;

        dfs(coord);
        grupos++;
    }

    cout << grupos << endl;

    return 0;
}
