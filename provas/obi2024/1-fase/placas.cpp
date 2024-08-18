#include <bits/stdc++.h>
using namespace std;

int main() {
    string placa;
    cin >> placa;

    int tam = placa.size();

    vector<char> brasil = {'l', 'l', 'l', '-', 'n', 'n', 'n', 'n'};
    vector<char> mercosul = {'l', 'l', 'l', 'n', 'l', 'n', 'n'};

    if (tam > 8 || tam < 7) {
        cout << 0 << endl;
        return 0;
    }

    vector<char> v;
    for (int i = 0; i < tam; i++) {
        if (placa[i] >= 'A' and placa[i] <= 'Z') {
            v.push_back('l');
            continue;
        }

        if (placa[i] >= '0' and placa[i] <= '9') {
            v.push_back('n');
            continue;
        }

        if(placa[i] == '-') {
            v.push_back('-');
            continue;
        }

        else {
            v.push_back('i');
        }
    }

    bool placa_valida = true;
    if (tam == 8) {
        for (int i = 0; i < 8; i++) {
            if (v[i] != brasil[i]) {
                placa_valida = false;
            }
        }

        if (placa_valida) {
           cout << 1 << endl;
            return 0;
        }
    }

    if (tam == 7) {
        for (int i = 0; i < 7; i++) {
            if (v[i] != mercosul[i]) {
                placa_valida = false;
            }
        }
        
        if (placa_valida) {
            cout << 2 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}