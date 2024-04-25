// UNNATURAL LANGUAGE PROCESSING
// https://codeforces.com/problemset/problem/1915/D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int casos, letras;
    string palavra;

    cin >> casos;

    string silaba("");

    while (casos--) {
        cin >> letras >> palavra;
        int consoante = 0;
        silaba = "";

        for (int i = 0; i < letras; i++) {
            char caractere = palavra[i];

            if (caractere != 'a' && caractere != 'e') {
                if (consoante) {
                    cout << silaba << '.';
                    silaba = caractere;
                }
                else silaba += caractere;
                consoante = 1;
            }
            else {
                consoante = 0;
                silaba += caractere;
            }

            if (silaba.length() == 4) {
                cout << silaba[0] << silaba[1] << '.';
                silaba = {silaba[2], silaba[3]};
            }
        }
        cout << silaba << endl;
    }

    return 0;
}

