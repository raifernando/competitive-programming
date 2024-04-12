// DIVISION?
// https://codeforces.com/contest/1669/problem/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;

    cin >> n;

    while (n--) {
        cin >> d;

        if (d <= 1399) {
            cout << "Division 4\n";
        }
        else if (d <= 1599) {
            cout << "Division 3\n";
        }
        else if (d <= 1899) {
            cout << "Division 2\n";
        }
        else {
            cout << "Division 1\n";
        }
    }

    return 0;
}