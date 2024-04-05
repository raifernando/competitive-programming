#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    n += 1;
    int mod = n % k;

    if (mod == 0) {
        cout << n;
    } 
    else {
        cout << n + k - mod;
    }

    return 0;
}