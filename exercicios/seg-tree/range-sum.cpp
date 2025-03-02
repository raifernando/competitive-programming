// Dynamic Range Sum Queries
// https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;

int n;  
int v[maxn];
ll tree[4*maxn];

void build(int no, int i, int j) {
    if (i == j) {
        tree[no] = v[i];
        return;
    }

    int meio = i + (j-i) / 2;
    int esq = 2*no, dir = 2*no + 1;

    build(esq, i, meio);
    build(dir, meio+1, j);

    tree[no] = tree[esq] + tree[dir];
}

ll query(int no, int i, int j, int a, int b) {
    if (i > b or j < a)
        return 0;

    if (a <= i and b >= j)
        return tree[no];

    int meio = i + (j-i) / 2;
    int esq = 2*no, dir = 2*no + 1;

    return query(esq, i, meio, a, b) + query(dir, meio + 1, j, a, b);
}

void update(int no, int i, int j, int pos, int val) {
    if (i == j) {
        tree[no] = val; 
        return;
    }

    int meio = i + (j-i) / 2;
    int esq = 2*no, dir = 2*no + 1;

    if (pos <= meio)
        update(esq, i, meio, pos, val);
    else
        update(dir, meio+1, j, pos, val);
            
    tree[no] = tree[esq] + tree[dir];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    build(1, 1, n);
    while (k--) {
        int q, a, b;
        cin >> q >> a >> b;

        if (q == 2) {
            ll r = query(1, 1, n, a, b);
            cout << r << "\n";
        }
        else 
            update(1, 1, n, a, b);
    }

    return 0;
}