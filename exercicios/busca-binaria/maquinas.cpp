// Factory Machines
// https://cses.fi/problemset/task/1620/

#include <bits/stdc++.h>
using namespace std;

bool ok(int n, long long t, vector<long long> v, long long mid) {
    long long total = 0;

    for (int i = 0; i < n; i++) {
        total += mid / v[i];
    }

    if (total >= t) 
        return true;
    
    return false;
}

int main() {
    int n;
    long long t;
    cin >> n >> t;

    vector<long long> v(n);
    long long t_min = 10e9;
    for (int i = 0; i < n; i++) { 
        long long x; cin >> x;
        v[i] = x;

        t_min = min(t_min, x);
    }

    long long L = 1, R = (t_min * t), ans = 10e9;
    while (L <= R) {
        long long mid = L + (R - L) / 2;

        if (ok(n, t, v, mid)) {
            ans = mid;
            R = mid - 1;
        }
        else {
            L = mid + 1;
        }
    }

    cout << ans <<  "\n";

    return 0;
}