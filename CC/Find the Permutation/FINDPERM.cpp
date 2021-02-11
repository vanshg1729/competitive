// https://www.codechef.com/IARCSJUD/problems/FINDPERM
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
const int maxn = 1e5 + 10;
int n;

struct segtree {

	int seg[4 * maxn] = {};
	
	void build(int k, int l, int r) {
		if (l == r) {
			seg[k] = 1;
			return;
		}

		int m = (l + r)/2;
		build(2 * k, l, m);
		build(2 * k + 1, m + 1, r);

		seg[k] = seg[2 * k] + seg[2 * k + 1];
	}

	void build() {
		build(1, 1, n);
	}

	void set(int k, int l, int r, int pos) {
		if (l == r) {
			seg[k] = 0;
			return;
		}

		int m = (l + r)/2;
		if (pos <= m) set(2 * k, l, m, pos);
		else set(2 * k + 1, m + 1, r, pos);

		seg[k] = seg[2 * k] + seg[2 * k + 1];
	}

	void set(int pos) {
		set(1, 1, n, pos);
	}

	int find_sum(int k, int l, int r, int sum) {

		if (l == r) return l;

		int m = (l + r)/2;
		if (sum <= seg[2 * k + 1]) return find_sum(2 * k + 1, m + 1, r, sum);
		else return find_sum(2 * k, l, m, sum - seg[2 * k + 1]);
	}

	int find_sum(int sum) {
		return find_sum(1, 1, n, sum);
	}
};

segtree st;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	st.build();
	int a[n + 10] = {}, ans[n + 10] = {};
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = n; i > 0; i--) {
		int pos = st.find_sum(a[i] + 1);
		st.set(pos);
		ans[pos] = i;
	}

	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}
