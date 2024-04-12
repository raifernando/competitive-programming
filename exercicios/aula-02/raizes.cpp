// RAÍZES
// https://neps.academy/br/exercise/170

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    float x;
    cout << fixed << setprecision(4);

    while (n--) {
        cin >> x;
        cout << sqrt(x) << endl;
    }

    return 0;   
}