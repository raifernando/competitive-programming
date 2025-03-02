// Bits (OBI)
// https://neps.academy/br/exercise/39

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

typedef long long ll;

int n, k;
ll dp[MAXN][MAXN];

ll calcule(int id, int uns) {
    if (id >= n-1) {
        dp[id][uns] = 1;
        return 1;
    }
    
    if (dp[id][uns] != 0)
        return dp[id][uns];

    if (uns >= k-1)
        dp[id][uns] = calcule(id+1, 0) % ((ll) 1e9 + 7);
    else
        dp[id][uns] = (calcule(id+1, 0) % ((ll) 1e9 + 7)) + (calcule(id+1, uns+1) % ((ll) 1e9 + 7));

    return dp[id][uns];
}

int main() {
    cin >> n >> k;

    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }

    ll r = calcule(0, 0) + calcule(0, 1);

    cout << r % ((ll) 1e9 + 7) << endl;
}