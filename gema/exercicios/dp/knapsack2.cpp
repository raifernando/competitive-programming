// E - Knapsack 2
// https://atcoder.jp/contests/dp/tasks/dp_e

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 105, maxv = 1e5 + 5;
const ll inf = 1e18;

int n, c, v_total = 0;

int v[maxn], p[maxn];
ll dp[maxn][maxv], r = 0;

void maior_valor() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= v_total; j++) {
            dp[i][j] = dp[i-1][j];

            if (v[i] <= j) 
                dp[i][j] = min(dp[i][j], dp[i-1][j - v[i]] + p[i]);

            if (dp[i][j] <= c)
                r = max(r, (ll) j);
        }
    }
}

int main() {    
    cin >> n >> c;

    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> v[i];
        v_total += v[i];    
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= v_total; j++)
            dp[i][j] = inf;
    }

    maior_valor();
    cout << r << endl;

    return 0;
}