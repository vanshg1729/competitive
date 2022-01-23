// https://www.codechef.com/IARCSJUD/problems/CATERCON
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
int n;
vector<int> adj[maxn] = {};
bool seen[maxn] = {};
ll dp[maxn][2] = {}, traffic[maxn] = {};

void dfs(int b) {
	dp[b][1] += traffic[b];
	seen[b] = 1;

	for (auto u : adj[b]) {
		if (seen[u]) continue;
		dfs(u);
		dp[b][1] += dp[u][0];
		dp[b][0] += max(dp[u][0], dp[u][1]);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> traffic[i];

	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
	cout << max(dp[1][0], dp[1][1]);
}
