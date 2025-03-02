// Mensagem
// https://codeforces.com/group/WYIydkiPyE/contest/450037/attachments/download/20669/MFP.pdf

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n+1, vector<int> (26));

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        v[i] = v[i-1];

        v[i][c - 'a']++;
    }

    int total = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int impares = 0;
            for(int k = 0; k < 26; k++) {
                if (v[i][k] - v[j][k] % 2 == 0)
                    impares++;
            }
            if (impares <= 1)
                total++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    } 

    

    return 0;
}