// Problema: Intervalo Distintos
// https://neps.academy/br/exercise/2438

#include <bits/stdc++.h>
using namespace std;

#define sp ' '
#define INF 1000000007
#define MAXN 100010

typedef long long ll;
typedef pair<int,int> pii;

int q_num[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int r_max = 1;

    int L = 0;
    for (int i = 0; i < n; i++) {
        int num = v[i];

        q_num[num]++;

        if (q_num[num] > 1) {
            r_max = max(r_max, i-L);    
            while (q_num[num] != 1) {
                int n_atras = v[L];
                q_num[n_atras]--;
                L++;
            }
        }
    }

    r_max = max(n-L, r_max);

    cout << r_max << endl;
     
    return 0;
}