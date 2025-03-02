// Minimizing Coins
// https://cses.fi/problemset/task/1634
 
#include <bits/stdc++.h>
using namespace std;
 
int const maxn = 110, maxx = 1e6 + 5, inf = 1e9 + 5;
int n, x;
 
vector<int> m(maxn);
 
int dp[maxx];
bool vis[maxx];
 
int qnt_moedas() {
    queue<int> q;
 
    for (int i = 1; i <= n; i++) {
        q.push(m[i]);
        dp[m[i]] = 1; 
    }
 
    bool possivel = false;
 
    while(!q.empty() and !possivel) {
        int s = q.front();
        q.pop();
 
        if (vis[s])
            continue;
 
        vis[s] = true;
 
        for (int moeda: m) {
            int soma = s + moeda;
 
            if (soma == x)
                possivel = true;
 
            if (soma > x or vis[soma])
                continue;
 
            dp[soma] = min(dp[soma], dp[s] + 1);
            q.push(soma);
        }
    }
 
    if (possivel)
        return dp[x];
 
    return -1;
}
 
int main() {
    cin >> n >> x;
 
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }
 
    for (int i = 0; i <= x; i++) {
        dp[i] = inf;
    }
 
    cout << qnt_moedas() << endl;
 
    return 0;
}