// Arquivos (OBI 2015)
// https://neps.academy/br/exercise/64

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, b;
    cin >> n >> b;

    vector<int> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    
    sort(v.begin(), v.end());

    int pastas = 0, pa = 0, pb = n - 1;

    while (pa <= pb) {
        ll sum = v[pa] + v[pb];

        if (sum <= b) {
            pa++;
        }

        pb--;
        pastas++;
    }

    cout << pastas << '\n';

    return 0;
}