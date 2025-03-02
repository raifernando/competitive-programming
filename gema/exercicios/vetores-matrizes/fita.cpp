// FITA COLORIDA
// https://neps.academy/br/course/programacao-basica-(codcad)/lesson/fita-colorida

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int zeros[n] = {0}, pos_zero = 0, qnt_zeros = 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 0) {
            zeros[pos_zero] = i;
            pos_zero++;
            qnt_zeros++;
        }
    }

    for (int i = 0; i < n; i++) {
        int d = 9;
        for (int k = 0; k < qnt_zeros; k++) {
            d = min(abs(i-zeros[k]), d);
        }
        cout << d << ' ';
    }

    return 0;
}