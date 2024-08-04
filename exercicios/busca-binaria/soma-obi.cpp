// Soma (OBI 2019)
// https://neps.academy/br/exercise/468

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long soma = 0;
    if (k == 0) {
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                zeros++;
            }
            else {
                soma += ((zeros + 1)*zeros)/2;
                zeros = 0;
            }
        }
        soma += ((zeros + 1)*zeros)/2;
    }
    else {
        long long s_parcial = 0;
        for (int i = 0; i < n; i++) {
            int num = v[i];

            if (s_parcial + num == k) {
                soma++;
                s_parcial = k;
                continue;
            }

            if (s_parcial == k) {
                if (num > k) 
                    s_parcial = 0;
                else
                    s_parcial = num;
            }
            else {
                s_parcial += num;
            }
            
        }

    } 

    cout << soma << "\n";

    return 0;
}