// Problema: Grupos de Trabalho
// https://neps.academy/br/exercise/2436 

#include <bits/stdc++.h>
using namespace std;

#define sp ' '
#define INF 1000000007

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int e, s, n; 
    cin >> e >> s >> n;

    int qnt_grupos = e / 3;

    vector<pii> sim(s), nao(n);
    vector<int> estudantes(e+1);

    for (int i = 0; i < s; i++) {
        int a, b;
        cin >> a >> b;

        sim[i] = {a, b};
    }   

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        nao[i] = {a, b};
    } 

    int id_grupo = 0;
    for (int i = 0; i < qnt_grupos; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        estudantes[a] = id_grupo;
        estudantes[b] = id_grupo;
        estudantes[c] = id_grupo;

        id_grupo++;
    } 

    int r_quebradas = 0;
    for (int i = 0; i < s; i++) {
        pii par = sim[i];
        if (estudantes[par.first] != estudantes[par.second])
            r_quebradas++;
    }   

    for (int i = 0; i < n; i++) {
        pii par = nao[i];
        if (estudantes[par.first] == estudantes[par.second])
            r_quebradas++;
    } 

    cout << r_quebradas << endl;

    return 0;
}