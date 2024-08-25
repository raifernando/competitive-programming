// Monsters
// https://cses.fi/problemset/task/1194

#include <bits/stdc++.h>
using namespace std;

#define INF (int) 1e9 

typedef pair<int, int> pii;
typedef pair<pii, char> ppc;

int main() {
    int n, m;
    cin >> n >> m;

    char grafo[n][m];
    int t_mostros[n][m], t_saida[n][m];

    char dir[4] = {'U', 'R', 'D', 'L'};
    int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
    bool vis_mostros[n][m], vis_saida[n][m];

    ppc caminho[n][m];

    queue<pii> fila, fila_mostros, finais;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;

            grafo[i][j] = c;
            t_mostros[i][j] = INF;
            t_saida[i][j] = INF;
            vis_mostros[i][j] = false;
            vis_saida[i][j] = false;

            if (c == 'A') {
                fila.push({i, j});
                t_saida[i][j] = 0;
                caminho[i][j] = {{-1, -1}, '\0'};
            }

            if (c == 'M') {
                fila_mostros.push({i, j});
                t_mostros[i][j] = 0;
            }

            if (i == 0 or j == 0 or i == n-1 or j == m-1) {
                if (c == '.' or c == 'A')
                    finais.push({i, j});
            }
        }
    }

    while(!fila_mostros.empty()) {
        int i = fila_mostros.front().first, j = fila_mostros.front().second;
        fila_mostros.pop();

        if (vis_mostros[i][j])
            continue;

        vis_mostros[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int posi = i + di[k], posj = j + dj[k];

            if (posi < 0 or posj < 0 or posi >= n or posj >= m)
                continue;

            if (grafo[posi][posj] == '#')
                continue;

            if (t_mostros[posi][posj] > t_mostros[i][j] + 1) {
                t_mostros[posi][posj] = min(t_mostros[posi][posj], t_mostros[i][j] + 1);
                fila_mostros.push({posi, posj});
            }
        }
    }

    while(!fila.empty()) {
        int i = fila.front().first, j = fila.front().second;
        fila.pop();

        if (vis_saida[i][j])
            continue;

        vis_saida[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int posi = i + di[k], posj = j + dj[k];

            if (posi < 0 or posj < 0 or posi >= n or posj >= m)
                continue;

            if (grafo[posi][posj] == '#')
                continue;

            if (t_saida[posi][posj] > t_saida[i][j] + 1) {
                if (t_saida[i][j] + 1 >= t_mostros[posi][posj])
                    continue;
                t_saida[posi][posj] = t_saida[i][j] + 1;
                caminho[posi][posj] = {{i, j}, dir[k]};
            }

            fila.push({posi, posj});
        }
    }

    pair<int, pii> t_min = {INF, {-1, -1}};

    while(!finais.empty()) {
        pii s = finais.front();
        finais.pop();

        if (!vis_saida[s.first][s.second]) 
            continue;

        if (t_saida[s.first][s.second] < t_min.first) 
            t_min = {t_saida[s.first][s.second], {s}};
    }

    if (t_min.first == INF) {
        cout << "NO\n";
        return 0;
    }

    stack<char> pilha;

    pii s = caminho[t_min.second.first][t_min.second.second].first;
    char volta = caminho[t_min.second.first][t_min.second.second].second;
    
    while (volta != '\0') {
        pilha.push(volta);

        volta = caminho[s.first][s.second].second;
        s = caminho[s.first][s.second].first;
    }

    cout << "YES\n" << t_min.first << endl;
    while (!pilha.empty()) {
        cout << pilha.top();
        pilha.pop();
    }

    if (t_min.first)
        cout << endl;

    return 0;
}