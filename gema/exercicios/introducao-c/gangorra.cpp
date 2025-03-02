// GANGORRA
// https://neps.academy/br/exercise/260

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a*b==c*d) {
        cout << 0;
    } 
    else if (a*b > c*d) {
        cout << -1;
    } 
    else {
        cout << 1;
    }
}