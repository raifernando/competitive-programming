// PLUS OR MINUS
// https://codeforces.com/contest/1807/problem/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        if ((a+b) == c) cout << "+\n";
        else cout << "-\n";
    }

    return 0;
}