// LEFTRIGHTARROW
// https://atcoder.jp/contests/abc345/tasks/abc345_a

#include<bits/stdc++.h>
using namespace std;

int main() {
    string arrow;
    cin >> arrow;

    int len = arrow.length();

    if (len < 3 || (arrow[0] != '<') || (arrow[len-1] != '>')) {
        cout << "No";
        return 0;
    }

    for (int i = 1; i < len - 1; i++) {
        if (arrow[i] != '=') {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}