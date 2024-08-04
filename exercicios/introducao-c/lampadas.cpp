// LAMPADAS
// https://neps.academy/br/exercise/59

#include <bits/stdc++.h>
using namespace std;

int main() {
    int ia, ib, fa, fb;
    cin >> ia >> ib >> fa >> fb;

    int a = (ia == fa), b = (ib == fb);

    if (b) cout << !a;
    else cout << (!b+ a);
    
    return 0;
}