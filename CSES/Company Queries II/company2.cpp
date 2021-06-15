// https://cses.fi/problemset/task/1688/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10, K = 25;
vector<int> adj[maxn] = {}, euler = {};
int idx[maxn] = {}, dis[maxn] = {}, lg[2 * maxn] = {};
int st[2 * maxn][K + 10] = {};

void dfs(int s) {
	idx[s] = euler.size();
	euler.push_back(s);
	for (auto u : adj[s]) {
		dis[u] = dis[s] + 1;
		dfs(u);
		euler.push_back(s);
	}
}

void compute_log() {
	lg[1] = 0;
	for (int i = 2; i <= 4e5 + 5; i++) lg[i] = lg[i/2] + 1;
}

struct sparse_table{

	void build() {
		for (int i = 0; i < euler.size(); i++) st[i][0] = euler[i];

		for (int j = 1; j <= K; j++) {
			for (int i = 0; i < euler.size(); i++) {
				if (i + (1 << j) <= euler.size()) {
					if (dis[st[i][j - 1]] < dis[st[i + (1 << (j - 1))][j - 1]]) {
						st[i][j] = st[i][j - 1];
					}
					else {
						st[i][j] = st[i + (1 << (j- 1))][j - 1];
					}
				}
			}
		}
	}
};

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,q; cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		int a; cin >> a;
		adj[a].push_back(i);
	}

	dfs(1);
	compute_log();
	sparse_table S;
	S.build();

	while (q--) {
		int a, b; cin >> a >> b;
		a = idx[a]; b = idx[b];
		if (a > b) swap(a, b);
		int m = lg[b - a + 1];
		cout << min(st[a][m], st[b - (1 << m) + 1][m]) << "\n";
	}	
}
