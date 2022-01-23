// https://www.codechef.com/IARCSJUD/problems/TASKFRCE
#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m, k; cin >> n >> m >> k;
	set<int> remain = {};
	int indeg[n + 10] = {};
	vector<int> adj[n + 10] = {};

	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		indeg[b]++;
		indeg[a]++;
	}

	bool b = true;
	int ans = n;
	for (int i = 1; i <= n; i++) remain.insert(i);

	while (b) {
		b = false;
		vector<int> del = {};

		for (auto u : remain) {
			if (indeg[u] < k) {
				ans--;
				b = true;
				for (auto j : adj[u]) {
					indeg[j]--;
				}
				del.push_back(u);	
			}
		}

		for (auto u : del) remain.erase(u);
	}

	if (ans) cout << "YES" << "\n" << ans;
	else cout << "NO";
}
