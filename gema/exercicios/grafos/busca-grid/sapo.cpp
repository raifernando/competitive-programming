// Sr. Sapo (OBI 2021)
// https://neps.academy/br/exercise/1775

#include <bits/stdc++.h>
using namespace std;

#define MAX 105
#define PULO_MAX 3

typedef pair<int,int> pii;

int n, m, p;
int mat[MAX][MAX] = {0};
bool vis[MAX][MAX] = {false};

pii ini, fim;

int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};

void dfs(pii s) {
    int i = s.first, j = s.second; 
    if (vis[i][j] == true) 
        return;

    vis[i][j] = true;

    for (int t = 0; t < 4; t++) {
        for (int k = 1; k <= PULO_MAX; k++) {
            int posi = i + k*di[t], posj = j + k*dj[t];

            if (posi <= 0 or posj <= 0 or posi > n or posj > m)
                continue;

            if (vis[posi][posj])
                continue;

            if (mat[posi][posj] == 1)
                dfs({posi, posj});
        }
    }
}

int main() {
    cin >> n >> m >> p;

    for (int i = 1; i <= p; i++) {
        int a, b;
        cin >> a >> b;

        mat[a][b] = 1;
    }

    int a, b;
    cin >> a >> b;
    ini = {a, b};

    cin >> a >> b;
    fim = {a, b};

    dfs({ini.first, ini.second});

    if (vis[fim.first][fim.second] == true) {
        cout << "S\n";
        return 0; 
    }

    cout << "N\n";

    return 0;
}