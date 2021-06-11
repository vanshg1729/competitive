// https://cses.fi/problemset/result/2318447/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;
vector<int> adj[maxn] = {};
int dis[maxn] = {};
int m = 0;

void dfs(int s, int p) {

	for (auto u : adj[s]) {
		if (u == p) continue;
		dis[u] = dis[s] + 1;
		dfs(u, s);
		if (dis[u] > dis[m]) m = u;
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
	memset(dis, 0, sizeof(dis));
	dfs(m, 0);

	cout << dis[m];
}
