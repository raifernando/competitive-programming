// TWO SETS
// https://cses.fi/problemset/task/1092/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    int num;
    cin >> num;

    ll soma = 0;

    if (num % 2 == 0) 
        soma = (num + 1) * (ll) (num / 2);
    else 
        soma = ((1 + num) / 2) * (ll) num;

    if (soma % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }


    cout << "YES" << endl;

    ll tamanho = soma / 2;
    set<int> a;
    set<int> b;

    while (num != 0) {
        ll dif = tamanho - num;
        if (dif >= 0 and a.find(num) == a.end()) {
            a.insert(num);
            tamanho -= num;
        }
        else {
            b.insert(num);
        }

        num--;
    }

    ll sum_a = 0, sum_b = 0;
    cout << a.size() << endl;
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << *it << ' ';
        sum_a += *it;
    }

    cout << endl << b.size() << endl;
    for (auto it = b.begin(); it != b.end(); it++) {
        cout << *it << ' ';
        sum_b += *it;
    }
    
    return 0;
}