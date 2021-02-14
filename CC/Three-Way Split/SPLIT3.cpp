// https://www.codechef.com/IARCSJUD/problems/SPLIT3
#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;

const int maxn = 3010;

vector<int> adj[maxn] = {};
ll sum[maxn] = {};
bool seen[maxn] = {};
int n, timer = 0;
int tin[maxn] = {}, tout[maxn] = {};

void dfs(int s) {

	tin[s] = ++timer;
	seen[s] = true;
	for (auto u : adj[s]) {
		if (seen[u]) continue;
		dfs(u);
		sum[s] += sum[u];
	}

	tout[s] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> sum[i];

	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	if (n == 1) {
		cout << sum[1];
		return 0;
	}
	else if (n == 2) {
		cout << max(sum[1] - sum[2], sum[2]);
		return 0;
	}

	ll con[3] = {};
	ll ans = 1e16;
	
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j < i; j++) {

			int a = i, b = j;
			if (is_ancestor(b, a)) swap(a, b);

			if (is_ancestor(a, b)) {
				con[1] = sum[a] - sum[b];
				con[2] = sum[b];
				con[0] = sum[1] - sum[a];
			}
			else {
				con[1] = sum[a]; con[2] = sum[b];
				con[0] = sum[1] - con[1] - con[2];
			}

			ll m = max(con[0], max(con[1], con[2]));
			ans = min(ans, m);
		}
	}

	cout << ans;
}

