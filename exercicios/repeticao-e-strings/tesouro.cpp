// TESOURO
// https://neps.academy/br/exercise/2161

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    string s;
    cin >> n >> x >> y >> s;

    int movx = 0, movy = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'C') movx--;
        else if (s[i] == 'B') movx++;
        else if (s[i] == 'D') movy++;
        else movy--;
    }

    cout << x + movx << " " << y + movy;

    return 0;
}