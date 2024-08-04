// TROCA DE CARTAS
// https://neps.academy/br/exercise/278

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; // numero de cartas de ana e beatriz
    cin >> a >> b;

    set<int> cartas_a;

    for (int i = 0; i < a; i++) {
        int id;
        cin >> id;
        cartas_a.insert(id);
    }

    int ultima_carta = 0, trocas = 0;
    for (int i = 0; i < b; i++) {
        int id;
        cin >> id;

        if (id == ultima_carta) continue;
        
        if (cartas_a.find(id) == cartas_a.end()) 
            trocas++;

        else 
            cartas_a.erase(id);
        
        ultima_carta = id;
    }

    cout << min(trocas , (int) cartas_a.size());

    return 0;
}