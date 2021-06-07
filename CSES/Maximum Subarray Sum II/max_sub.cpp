// https://cses.fi/problemset/task/1644/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
#define INF LLONG_MAX;

const int maxn = 2e5 + 10;
ll arr[maxn] = {}, pref[maxn] = {};
int n, a, b;

struct segtree{

	ll seg[4 * maxn] = {};
	void build(int k ,int l, int r) {
		if (l == r) {
			seg[k] = pref[l];
			return;
		}

		int m = (l + r)/2;
		build(2 * k, l, m);
		build(2 * k + 1, m + 1, r);
		seg[k] = min(seg[2 * k], seg[2 * k + 1]);
	}

	ll get_min(int k, int l, int r, int tl, int tr) {
		if (tl == l and tr == r) return seg[k];
		if (tl > r or tr < l) return INF;

		int m = (l + r)/2;
		ll min_1 = get_min(2 * k, l, m, tl, min(tr, m));
		ll min_2 = get_min(2 * k + 1, m + 1, r, max(m + 1, tl), tr);
		return min(min_2, min_1);
	}
};

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pref[i] = pref[i - 1] + arr[i];
	}

	segtree s; s.build(1, 0, n);

	ll ans = -INF;
	for (int i = a; i <= n; i++) {
		int tr = max(0, i - a);
		int tl = max(0, i - b);
		ll m = s.get_min(1, 0, n, tl, tr);
		ans = max(ans, pref[i] - m);
	}

	cout << ans;
}
