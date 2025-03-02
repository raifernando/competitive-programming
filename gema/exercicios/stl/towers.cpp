// TOWERS
// https://cses.fi/problemset/task/1073/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    multiset<int> torres;
    for (int i = 0; i < n; i++) {
        int cubo;
        cin >> cubo;

        auto prox = torres.upper_bound(cubo);
        
        if (*prox > cubo and prox != torres.end()) {
            torres.erase(prox);
            torres.insert(cubo);
        }

        else torres.insert(cubo);
    }

    cout << torres.size();

    return 0;
}