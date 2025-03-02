// Problema: Prefixo
// https://neps.academy/br/exercise/2437

#include <bits/stdc++.h>
using namespace std;

#define sp ' '
#define INF 1000000007

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string a, b;

    cin >> n >> a >> m >> b;

    int resp = 0;
    for (int i = 0; i < min(n, m); i++) {
        if (a[i] == b[i]) {
            resp++;
            continue;
        }

        break;
    }     

    cout << resp << endl;
    return 0;
}