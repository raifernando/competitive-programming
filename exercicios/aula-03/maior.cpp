// SUBSTITUIOR O MAIOR EM MATRIZ 3X3
// https://neps.academy/br/exercise/202

#include <bits/stdc++.h>
using namespace std;

int main() {
    int maior, matriz[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x; 
            cin >> x;
        
            if (i == 0 && j == 0) maior = x;
            else if (x > maior) maior = x;
            
            matriz[i][j] = x;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == maior) matriz[i][j] = -1;
            cout << matriz[i][j] << ' ';
        }
        cout << endl;

    }

    return 0;
}