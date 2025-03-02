// Mina
// https://neps.academy/br/exercise/65

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int, pii> ppi;

#define INF 10000000

int main() {
    int n;
    cin >> n;

    int tab[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tab[i][j];
        }
    }

    int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};

    bool vis[n][n];
    int dist[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vis[i][j] = false;
            dist[i][j] = INF;
        }
    }

    priority_queue<ppi, vector<ppi>, greater<ppi>> fila;
    fila.push({0, {0,0}});
    dist[0][0] = 0;

    while (!fila.empty()) {
        pii u = fila.top().second;
        fila.pop();

        if (vis[u.first][u.second])
            continue;

        vis[u.first][u.second] = true;

        for (int i = 0; i < 4; i++) {
            int posi = u.first + di[i], posj = u.second + dj[i];

            if (posi < 0 or posj < 0 or posi >= n or posj >= n) 
                continue;

            if (dist[posi][posj] > dist[u.first][u.second] + tab[posi][posj]) {
                dist[posi][posj] = dist[u.first][u.second] + tab[posi][posj];
                fila.push({dist[posi][posj], {posi, posj}});
            }
        }
    }

    cout << dist[n-1][n-1] << endl;

    return 0;
}