// SUM OF TWO VALUES
// https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    map <int, int> mapa;

    int repetidos = 0;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;

        int dif = x - k;

        if (mapa.find(k) != mapa.end()) {
            cout << mapa[k] << " " << mapa.size() + 1 + repetidos;
            return 0;
        }
        
        else if (mapa.find(dif) == mapa.end()) {
            mapa[dif] = i;
        }
        else repetidos++;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}