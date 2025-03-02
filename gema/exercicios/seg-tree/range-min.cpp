// Dynamic Range Minimum Queries
// https://cses.fi/problemset/task/1649

#include <bits/stdc++.h>
using namespace std;

#define esq 2*no
#define dir ((2*no)+1)
#define meio (i + (j-i)/2)

const int maxn = 2e5 + 5;
const int inf = INT_MAX;

int n, v[maxn], tree[4*maxn];

void build(int no, int i, int j) {
    if (i == j) {
        tree[no] = v[i];
        return;
    }

    build(esq, i, meio);
    build(dir, meio+1, j);

    tree[no] = min(tree[esq], tree[dir]);
}

int query(int no, int i, int j, int a, int b) {
    if (i > b or j < a)
        return inf;

    if (a <= i and j <= b) {
        return tree[no];
    }

    int x = query(esq, i, meio, a, b), y = query(dir, meio+1, j, a, b);
    return min(x, y);
}

void update(int no, int i, int j, int pos, int val) {
    if (i == j) {
        tree[no] = val;
        return;
    }

    if (pos <= meio)
        update(esq, i, meio, pos, val);
    else
        update(dir, meio + 1, j, pos, val);

    tree[no] = min(tree[esq], tree[dir]);
}

int main() {
    fill(tree, tree+4*maxn, inf);

    int k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    build(1, 1, n);

    while(k--) {
        int q, a, b;
        cin >> q >> a >> b;

        if (q == 1)
            update(1, 1, n, a, b);
        else
            cout << query(1, 1, n, a, b) << "\n";
    }

    return 0;
}
