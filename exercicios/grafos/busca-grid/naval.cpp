// Batalha Naval
// https://neps.academy/br/exercise/543

#include <bits/stdc++.h>
using namespace std;

#define MAX 110

int n, m;

char tab[MAX][MAX];
bool vis[MAX][MAX], baleado[MAX][MAX];

void dfs(int i, int j, bool *ok) {
    if (vis[i][j]) 
        return;

    vis[i][j] = true;

    if (!baleado[i][j]) 
        *ok = false;
    
    int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
    for (int k = 0; k < 4; k++) {
        int posi = i + di[k], posj = j + dj[k];

        if (posi <= 0 or posj <= 0 or posi > n or posj > m)
            continue;

        if (tab[posi][posj] == '.')
            continue;

        dfs(posi, posj, ok);
    }

    return;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> tab[i][j];
        }
    }

    int destruidos = 0;

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        if (tab[a][b] == '.')
            continue;

        baleado[a][b] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] or tab[i][j] == '.')
                continue;

            bool ok = true;

            dfs(i, j, &ok);

            if(ok)
                destruidos++;
        }
    }

    cout << destruidos << endl;

    return 0;
}