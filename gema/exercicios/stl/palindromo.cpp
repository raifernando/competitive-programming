// PALINDROME REORDER
// https://cses.fi/problemset/task/1755/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.length(), letras[26] = {0};

    for (int i = 0; i < len; i++) {
        int c = s[i];
        letras[c-'A']++;
    }

    int impar = 0, tam = 0;
    string imp, pal = "";
    for (int i = 0; i < 26; i++) {
        if (letras[i] == 0) continue;

        if (letras[i] % 2 != 0) {
            impar++;
            imp = string(letras[i], (i+'A'));

            if (impar > 1) {
                cout << "NO SOLUTION" << endl;
                return 0;
            }

            continue;
        }
        
        pal.append(string(letras[i] / 2, (i+'A')));
        tam += letras[i] / 2;
    }

    pal.append(imp);

    for (int i = tam - 1; i >= 0; i--) {
        pal += pal[i];
    }    

    cout << pal << endl;
}