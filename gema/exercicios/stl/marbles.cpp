// GAME WITH MARBLES (HARD VERSION)
// https://codeforces.com/contest/1914/problem/E2

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        multiset<int> m_a;
        multiset<pair<int, int>> m_b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            m_a.insert({x, 0});
            m_b.insert({0, x});
        }

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            // m_a[i].second = x;
            // m_b[i].first = x;
        }

    }
}