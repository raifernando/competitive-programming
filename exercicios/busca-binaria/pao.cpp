// Pão a Metro
// https://neps.academy/br/exercise/605

#include <bits/stdc++.h>
using namespace std;

bool possivel(int x, vector<int> tam, int n, int k) {
    int total = 0;

    for (int i = 0; i < k; i++) {
        total += tam[i]/x;
    }

    if (total >= n) 
        return true;

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> tam(k);
    for (int i = 0; i < k; i++) {
        cin >> tam[i];
    }

    int L = 1, R = 10000, ans = 0;
    while (L <= R) {
        int mid = L + (R - L) / 2;

        if (possivel(mid, tam, n, k)) {
            ans = mid;
            L = mid + 1;
        }
        else {
            R = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}