// Manchas de pele (OBI 2019)
// https://neps.academy/br/exercise/567

#include <bits/stdc++.h>
using namespace std;

#define MAX 1010

int n, m;
int mat[MAX][MAX];
bool vis[MAX][MAX] = {false};

int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};

void dfs(int i, int j) {
    if (vis[i][j])
        return;

    vis[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int posi = i + di[k], posj = j + dj[k];

        if (posi >= 0 and posi < n and posj >= 0 and posj < m) {
            if (mat[posi][posj] == 1)
                dfs(posi, posj);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int grupo = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0 or vis[i][j])
                continue;

            grupo++;
            dfs(i, j);
        }
    }

    cout << grupo << endl;

    return 0;
}