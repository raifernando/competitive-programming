// Problema: Cubo

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n;
    cin >> n;

    ll t_3 = 8, t_2 = 8*(n-2)+4*(n-2), t_1 = (n*n - 2*n - 2*(n-2))*6;
    ll t_0 = (n-2)*(n-2)*(n-2);

    cout << t_0 << endl << t_1 << endl << t_2 << endl << t_3 << endl;
}