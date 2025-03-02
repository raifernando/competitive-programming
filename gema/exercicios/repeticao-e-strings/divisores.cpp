// TODOS OS DIVISORES
// https://neps.academy/br/exercise/216

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) cout << i << " ";
    }

    return 0;
}