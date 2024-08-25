// Fire
// https://open.kattis.com/problems/fire2

#include <bits/stdc++.h>
using namespace std;

#define INF 10000000
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

int main() {
	int t;
	cin >> t;

	int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};

	while (t--) {
		int n, m;
		cin >> m >> n;

		char tab[n][m];
		int t_fogo[n][m], t_saida[n][m];
		bool vis[n][m];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				t_fogo[i][j] = INF;
				vis[i][j] = false;
			}
		}
	
		priority_queue<pip, vector<pip>, greater<pip>> fila;

		pii ini;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;

				if (c == '*') {
					fila.push({0, {i, j}});
					t_fogo[i][j] = 0;
				}
				if (c == '@')
					ini = {i, j};

				tab[i][j] = c;
			}
		}

		while(!fila.empty()) {
			pii s = fila.top().second;
			fila.pop();

			if(vis[s.first][s.second])
				continue;

			vis[s.first][s.second] = true;

			for (int k = 0; k < 4; k++) {
				int posi = s.first + di[k], posj = s.second + dj[k];

				if (posi < 0 or posj < 0 or posi >= n or posj >= m)
					continue;

				if (vis[posi][posj])
					continue;

				char c = tab[posi][posj];

				if (c == '#')
					continue;

				if (t_fogo[posi][posj] > t_fogo[s.first][s.second] + 1) {
					t_fogo[posi][posj] = t_fogo[s.first][s.second] + 1;

					fila.push({t_fogo[posi][posj], {posi, posj}});
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis[i][j] = false;
				t_saida[i][j] = INF;
			}
		}
	
		fila.push({0, ini});
		t_saida[ini.first][ini.second] = 0;

		while(!fila.empty()) {
			pii s = fila.top().second;
			fila.pop();

			if(vis[s.first][s.second])
				continue;

			vis[s.first][s.second] = true;

			for (int k = 0; k < 4; k++) {
				int posi = s.first + di[k], posj = s.second + dj[k];

				if (posi < 0 or posj < 0 or posi >= n or posj >= m)
					continue;

				if (vis[posi][posj])
					continue;

				char c = tab[posi][posj];

				if (c == '#')
					continue;

				if (t_saida[posi][posj] > t_saida[s.first][s.second] + 1) {
					t_saida[posi][posj] = t_saida[s.first][s.second] + 1;

					fila.push({t_saida[posi][posj], {posi, posj}});
				}
			}
		}

		bool possivel[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis[i][j] = false;

				if (tab[i][j] == '#') {
					possivel[i][j] = false;
					continue;
				}

				if (t_saida[i][j] < t_fogo[i][j])
					possivel[i][j] = true;
				else
					possivel[i][j] = false;
			}
		}
	
		fila.push({0, ini});

		while(!fila.empty()) {

			pii s = fila.top().second;
			fila.pop();

			if(vis[s.first][s.second] or !possivel[s.first][s.second])
				continue;

			vis[s.first][s.second] = true;

			for (int k = 0; k < 4; k++) {
				int posi = s.first + di[k], posj = s.second + dj[k];

				if (posi < 0 or posj < 0 or posi >= n or posj >= m)
					continue;

				if (vis[posi][posj])
					continue;

				if (possivel[posi][posj])
					fila.push({t_saida[posi][posj], {posi, posj}});
			}
		}

		bool saiu = false;
		int t_final = INF;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i != 0 and j != 0 and i != n-1 and j != m-1)
					continue;

				if (vis[i][j]) {
					saiu = true;
					t_final = min(t_final, t_saida[i][j]);
				}
			}
		}

		if (saiu) 
			cout << t_final + 1 << endl;
		else 
			cout << "IMPOSSIBLE\n";
	}

	return 0;
}