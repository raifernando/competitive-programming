// Cryptography
// https://codeforces.com/gym/101845/problem/C

#include <bits/stdc++.h>
using namespace std;

#define MAXTAM 130
#define MIN 33
#define MAX 126
#define INF 1e5

int mat[MAXTAM][MAXTAM];

void floyd_marshall() {
    for (int k = MIN; k <= MAX; k++) {
        for (int i = MIN; i <= MAX; i++) {
            for (int j = MIN; j <= MAX; j++) {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
}

int main() {
    int m;

    string ori, crip;
    cin >> ori >> crip >> m;

    for (int i = MIN; i <= MAX; i++) {
        for (int j = MIN; j <= MAX; j++) {
            mat[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        char a, b;
        int c;

        cin >> a >> b >> c;

        int x = a, y = b;

        mat[x][y] = min(mat[x][y], c);
    }

    int custo = 0;
    bool possivel = true;

    floyd_marshall();

    for (int i = 0; i < (int) ori.size(); i++) {
        int a = ori[i], b = crip[i];

        if (a == b)
            continue;

        if (mat[a][b] == INF) {
            possivel = false;
            break;
        }

        custo += mat[a][b];
    }

    if (possivel)
        cout << custo << endl;
    else 
        cout << -1 << endl;

    return 0;
}