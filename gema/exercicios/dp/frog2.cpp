// B - Frog 2
// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

int n, k;
const int maxn = 1e5 + 5;
const int INF = 1e9;

vector<int> h;
int custo[maxn];
bool calculado[maxn];

int menor_custo() {
    custo[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k and (i-j) >= 0; j++) {
            custo[i] = min(custo[i], custo[i-j] + abs(h[i] - h[i-j]));
        }
    }

    return custo[n-1];
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        h.push_back(x);

        custo[i] = INF;
    }

    cout << menor_custo() << endl;

    return 0;
}