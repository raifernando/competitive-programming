// Setas (OBI 2014)
// https://neps.academy/br/exercise/386

#include <bits/stdc++.h>
using namespace std;

#define MAX 510

typedef pair<int,int> pii;

int n;
char mat[MAX][MAX];
bool segura[MAX][MAX];
bool vis[MAX][MAX];

char mov[4] = {'>', '<', 'A', 'V'};
pii pos_mov[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool dfs(int i, int j) {
    if (segura[i][j] == false)
        return false;
    if (vis[i][j])
        return true;

    vis[i][j] = true;

    int posi = i, posj = j;
    switch(mat[i][j]) {
        case '>': posj++; break;
        case '<': posj--; break;
        case 'A': posi--; break;
        case 'V': posi++; break; 
    }

    bool ok = dfs(posi, posj);
    if (ok)
        return true;

    segura[i][j] = false;
    return false;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            segura[i][j] = true;
        }
    }

    int cel_seguras = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dfs(i, j);
            cel_seguras += segura[i][j];
        }
    }

    cout << cel_seguras << endl;

    return 0;
}
