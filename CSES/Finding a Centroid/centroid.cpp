// https://cses.fi/problemset/task/2079/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;
vector<int> adj[maxn] = {};
int sub_size[maxn] = {};
int par[maxn] = {};

void dfs(int s, int p = -1) {

	sub_size[s] = 1;
	for (auto u : adj[s]) {
		if (u == p) continue;
		par[u] = s;
		dfs(u, s);
		sub_size[s] += sub_size[u];
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

 	dfs(1);
 	int ans = 1;

 	while (1) {
 		bool b = true;
 		for (auto u : adj[ans]) {
 			if (u == par[ans]) continue;
 			if (sub_size[u] > n/2) {
 				ans = u;
 				b = false;
 				break;
 			}
 		}

 		if (b) break;
 	}

 	cout << ans;

}
