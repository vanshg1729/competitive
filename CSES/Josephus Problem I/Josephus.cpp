// https://cses.fi/problemset/task/2162/
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> v[2] = {}, series = {};
	int st = 1, i = 0;

	for (int j = 1; j <= n; j++) v[0].push_back(j);
	while (1) {

		for (int j = 0; j < v[i].size(); j++) {
			if (j % 2 == st) {
				series.push_back(v[i][j]);
			}
			else {
				v[(i + 1) % 2].push_back(v[i][j]);
			}
		}

		if (v[i].size() % 2 != st) st = 1;
		else st = 0;

		v[i].clear();
		i ^= 1;

		if (v[i].size() == 0) break;
	}

	for (auto u : series) cout << u << " ";
}
