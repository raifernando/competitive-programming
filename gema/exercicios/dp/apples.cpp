// Apple Division
// https://cses.fi/problemset/task/1623

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 22;
const ll inf = LONG_LONG_MAX;

int n;
int pesos[maxn];
ll resp = inf;

void diferenca(int maca, ll a, ll b) {
    if (maca >= n) {
        resp = min(resp, abs(a-b));
        return;
    }

    diferenca(maca+1, a + pesos[maca], b);
    diferenca(maca+1, a, b + pesos[maca]);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) 
        cin >> pesos[i];

    diferenca(1, pesos[0], 0);

    cout << resp << endl;

    return 0;    
}