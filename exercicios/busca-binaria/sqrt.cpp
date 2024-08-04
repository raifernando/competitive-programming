// Sqrt(x)
// https://leetcode.com/explore/learn/card/binary-search/125/template-i/950/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    int L = 0, R = x, ans = 0;

    while (L <= R) {
        long long mid = L + (R - L) / 2;
        long long pow = mid*mid;

        if (pow <= x) {
            ans = mid;
            L = mid + 1;
        }
        else
            R = mid - 1;
    }

    cout << ans << endl;

    return 0;
}