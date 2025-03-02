// A - Frog 1
// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n;
vector<int> h;

int custo[maxn];

int menor_custo() {
    for (int i = 2; i < n; i++) {
        int um = custo[i-1] + abs(h[i-1] - h[i]);
        int dois = custo[i-2] + abs(h[i-2] - h[i]);

        custo[i] = min(um, dois);
    }

    return custo[n-1];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.push_back(x); 
    }

    custo[0] = 0;
    custo[1] = abs(h[0] - h[1]);

    cout << menor_custo() << endl;

    return 0;
}