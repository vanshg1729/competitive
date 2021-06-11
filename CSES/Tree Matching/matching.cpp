// https://cses.fi/problemset/task/1130/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;
vector<int> adj[maxn] = {};
int dp[maxn][3] = {};

void dfs(int s, int p) {

	int sum = 0;
	for (auto u : adj[s]) {
		if (u == p) continue;
		dfs(u, s);
		dp[s][0] += max(dp[u][0], dp[u][1]);
	}

	for (auto u : adj[s]) {
		if (u == p) continue;
		dp[s][1] = max(dp[s][1], dp[s][0] - max(dp[u][0], dp[u][1]) + dp[u][0] + 1);
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
	cout << max(dp[1][0], dp[1][1]);
}
