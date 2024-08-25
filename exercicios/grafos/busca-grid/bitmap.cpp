// Bitmap
// https://www.spoj.com/problems/BITMAP/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<pii, pii> ppp;

#define INF 1e9

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int d[n][m];
        bool vis[n][m];
        queue<ppp> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;

                int a = (c == '1');

                d[i][j] = INF;
                vis[i][j] = false;

                if (a) {
                    q.push({{i, j}, {i, j}});
                    d[i][j] = 0;
                }
            }
        }

        int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            pii s = q.front().first;
            int i = s.first, j = s.second;

            int branco_i = q.front().second.first, branco_j = q.front().second.second;
            q.pop();

            if (vis[i][j])
                continue;

            vis[i][j] = true;

            for (int k = 0; k < 4; k++) {
                int posi = i + di[k], posj = j + dj[k];

                if (posi < 0 or posj < 0 or posi >= n or posj >= m)
                    continue;

                d[posi][posj] = min(d[posi][posj], abs(branco_i - posi) + abs(branco_j - posj));
                q.push({{posi, posj}, {branco_i, branco_j}});
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << d[i][j] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}