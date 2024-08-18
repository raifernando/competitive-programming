// Fire
// https://open.kattis.com/problems/fire2

#include <bits/stdc++.h>
using namespace std;

#define MAX 1005
#define INF 10000000
typedef pair<int,int> pii;

int main() {
	int t;
	cin >> t;

	int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};

	while (t--) {
		int n, m;
		cin >> m >> n;

		char tab[n][m];
		vector<pii> fogos;

		pii ini;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				tab[i][j] = c;

				if (c == '*')
					fogos.push_back({i, j});

				if (c == '@')
					ini = {i, j};
			}
		}

		int t_fogo[n][m], t_saida[n][m];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				t_fogo[i][j] = INF;
				t_saida[i][j] = INF;
			}
		}

		int qnt_fogos = fogos.size();

		for (int i = 0; i < qnt_fogos; i++) {
			pii ini_f = fogos[i];
			queue<pii> q;
			bool vis_fogo[n][m];

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					vis_fogo[i][j] = false;
				}
			}

			q.push(ini_f);
			vis_fogo[ini_f.first][ini_f.second] = true;
			t_fogo[ini_f.first][ini_f.second] = 0;

			while (!q.empty()) {
				pii pos = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int posi = pos.first + di[k], posj = pos.second + dj[k];

					if (posi < 0 or posi >= n or posj < 0 or posj >= m) 
						continue;

					if (vis_fogo[posi][posj] == true)
						continue;

					if (tab[posi][posj] == '#')
						continue;

					vis_fogo[posi][posj] = true;

					

					t_fogo[posi][posj] = min(t_fogo[posi][posj], t_fogo[pos.first][pos.second] + 1);
					q.push({posi, posj});
				}
			}
		}

		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < m; j++) {
		// 		char c = tab[i][j];

		// 		if (c == '#') {
		// 			cout << "- ";
		// 			continue;
		// 		}

		// 		cout << t_fogo[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }

		bool vis_saida[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis_saida[i][j] = false;
			}
		}

		queue<pii> q_s;
		q_s.push(ini);
		vis_saida[ini.first][ini.second] = true;
		t_saida[ini.first][ini.second] = 0;

		while (!q_s.empty()) {
			pii pos = q_s.front();
			q_s.pop();

			for (int k = 0; k < 4; k++) {
				int posi = pos.first + di[k], posj = pos.second + dj[k];

				if (posi < 0 or posi >= n or posj < 0 or posj >= m) 
					continue;

				if (vis_saida[posi][posj] == true)
					continue;

				if (tab[posi][posj] != '.')
					continue;

				vis_saida[posi][posj] = true;

				t_saida[posi][posj] = min(t_saida[posi][posj], t_saida[pos.first][pos.second] + 1);
				q_s.push({posi, posj});
			}
		}

		int t_min = INF;



		int x[2] = {0, n-1};
		for (int k = 0; k < 2; k++) {
			for (int i = 0; i < m; i++) {
				if (tab[x[k]][i] != '.')
					continue;

				if (t_fogo[x[k]][i] >= t_saida[x[k]][i])
					t_min = min(t_min, t_saida[x[k]][i]);
			}
		}

		int y[2] = {0, m-1};
		for (int k = 0; k < 2; k++) {
			for (int i = 0; i < n; i++) {
				if (tab[i][y[k]] != '.')
					continue;

				if (t_fogo[i][y[k]] >= t_saida[i][y[k]])
					t_min = min(t_min, t_saida[i][y[k]]);
			}
		}

		if (t_min == INF)
			cout << "IMPOSSIBLE\n";
		else
			cout << t_min + 1 << endl;
	}

	return 0;
}