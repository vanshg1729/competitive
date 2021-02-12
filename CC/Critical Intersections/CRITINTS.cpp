// https://www.codechef.com/IARCSJUD/problems/CRITINTS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 310;
vector<int> adj[maxn] = {};
int n, m;

bool is_connected(int a) {
	bool seen[n + 10] = {};
	seen[a] = 1;
	int comps = 0;

	for (int i = 1; i <= n; i++) {
		if (seen[i]) continue;
		if (comps >= 1) return false;

		comps++;
		seen[i] = true;
		queue<int> q;
		q.push(i);

		while (!q.empty()) {
			int b = q.front();
			q.pop();

			for (auto u : adj[b]) {
				if (seen[u]) continue;
				seen[u] = true;
				q.push(u);
			}
		}
	}

	return true;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> nodes = {};
	for (int i = 1; i <= n; i++) {
		if (!is_connected(i)) nodes.push_back(i);
	}

	cout << nodes.size() << "\n";
	for (auto u : nodes) cout << u << "\n";
}
