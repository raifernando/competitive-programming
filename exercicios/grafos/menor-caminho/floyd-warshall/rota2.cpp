// Shortest Routes II
// https://cses.fi/problemset/task/1672

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

#define INF (ll) 1e15
#define MAX 502

int n, m;
ll mat[MAX][MAX];

void floyd_warshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[j][k]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                mat[i][j] = 0;
            else 
                mat[i][j] = INF;
        }
    }

    for (int i = 1; i <= m; i++) {
        int a, b, p;
        cin >> a >> b >> p;

        mat[a][b] = min((ll) p, mat[a][b]);
        mat[b][a] = min((ll) p, mat[b][a]);
    }

    floyd_warshall();

    while (q--) {
        int ini, fim;
        cin >> ini >> fim;

        if (abs(mat[ini][fim]) == INF)
            cout << -1 << endl;
        else
            cout << mat[ini][fim] << endl;
    }

    return 0;
}