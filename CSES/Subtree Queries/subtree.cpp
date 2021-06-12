// https://cses.fi/problemset/task/1137/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long

const int maxn = 2e5 + 10;
int cnt[maxn] = {}, idx[maxn] = {}, val[maxn] = {};
vector<int> order = {}, adj[maxn] = {};

void dfs(int s, int p) {
	idx[s] = order.size();
	order.push_back(s);
	cnt[s] = 1;

	for (auto u : adj[s]) {
		if (u == p) continue;
		dfs(u, s);
		cnt[s] += cnt[u];
	}
}

struct segtree{

	ll seg[4 * maxn] = {};

	void build(int k, int l, int r) {
		if (l == r) {
			seg[k] = val[order[l]];
			return;
		}

		int m = (l + r)/2;
		build(2 * k, l, m);
		build(2 * k + 1, m + 1, r);
		seg[k] = seg[2 * k] + seg[2 * k + 1];
	}

	long long get(int k, int l, int r, int tl, int tr) {
		if (l == tl and r == tr) return seg[k];
		if (tr < l or tl > r) return 0;

		int m = (l + r)/2;
		return get(2 * k, l, m, tl, min(m, tr)) + 
		get(2 * k + 1, m + 1, r, max(m + 1, tl), tr);
	}

	void update(int k, int l, int r, int pos, int new_val) {
		if (l == r) {
			seg[k] = new_val;
			return;
		}

		int m = (l + r)/2;
		if (pos <= m) update(2 * k, l, m, pos, new_val);
		else update(2 * k + 1, m + 1, r, pos, new_val);
		seg[k] = seg[2 * k] + seg[2 * k + 1];
	}
};

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> val[i];
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	order.push_back(0);
	dfs(1, 0);
	segtree t; t.build(1, 1, n);

	while (q--) {

		int ty; cin >> ty;
		if (ty == 1) {
			int s, x; cin >> s >> x;
			t.update(1, 1, n, idx[s], x);
		}
		else {
			int s; cin >> s;
			cout << t.get(1, 1, n, idx[s], idx[s] + cnt[s] - 1) << "\n";
		}
	}
}
