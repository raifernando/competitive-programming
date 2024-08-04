// SLIDING WINDOW MEDIAN
// https://cses.fi/problemset/task/1076/
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;

    queue<int> fila;
    multiset<int> ordenado;

    int pos_media = (k - 1) / 2, mediana;

    for (int i = 0; i < (k); i++) {
        int x;
        cin >> x;
        fila.push(x); 
        ordenado.insert(x);
    }

    auto it = ordenado.begin();
    advance(it, pos_media);
    cout << *it << ' ';

    for (int i = 0; i < (n-k); i++) {
        int x;
        cin >> x;

        ordenado.insert(x);

        if (fila.front() <= *it and *it < x) advance(it, 1);
        if (x < *it and fila.front() >= *it) advance(it, -1);

        ordenado.erase(find(ordenado.begin(), ordenado.end(), fila.front()));

        

        fila.pop();
        fila.push(x);
        
        cout << *it << ' ';
    }
    
}