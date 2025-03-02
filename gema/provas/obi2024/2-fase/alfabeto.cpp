// Problema: Alfabeto

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int alfabeto_alien[256];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    char c;
    for (int i = 0; i < k; i++) {
        cin >> c;
        int pos = c;

        alfabeto_alien[pos]++;
    }

    bool alien = true;

    for (int i = 0; i < n; i++) {
        cin >> c;
        int pos = c;
        
        if (alfabeto_alien[pos] == 0)
            alien = false;
    }

    if (alien) 
        cout << "S\n";
    else 
        cout << "N\n";

    return 0;
}