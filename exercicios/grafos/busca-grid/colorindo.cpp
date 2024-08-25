// Colorindo
// https://neps.academy/br/exercise/535

#include <bits/stdc++.h>
using namespace std;

#define MAX 205

int n, m;

int tab[MAX][MAX];
bool vis[MAX][MAX];

int di[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int i, int j) {
    if (vis[i][j])
        return;

    vis[i][j] = true;

    for (int k = 0; k < 8; k++) {
        int posi = i + di[k], posj = j + dj[k];

        if (posi <= 0 or posj <= 0 or posi > n or posj > m) 
            continue;

        if (tab[posi][posj])
            continue;

        dfs(posi, posj);
    }
}

int main() {
    int x, y, k;
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        tab[a][b] = 1;
    }

    dfs(x, y);

    int pintados = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pintados += vis[i][j];
        }
    }

    cout << pintados << endl;

    return 0;
}