// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=737
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;

const int maxn = 1e5;
int seen[maxn + 10] = {}, tin[maxn + 10] = {};
int low[maxn + 10] = {};
int timer = 0;
vector<pair<int,int> > bridges = {};

void dfs(vector<int> adj[], int s, int p = -1) {
	seen[s] = true;
	tin[s] = low[s] = ++timer;
	for (auto u : adj[s]) {
		if (u == p) continue;
		if (seen[u]) {
			low[s] = min(low[s], low[u]);
		}
		else {
			dfs(adj, u, s);
			low[s] = min(low[s], low[u]);
			if (low[u] > tin[s]) {
				bridges.push_back({s, u});
			}
		}
	}
}

void find_bridge(vector<int> adj[], int n) {
	bridges.clear();
	memset(seen, 0, sizeof(seen));
	memset(tin, 0, sizeof(tin));
	memset(low, 0, sizeof(low));

	for (int i = 0; i < n; i++) {
		if (seen[i]) continue;
		dfs(adj, i);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    while (cin >> n) {
    	vector<int> adj[n + 10] = {};
    	for (int i = 0; i < n; i++) {
    		int a; cin >> a;
    		char gar; int m;
    		cin >> gar >> m >> gar;
    		for (int j = 1; j <= m; j++) {
    			int b; cin >> b;
    			adj[a].push_back(b);
    		}
    	}

    	find_bridge(adj, n);
    	for (int i = 0; i < bridges.size(); i++) {
    		if (bridges[i].fr > bridges[i].sc) {
    			swap(bridges[i].fr, bridges[i].sc);
    		}
    	}

    	sort(bridges.begin(), bridges.end());
    	cout << bridges.size() <<" critical links\n";
    	for (auto u : bridges) cout << u.fr << " - " << u.sc << "\n";
    	cout << "\n";
    }
}
