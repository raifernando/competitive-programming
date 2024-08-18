// Problema: Dança

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    int mat[n+1][m+1], pos = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mat[i][j] = pos;
            pos++;
        }
    }
    
    int coluna[m+1], linha[n+1];
    for (int i = 1; i <= n; i++) {
        linha[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        coluna[i] = i;
    }

    while (p--) {
        char c;
        int a, b;
        cin >> c >> a >> b;

        if (c == 'C') 
            swap(coluna[a], coluna[b]);
        
        if (c == 'L') 
            swap(linha[a], linha[b]);
    }

     for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mat[linha[i]][coluna[j]] << ' ';
        }
        cout << endl;
    }

    return 0;
}