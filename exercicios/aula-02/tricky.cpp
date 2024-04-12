// TRICKY TEMPLATE
// https://codeforces.com/problemset/problem/1922/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases, len;
    string a, b, c;

    cin >> cases;

    while (cases--) {
        cin >> len;
        cin >> a >> b >> c;

        int check = 1;
        int iguais = 0;

        for (int x = 0; x < len; x++) {
            if ((a[x] == b[x]) && (b[x] == c[x])) iguais++;

            if (((a[x] == c[x]) && (b[x] != c[x])) || ((b[x] == c[x]) && (a[x] != c[x]))) check = 0;
        }
        
        if (check && iguais < len) cout <<"YES\n";
        else cout << "NO\n";
    }
    
}