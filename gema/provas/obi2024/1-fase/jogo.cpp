#include <bits/stdc++.h>
using namespace std;

int const MAX = 50;

int mat[MAX + 1][MAX + 1];

int checar_vizinhos(int i, int j, int n) {
    n--;
    int qnt = 0;
    for (int q = -1; q <= 1; q++) {
        for (int r = -1; r <= 1; r++) {
            if (q == r and q == 0) 
                continue;   

            int x = i+q, y = j+r;
            if (x >= 0 and x <= n and y >= 0 and y <= n) {
                if (mat[x][y] == 1)
                    qnt++;
            }
        }
    }
    return qnt;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        char entrada[n+1];
        cin >> entrada;
        for (int j = 0; j < n; j++) {
            int a = entrada[j];
            mat[i][j] = a - '0';
        }
    }

    int mat_vivas[n][n];

    while (q != 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int vivas = checar_vizinhos(i, j, n);
                mat_vivas[i][j] = vivas;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int vivas = mat_vivas[i][j];
                if (mat[i][j] == 0) {
                    if (vivas == 3) {
                        mat[i][j] = 1;
                    }
                    continue;
                }

                if (vivas < 2 or vivas > 3)
                    mat[i][j] = 0;
            }
        }

        q--;
    }

    for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j];
            }
            cout << endl;
        }

    return 0;
}