// https://www.codechef.com/IARCSJUD/problems/MEDUVADA
#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	char grid[n + 10][m + 10] = {};
	pair<int, int> st, en;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			grid[i][j] = c;
			if (c == 'D') en = {i, j};
			if (c == 'M') st = {i, j};
		}
	}

	vector<pair<int, int> > moves = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

	bool seen[n][m] = {};
	seen[st.fr][st.sc] = 1;
	pair<int, int> par[n][m] = {};

	queue<pair<int, int> > q;
	q.push(st);

	while (!q.empty()) {
		auto b = q.front();
		q.pop();

		for (auto u : moves) {
			int x = (b.fr + u.fr + n) % n;
			int y = (b.sc + u.sc + m) % m;

			if (seen[x][y] or grid[x][y] == '#') continue;
			seen[x][y] = true;
			par[x][y] = b;
			q.push({x, y});
		}
	}

	if (seen[en.fr][en.sc]) {
		cout << "YES" << "\n";

		en = par[en.fr][en.sc];
		while (en != st) {
			int i = en.fr, j = en.sc;
			grid[i][j] = 'x';
			en = par[i][j];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << grid[i][j];
			}
			cout << "\n";
		}
	}
	else cout << "NO";
}
