// https://www.codechef.com/IARCSJUD/problems/SPLIT3
#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;

struct Edge {
	int a, b;
};

const int maxn = 3010;

vector<int> adj[maxn] = {};
ll sum[maxn] = {};
bool seen[maxn] = {};
int n, timer;
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
	vector<Edge> edge = {};
	for (int i = 1; i <= n; i++) cin >> sum[i];

	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		edge.push_back({a, b});
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

	for (int i = 0; i < edge.size(); i++) {
		if (is_ancestor(edge[i].b, edge[i].a)) swap(edge[i].a, edge[i].b);
	}

	for (int i = 0; i < edge.size(); i++) {

		for (int j = 0; j < i; j++) {

			auto node1 = edge[i];
			auto node2 = edge[j];

			if (is_ancestor(node1.b, node2.b)) {
				con[1] = sum[node1.b] - sum[node2.b];
				con[2] = sum[node2.b];
				con[0] = sum[1] - sum[node1.b];
			}
			else if (is_ancestor(node2.b, node1.b)) {
				con[1] = sum[node2.b] - sum[node1.b];
				con[2] = sum[node1.b];
				con[0] = sum[1] - sum[node2.b];
			}
			else {
				con[1] = sum[node1.b]; con[2] = sum[node2.b];
				con[0] = sum[1] - con[1] - con[2];
			}

			ll m = max(con[0], max(con[1], con[2]));
			ans = min(ans, m);
		}
	}	

	cout << ans;
}

