// DID WE GET EVERTHING COVERED?
// https://codeforces.com/contest/1925/problem/C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; // numero de casos teste
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k, m; // tamanho string, k primeiras letras, tamanho da string s
        cin >> n >> k >> m;

        string s;
        cin >> s;

        int letras[k] = {0};
        for (int p = 0; p < m; p++) {
            char c = s[p];
            letras[c-97]++;
        }

        bool existe = true;
        for (int p = 0; p < k; p++) {
            if (letras[p] < n) {
                char c = p + 97;
                cout << "NO" << endl;
                for (int l = 0; l < n; l++) {
                    cout << c;
                }
                cout << endl;
                existe = false;
                break;
            }
        }

        int primeiro[k] = {0};
        for (int p = 0; p < m; p++) {
            char c = p + 97;
            if (s[p] != c) primeiro[s[p]-97]++;
            else break;
        }

        int ultimo[k] = {0};
        for (int p = m-1; p >= 0; p--) {
            char c = p + 97;
            if (s[p] != c) ultimo[s[p]-97]++;
            else break;
        }


        if (existe) cout << "YES" << endl;
    }

    return 0;
}