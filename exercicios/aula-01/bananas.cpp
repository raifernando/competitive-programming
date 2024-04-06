// BANANAS
// https://codeforces.com/contest/546/problem/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, w; // price, money, quantity
    cin >> k >> n >> w;

    int total = 0;
    for (int i = 1; i <= w; i++) {
        total += i*k;
    }

    if (total <= n) {
        cout << 0;
    }
    else {
        cout << total - n;
    }

    return 0;
}