// f91
// https://br.spoj.com/problems/F91/

#include <bits/stdc++.h>
using namespace std;

int f91(int n) {
    if (n >= 101) 
        return n-10 ;
    else 
        return f91(f91(n+11));
}

int main() {
    int n;
    cin >> n;

    while (n) {
        int x = f91(n);
        cout << "f91(" << n << ") = " << x << endl;
        cin >> n;
    }

    return 0;
}