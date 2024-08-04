// O MAR NÃO ESTÁ PARA PEIXE
// https://neps.academy/br/exercise/530

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int mar[105][105] = {0}, area = 0;

    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                if (mar[x][y] != 1) area++;
            
                mar[x][y] = 1;
            }
        }
    }

    cout << area;

    return 0;
}