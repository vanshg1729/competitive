// https://cses.fi/problemset/task/1136/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = 2e5 + 10;
vector<int> adj[maxn] = {};
int diff[maxn] = {}, ans[maxn] = {}, par[maxn][20] = {}, dis[maxn] = {};

void dfs(int s, int p) {

	for (auto u : adj[s]) {
		if (u == p) continue;
		par[u][0] = s;
		dis[u] = dis[s] + 1;
		dfs(u, s);
	}
}

void build_lca(int n) {

	for (int i = 1; i <= 18; i++) {
		for (int j = 1; j <= n; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}
}

int LCA(int a, int b) {
	if (dis[a] > dis[b]) swap(a, b);
	int diff = dis[b] - dis[a];
	for (int i = 0; i <= 18; i++) {
		if (diff & (1 << i)) b = par[b][i];
	}

	if (a == b) return a;

	for (int i = 18; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}

	return par[a][0];
}

void dfs2(int s, int p) {
	ans[s] = diff[s];
	for (auto u : adj[s]) {
		if (u == p) continue;
		dfs2(u, s);
		ans[s] += ans[u];
	}
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q; cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	build_lca(n);

	while (q--) {
		int a, b; cin >> a >> b;
		int c = LCA(a, b);
		if (b == c) swap(a, b);
		if (a == c) {
			diff[b]++;
			diff[par[c][0]]--;
		}
		else {
			diff[a]++;
			diff[b]++;
			diff[c]--;
			diff[par[c][0]]--;
		}
	}

	dfs2(1, 0);
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
