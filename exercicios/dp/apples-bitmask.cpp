// Apple Division
// https://cses.fi/problemset/task/1623

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = LONG_LONG_MAX;

int main() {
    int n;
    cin >> n;

    int pesos[n];
    ll resp = inf;

    for (int i = 0; i < n; i++) 
        cin >> pesos[i];

    for (int mask = 0; mask < (1 << n); mask++) {
        ll grupo1 = 0, grupo2 = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                grupo1 += pesos[i];
            else
                grupo2 += pesos[i];
        }

        resp = min(resp, abs(grupo1 - grupo2));
    }

    cout << resp << endl;

    return 0;    
}