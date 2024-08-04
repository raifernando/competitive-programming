// BSEARCH01
// https://www.spoj.com/problems/BSEARCH1/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        int L = 0, R = n-1, ans = -1;

        while (L <= R) {
            int mid = L + (R - L) / 2;

            if (v[mid] == x) {
                ans = mid;
                R = mid - 1;
            }
            else if (v[mid] > x) {
                R = mid - 1;
            }
            else 
                L = mid + 1;
        }

        cout << ans << "\n";
    }

    return 0;
}