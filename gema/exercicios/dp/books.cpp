// Book Shop
// https://cses.fi/problemset/task/1158
 
#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1010, maxx = 1e5 + 5;
 
vector<int> v(maxx), p(maxx); // valor e paginas 
int paginas[maxn][maxx];
 
int n, x, r = 0;
 
int contar_paginas() {
    for (int livro = 1; livro <= n; livro++) {
        for (int preco = 1; preco <= x; preco++) {
            paginas[livro][preco] = paginas[livro-1][preco];
 
            if (preco - v[livro] >= 0)
                paginas[livro][preco] = max(paginas[livro][preco], p[livro] + paginas[livro-1][preco-v[livro]]);
        }
    }
 
    return paginas[n][x];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> x;
 
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
 
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
 
    cout << contar_paginas() << endl;
 
    return 0;
}