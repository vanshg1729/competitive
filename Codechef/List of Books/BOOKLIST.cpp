// https://www.codechef.com/IARCSJUD/problems/BOOKLIST
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
const int maxn = 1e6 + 10;
int n;

struct segtree{

	int sum[4*maxn] = {};

	void build(int k, int l, int r) {
		if (l == r) {
			sum[k] = 1;
			return;
		}

		int m = (l + r)/2;
		build(2 * k, l, m);
		build(2 * k + 1, m + 1, r);
		sum[k] = sum[2 * k] + sum[2 * k + 1];
	}

	void build() {
		build(1, 1, n);
	}

	int find(int k, int l, int r, int s) {
		//cout << k << " " << l << " " << r << " " << s << endl;
		if (l == r) return l;
		int m = (l + r)/2;

		if (s <= sum[2 * k]) return find(2 * k, l, m, s);
		else return find(2 * k + 1, m + 1, r, s - sum[2 * k]);
	}

	int find(int s) {
		return find(1, 1, n, s);
	}

	void modify(int k, int l, int r, int pos) {
		if (l == r) {
			sum[k] = 0;
			return;
		}

		int m = (l + r)/2;
		if (pos <= m) modify(2 * k, l, m, pos);
		else modify(2 * k + 1, m + 1, r, pos);
		sum[k] = sum[2 * k] + sum[2 * k + 1]; 
	}

	void modify(int pos) {
		modify(1, 1, n, pos);
	}
};

segtree seg;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	seg.build();

	int a[n + 10] = {};
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int m; cin >> m;
	
	while (m--) {
		int b; cin >> b;
		int pos = seg.find(b);
		cout << a[pos] << "\n";
		seg.modify(pos);
	}		 	
}
