// https://cses.fi/problemset/task/1135/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10, K = 25;
vector<int> adj[maxn] = {}, euler = {};
int idx[maxn] = {}, dis[maxn] = {}, lg[2 * maxn] = {};
int st[2 * maxn][K + 10] = {};

void dfs(int s, int p) {
	idx[s] = euler.size();
	euler.push_back(s);

	for (auto u : adj[s]) {
		if (u == p) continue;

		dis[u] = dis[s] + 1;
		dfs(u, s);
		euler.push_back(s);
	}
}

void compute_log() {
	lg[1] = 0;
	for (int i = 2; i <= 4e5 + 5; i++) lg[i] = lg[i/2] + 1;
}

void build_table() {
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

int ancest(int a, int b) {

		a = idx[a]; b = idx[b];
		if (a > b) swap(a, b);
		int m = lg[b - a + 1];
		if (dis[st[a][m]] < dis[st[b - (1 << m) + 1][m]]) return st[a][m];
		return st[b - (1 << m) + 1][m];	
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,q; cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	compute_log();
	build_table();

	while (q--) {
		int a, b; cin >> a >> b;
		int c = ancest(a, b);
		//cout << a << " " << b << " " << ancest(a, b) << endl;		
		cout << dis[a] + dis[b] - 2 * dis[c] << "\n";
	}	
}
