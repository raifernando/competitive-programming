// Ogro
// https://neps.academy/br/exercise/261

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v(n-1);
    for(int i = 0; i < n-1; i++) 
        cin >> v[i];

    vector<int> pontos(n);
    for(int i = 0; i < n; i++) 
        cin >> pontos[i];

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        int L = 0, R = n-2, pos = n-1; 
        while (L <= R) {
            int mid = L + (R - L) / 2;

            if (v[mid] == x) {
                pos = mid + 1;
                R = mid - 1;
            }
            else if (v[mid] > x) {
                pos = mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }

        cout << pontos[pos] << ' ';
    }

    return 0;
}