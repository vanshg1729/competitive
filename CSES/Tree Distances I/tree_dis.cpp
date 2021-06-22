// https://cses.fi/problemset/task/1132/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = 2e5 + 10;
vector<int> adj[maxn] = {};
int depth[maxn] = {}, ans[maxn] = {};

void dfs(int s, int p) {

	for (auto u : adj[s]) {
		if (u == p) continue;
		dfs(u, s);
		depth[s] = max(depth[s], 1 + depth[u]);
	}
}

void solve(int s, int p, int par_ans) {
 
	ans[s] = max(depth[s], 1 + par_ans);
	vector<int> pref = {}, suff = {};
	for (auto u : adj[s]) {
		if (u == p) continue;
		pref.push_back(depth[u]);
		suff.push_back(depth[u]);
	}

	for (int i = 1; i < pref.size(); i++) {
		pref[i] = max(pref[i], pref[i - 1]);
	}

	for (int i = suff.size() - 2; i >=0; i--) {
		suff[i] = max(suff[i], suff[i + 1]);
	}

	int i = 0;
	for (auto u : adj[s]) {
		if (u == p) continue;
		int p_max = (i == 0) ? -1 : pref[i - 1];
		int s_max = (i == suff.size() - 1) ? -1 : suff[i + 1];
		int partial_ans = 1 + max(max(p_max, s_max), par_ans);

		solve(u, s, partial_ans);
		i++;
	}
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	solve(1, 0, -1);
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
