// LAMPADAS
// https://neps.academy/br/exercise/52

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int l1 = 0, l2 = 0;

    while (n--) {
        int x; cin >> x;

        if (x == 1) l1 = !l1;
        else {
            l1 = !l1;
            l2 = !l2;
        }
    }

    cout << l1 << endl << l2 << endl;

    return 0;
}