// Fox and Names
// https://codeforces.com/problemset/problem/510/C

#include <bits/stdc++.h>
using namespace std;

#define MAX 26

int main() {
    int n;
    cin >> n;

    vector<string> palavras(n);
    vector<char> grafo[MAX];
    int grau[MAX];
    fill(grau, grau+MAX, 0);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        palavras[i] = s;
    }

    bool ciclo = false;

    for (int i = 1; i < n; i++) {
        int k = strcmp(palavras[i-1].c_str(), palavras[i].c_str());
        if (k == 0)
            continue;

        int tam1 = strlen(palavras[i-1].c_str()), tam2 = strlen(palavras[i].c_str());

        int min_tam = min(tam1, tam2);

        if (palavras[i-1][0] != palavras[i][0]) {
            grau[palavras[i][0] - 'a']++;
            grafo[palavras[i-1][0]-'a'].push_back(palavras[i][0]);
            continue;
        }

        bool ok = false;
        for (int j = 1; j < min_tam; j++) {
            char c1 = palavras[i-1][j], c2 = palavras[i][j];

            if (c1 == c2) 
                continue;

            grafo[c1-'a'].push_back(c2);
            grau[c2-'a']++;
            ok = true;
            break;
        }

        if (tam1 > tam2 and !ok)
            ciclo = true;
    }

    priority_queue<char, vector<char>, greater<char>> fila;

    bool vis[MAX];
    fill(vis, vis+MAX, false);

    for (int i = 0; i < MAX; i++) {
        if (grau[i] == 0) {
            fila.push(i+'a');
        }
    }

    queue<char> r;

    while (!fila.empty()) {
        int c = fila.top();
        fila.pop();

        r.push(c);

        if (vis[c-'a']) {
            ciclo = true;
            break;
        }

        vis[c-'a'] = true;  

        for (auto u: grafo[c-'a']) {
            grau[u-'a']--;

            if (grau[u-'a'] == 0)
                fila.push(u);
        }
    }

    for (int i = 0; i < 26; i++) {
        if (grau[i] != 0) 
            ciclo = true;
    }

    if (ciclo) {
        cout << "Impossible\n";
        return 0;
    }

    while (!r.empty()) {
        cout << r.front();
        r.pop();
    }
    cout << endl;
    
    return 0;
}


