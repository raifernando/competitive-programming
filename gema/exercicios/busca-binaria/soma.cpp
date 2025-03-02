// Static Range Sum Queries
// https://cses.fi/problemset/task/1646/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> v;
    vector<long long> soma(n+1, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        soma[i + 1] += (soma[i] + x);
    }

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        cout << soma[b] - soma[a-1] << "\n";
    }

    return 0;
}