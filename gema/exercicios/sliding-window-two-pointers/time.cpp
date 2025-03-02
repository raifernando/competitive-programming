// Balanced Team
// https://codeforces.com/contest/1133/problem/C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];

    sort(v.begin(), v.end());

    int estudantes = 0, fim = 0;
    for (int i = 0; i < n - 1; i++) {
        int ini = i, diferenca = v[i+1] - v[i];

        int cont = 2;
        while (diferenca <= 5 and (i + cont < n)) {
            diferenca = v[i + cont] - v[i];
            fim++;
            cont++;
        }

        
        estudantes = max(estudantes, cont);
    

    }

    cout << estudantes << '\n' << fim << '\n';

    return 0;
}