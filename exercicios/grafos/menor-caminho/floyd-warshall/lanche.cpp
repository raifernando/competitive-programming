// Lanche na Empresa (OBI 2008)
// https://neps.academy/br/exercise/307

#include <bits/stdc++.h>
using namespace std;

#define MAXN 255
#define INF 1e9

int s;

int mat[MAXN][MAXN];

void floyd_warshall() {
    for (int k = 1; k <= s; k++) {
        for (int i = 1; i <= s; i++) {
            for (int j = 1; j <= s; j++) {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[j][k]);
            }
        }
    }
}

int main() {
    int c;
    cin >> s >> c;

    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= s; j++) {
            if (i == j)
                mat[i][j] = 0;
            
            mat[i][j] = INF;
        }   
    }   

    for (int i = 0; i < c; i++) {
        int a, b, d;
        cin >> a >> b >> d;

        mat[a][b] = min(mat[a][b], d);
        mat[b][a] = min(mat[b][a], d);
    }

    int min_d = INF;

    floyd_warshall();

    for (int i = 1; i <= s; i++) {
        int max_local = 0;
        for (int j = 1; j <= s; j++) {
            if (i == j)
                continue;
            
            max_local = max(max_local, mat[i][j]);
        }

        min_d = min(min_d, max_local);
    }

    cout << min_d << endl;

    return 0;
}