// FATORIAL
// https://br.spoj.com/problems/FATORIA2/

#include <bits/stdc++.h>
using namespace std;

int fatorial(int n) {
    if (n <= 1)
        return 1;
    else    
        return n * fatorial(n-1);
}

int main() {
    int n;
    cin >> n;

    cout << fatorial(n);

    return 0;
}