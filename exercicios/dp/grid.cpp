// H - Grid 1
// https://atcoder.jp/contests/dp/tasks/dp_h

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll modulo = 1e9 + 7;

int main() {
    int h, w;
    cin >> h >> w;

    char grid[h+1][w+1];
    ll dp[h+1][w+1];

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> grid[i][j];

            dp[i][j] = 0;
        }
    }

    dp[1][1] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char c = grid[i][j];

            if (c == '#')
                continue;

            if (i == 1 and j == 1) 
                continue;

            int esquerda = j-1, cima = i-1;

            if (esquerda >= 1)
                dp[i][j] =(dp[i][j] + dp[i][esquerda]) % modulo;
            
            if (cima >= 1)
                dp[i][j] = (dp[i][j] + dp[cima][j]) % modulo;
        }
    }

    cout << dp[h][w] << endl;

    return 0;
}