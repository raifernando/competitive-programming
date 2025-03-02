// DISTINCT NUMBERS
// https://cses.fi/problemset/task/1621/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<int> lista;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        lista.insert(x);
    }

    cout << lista.size();

    return 0;
}