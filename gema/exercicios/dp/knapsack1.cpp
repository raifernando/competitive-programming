// D - Knapsack 1
// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;

const int maxn = 105, maxp = 1e5 + 5;
typedef long long ll;

int n, capacidade;
int pesos[maxp], valores[maxp];

ll dp[maxp][maxn];
ll r = 0;

void maior_soma() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= capacidade; j++) { 
            dp[j][i] = dp[j][i-1];

            if (j >= pesos[i]) 
                dp[j][i] = max(dp[j][i], dp[j - pesos[i]][i-1] + valores[i]);

            r = max(r, dp[j][i]);
        }
    }
}

int main() {
    cin >> n >> capacidade;

    for (int i = 1; i <= n; i++) 
        cin >> pesos[i] >> valores[i];

    maior_soma();
    cout << r << endl;

    return 0;
}
