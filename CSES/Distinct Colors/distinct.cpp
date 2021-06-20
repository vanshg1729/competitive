// https://cses.fi/problemset/task/1139/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = 2e5 + 10;
vector<int> adj[maxn] = {};
int col[maxn] = {}, dis[maxn] = {};
set<int> s = {};

void dfs(int src, int p = -1) {
	set<int> t;
	t.insert(col[src]);

	for (auto u : adj[src]) {
		if (u == p) continue;
		dfs(u, src);
		if (s.size() > t.size()) swap(s, t);
		for (auto x : s) t.insert(x);
	}

	dis[src] = t.size();
	swap(t, s);
}


int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> col[i];
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	for (int i = 1; i <= n; i++) cout << dis[i] << " ";
}
