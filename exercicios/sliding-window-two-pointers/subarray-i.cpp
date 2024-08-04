// Subarray Sums I
// https://cses.fi/problemset/task/1660/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];

    int l = 0, r = 0, ans = 0;
    ll sum = 0;
    while (r < n) {
        sum += v[r];

        while (sum >= x) {
            if (sum == x)
                ans++;
            
            sum -= v[l];
            l++;
        }

        r++;
    } 

    cout << ans << "\n";
    
    return 0;
}