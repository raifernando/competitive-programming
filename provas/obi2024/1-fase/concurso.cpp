#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    multiset<int, greater<int>> notas;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        notas.insert(a);
    }

    auto it = notas.begin();
    advance(it, k - 1);

    cout << *it << endl;

    return 0;
}