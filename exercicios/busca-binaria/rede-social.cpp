// Rede Social
// https://neps.academy/br/exercise/1104

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;

    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int L = 1, R = m, fi = 0;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        int n_restantes = m - mid + 1;

        if (v[mid - 1] >= n_restantes) {
            fi = max(fi, min(v[mid - 1], n_restantes));
            R = mid - 1;
        }
        else {
            L = mid + 1;
        }
    }

    cout << fi << "\n";

    return 0;   
}