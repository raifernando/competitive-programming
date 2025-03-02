// Copying books
// https://www.spoj.com/problems/BOOKS1/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, m, k;
    cin >> q >> m >> k;

    vector<int> p(m);
    vector<long long> soma(m+1, 0);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
        soma[i+1] = soma[i] + p[i];
    }

    for (int i = 0; i < m+1; i++) {
        cout << soma[i] << endl;
    }

    return 0;
}