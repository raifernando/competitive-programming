// Chuva (OBI 2019)
// https://neps.academy/br/exercise/469

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, char> pic;

#define INF 1e9

int main() {
    int n, m;
    cin >> n >> m;

    char tab[n][m];
    bool vis[n][m];
    pii ini;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;

            if (c == 'o')
                ini = {i, j};

            tab[i][j] = c;
            vis[i][j] = false;
        }
    }

    queue<pii> q;
    q.push(ini);

    int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();

        if (vis[i][j]) 
            continue;
        
        vis[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int posi = i + di[k], posj = j + dj[k];

            if (posi < 0 or posj < 0 or posi >= n or posj >= m)
                continue;

            if (tab[posi][posj] == '#')
                continue;

            bool escorre = false;

            if (posi - 1 >= 0) 
                if (tab[posi-1][posj] == 'o') 
                    escorre = true;

            if (posj - 1 >= 0 and posi + 1 < n) 
                if (tab[posi][posj-1] == 'o' and tab[posi+1][posj-1] == '#') 
                    escorre = true;

            if (posj + 1 < m and posi + 1 < n) 
                if (tab[posi][posj+1] == 'o' and tab[posi+1][posj+1] == '#') 
                    escorre = true;
            
            if (escorre) {
                tab[posi][posj] = 'o';
                q.push({posi, posj});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << tab[i][j];
        }
        cout << endl;
    }

    return 0;
}