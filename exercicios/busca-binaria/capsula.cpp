// Cápsulas
// https://neps.academy/br/exercise/205

#include <bits/stdc++.h>
using namespace std;

bool ok(int n, long long f, vector<int> v, int mid) {
    long long produzidas = 0;

    for (int i = 0; i < n; i++) {
        produzidas += mid / v[i];
    }

    if (produzidas >= f)
        return true;
    
    return false;
}


int main() {
    int n; long long f;
    cin >> n >> f;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int L = 1, R = 10e8, ans = 10e8;
    while (L <= R) {
        int mid = L + (R - L) / 2;

        if (ok(n, f, v, mid)) {
            ans = mid;
            R = mid - 1;
        }
        else {
            L = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
