// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=551
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;

const int maxn = 1e5;
int seen[maxn + 10] = {}, tin[maxn + 10] = {};
int low[maxn + 10] = {}, in_stack[maxn + 10] = {};
int timer = 0;
vector<pair<int,int> > edges = {};

void dfs(vector<int> adj[], int s, int p = -1) {
	seen[s] = true;
	in_stack[s] = true;
	tin[s] = low[s] = ++timer;

	for (auto u : adj[s]) {
		if (u == p) continue;
		if (in_stack[u]) {
			edges.push_back({s, u});
			low[s] = min(low[s], low[u]);
		}
		else {
			dfs(adj, u, s);
			edges.push_back({s, u});
			low[s] = min(low[s], low[u]);
			if (low[u] > tin[s]) {
				edges.push_back({u, s});
			}
		}
	}

	in_stack[s] = false;
}

void find_bridge(vector<int> adj[], int n) {
	edges.clear();
	memset(seen, 0, sizeof(seen));
	memset(tin, 0, sizeof(tin));
	memset(low, 0, sizeof(low));
	memset(in_stack, 0, sizeof(in_stack));

	for (int i = 1; i <= n; i++) {
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
    int count = 0;
    while (cin >> n) {

    	int m;
    	cin >> m;
    	count++;
    	if (n == 0) return 0;
    	cout << count << "\n\n";

    	vector<int> adj[n + 10] = {};
 		for (int i = 1; i <= m; i++) {
 			int a, b; cin >> a >> b;
 			adj[a].push_back(b);
 			adj[b].push_back(a);
 		}

    	find_bridge(adj, n);
    	sort(edges.begin(), edges.end());

    	for (auto u : edges) cout << u.fr << " " << u.sc << "\n";
    	cout << "#\n";


    }
}
