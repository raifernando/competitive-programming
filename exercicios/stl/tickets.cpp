// CONCERT TICKETS
// https://cses.fi/problemset/task/1091/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; // qnt de tickets, qnt de clientes
    cin >> n >> m;

    multiset<int> tickets;

    for (int i = 0; i < n; i++) {
        int preco_bilhete;
        cin >> preco_bilhete;
        tickets.insert(preco_bilhete);
    }

    for (int i = 0; i < m; i++) {
        int preco_max;
        cin >> preco_max;
        auto disponivel = tickets.lower_bound(preco_max);
        if (*disponivel == preco_max) 
            cout << *disponivel << endl;

        else if (disponivel != tickets.begin()) {
            disponivel--;
            cout << *disponivel << endl;
        }

        else {
            cout << -1 << endl;
            continue;
        }
        tickets.erase(disponivel);
    }

    return 0;
}