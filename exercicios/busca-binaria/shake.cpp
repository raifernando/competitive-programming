// Shake Shake Shaky
// https://www.spoj.com/problems/MAIN8_C/

#include <bits/stdc++.h>
using namespace std;

bool possivel(int n, int k, int mid, vector<int> v) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += v[i] / mid;
    }

    if (total >= k) {
        return true;
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        int maior = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v[i] = x;

            maior = max(maior, x);
        }

        int L = 1, R = maior, ans = 0;
        while (L <= R) {
            int mid = L + (R - L) / 2;

            if (possivel(n, k, mid, v)) {
                ans = mid;
                L = mid + 1;
            }
            else {
                R = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}