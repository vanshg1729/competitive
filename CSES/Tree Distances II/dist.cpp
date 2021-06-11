// https://cses.fi/problemset/task/1133/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;
vector<int> adj[maxn] = {};
int dis[maxn] = {};
int cnt[maxn] = {};
ll sum[maxn][2] = {};
int par[maxn] = {};
vector<int> order = {};

void dfs(int s, int p) {
	order.push_back(s);
	cnt[s] = 1;
	for (auto u : adj[s]) {
		if (u == p) continue;
		dis[u] = dis[s] + 1;
		par[u] = s;
		dfs(u, s);
		sum[1][0] += sum[u][0] + dis[u];
		cnt[s] += cnt[u];
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
	cout << sum[1][0] << " ";
	sum[1][1] = sum[1][0];

	for (auto s : order) {
		if (s == 1) continue;
		sum[s][1] = sum[par[s]][1] - cnt[s] + (n - cnt[s]);
	}

	for (int i = 2; i <= n; i++) cout << sum[i][1] << " ";
}
