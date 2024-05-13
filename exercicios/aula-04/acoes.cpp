//  INVESTINDO NO MERCADO DE ACOES
// https://br.spoj.com/problems/ACOES1MG/

#include <bits/stdc++.h>
using namespace std;

int parcelas(int n, int k) {
    if (n <= k)
        return 1;
    else {
        if (n % 2 == 0)
            return parcelas((int) n/2, k) + parcelas((int) n/2, k);
        else
            return parcelas((int) (n+1)/2, k) + parcelas((int) (n-1)/2, k);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    while (n and k) {
        cout << parcelas(n, k) << endl;
        cin >> n >> k;
    }

    return 0;
}