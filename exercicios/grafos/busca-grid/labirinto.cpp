// Labyrinth
// https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    char mat[n][m];

    pair<int,int> ini;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            
            mat[i][j] = c;

            if (c == 'A')
                ini = {i, j};
        }
    }

    bool vis[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = false;
        }
    }
    queue<pair<pair<int,int>, int>> q;
    vector<pair<char, int>> caminho;

    vis[ini.first][ini.second] = true;
    q.push({ini, 0});
    caminho.push_back({'A', -1});

    bool b_encontrado = false;

    int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
    string direcoes = "DURL";

    while(!q.empty() and !b_encontrado) {
        pair<int,int> coord = q.front().first;
        int pos = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int posi = coord.first + di[i], posj = coord.second + dj[i];

            if (posi < 0 or posi >= n or posj < 0 or posj >= m)
                continue;
             
            if (vis[posi][posj] == true)
                continue;

            vis[posi][posj] = true;

            char c = mat[posi][posj];
            if (c == '#') 
                continue;
                    
            caminho.push_back({direcoes[i], pos});

            if (c == 'B') {
                b_encontrado = true;
                break;
            }
                
            int pos_v = (int) caminho.size() - 1;

            q.push({{posi, posj}, pos_v});
        }
    }

    if (b_encontrado == false) {
        cout << "NO\n";
        return 0; 
    }

    stack<char> s;
    int tam = (int) caminho.size() - 1, pos = caminho[tam].second;

    s.push(caminho[tam].first);

    for (int i = tam; i >= 1; i--) {
        if (i == pos) {
            s.push(caminho[i].first);
            pos = caminho[i].second;
        }
    }

    cout << "YES\n" << s.size() << endl;
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }

    cout << endl;

    return 0;
}