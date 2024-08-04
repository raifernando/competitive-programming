// Array Division
// https://cses.fi/problemset/task/1085/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool checar(int n, int k, ll mid, vector<int> v) {
    int total = 0;

    ll soma = 0;    
    for (int i = 0; i < n; i++) {
        int num = v[i];

        if (soma + num < mid) {
            soma += num;
            continue;
        }

        total++;
        if (soma + num > mid) {
            soma = num;
        }
        else {
            soma = 0;
        }
    }

    if (soma and soma < mid) total++;
    else if (soma > mid) total += 2;

    if (total <=  k) return true;
    
    return false;   
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    ll soma = 0;
    int v_max = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        v[i] = x;
        v_max = max(v_max, x);
        soma += x;
    }

    ll L = v_max, R = soma, ans = soma;
    while (L <= R) {
        ll mid = L + (R - L) / 2;

        if(checar(n, k, mid, v)) {
            ans = mid;
            R = mid - 1;
        }
        else {
            L = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}