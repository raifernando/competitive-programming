// COLORINDO
// https://neps.academy/br/exercise/535

#include <bits/stdc++.h>
using namespace std;

bool possivel_pintar(int a, int b, int n, int m, int mat) {
    if (a >= 1 and b >= 1 and a <= n and b <= m and mat == 0) return true;
    return false;
}

int main() {
    int n, m, xo, yo, k;
    cin >> n >> m >> xo >> yo >> k;

    int mat[n+1][m+1] = {0};
    queue<pair<int,int>> fila;
    
    fila.push({xo,yo});
    int qnt = 0;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        mat[a][b] = -1;
    }

    while (!fila.empty()) {
        int x = fila.front().first, y = fila.front().second;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 and j == 0) 
                    continue;

                int a = x + i, b = y + j;

                if (possivel_pintar(a, b, n, m, mat[a][b])) {
                    mat[a][b] = 1;
                    fila.push({a, b});
                    qnt++;
                }
            }
        }
        fila.pop();
    }

    if (qnt == 0) qnt = 1;
    cout << qnt << endl;
}