// https://www.codechef.com/IARCSJUD/problems/GREATESC
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e4;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m;

	vector<int> adj[n + 10] = {};
	for(int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int s, t; cin >> s >> t;
	int seen[n + 10] = {}, dis[n + 10] = {};

	queue<int> q;
	q.push(s); seen[s] = 1;

	while (!q.empty()) {
		int b = q.front();
		q.pop();

		for(auto u : adj[b]) {
			if(seen[u]) continue;
			dis[u] = dis[b] + 1;
			seen[u] = true;
			q.push(u);
		}
	}

	cout << dis[t];
}
