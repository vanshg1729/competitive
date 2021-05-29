// https://cses.fi/problemset/task/2163/
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second

const int maxn = 2*1e5 + 10;
struct segtree{
	int sum[4*maxn] = {};
	int num;

	void build(int l, int r, int k) {
		if (l == r) {
			sum[k] = 1;
			return;
		}

		int m = (l + r)/2;
		build(l, m, 2 * k); build(m + 1, r, 2 * k + 1);
		sum[k] = sum[2 * k] + sum[2 * k + 1];
	}

	void update(int l, int r, int k, int pos) {
		if (l == r) {
			sum[k] = 0;
			return;
		}

		int m = (l + r)/2;
		if (pos <= m) update(l, m, 2 * k, pos);
		else update(m + 1, r, 2 * k + 1, pos);
		sum[k] = sum[2 * k] + sum[2 * k + 1];
	}

	void update(int pos) {
		update(0, num - 1, 1, pos);
	}

	int get(int l, int r, int k, int tl, int tr) {
		if (tl > r or tr < l) return 0;
		if (tl <= l and tr >= r) return sum[k];

		int m = (l + r)/2;
		return get(l, m, 2 * k, tl, min(m, tr)) + get(m + 1, r, 2 * k + 1, max(m + 1, tl), tr);
	}

	int get(int l, int r) {
		return get(0, num - 1, 1, l, r);
	}

	int find(int l, int r, int k, int s) {
		if (l == r) return l;
		int m = (l + r)/2;
		if (s <= sum[2 * k]) return find(l, m, 2 * k, s);
		else return find(m + 1, r, 2 * k + 1, s - sum[2 * k]);
	}

	int find(int s) {
		return find(0, num - 1, 1, s);
	}

};

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k; k++;
	int tot = n - 1;
	int arr[n + 10] = {}; for (int i = 0; i < n; i++) arr[i] = i + 1;

	segtree t; t.num = n; t.build(0, n - 1, 1);

	vector<int> series = {};

	int st = (k - 1) % n;
	series.push_back(arr[st]); 
	t.update(st);

	while (series.size() < n) {
		int id;
		int req_sum = k % tot;
		if (req_sum == 0) req_sum = tot;
		int cur_sum = t.get(0, st);
		if (tot - cur_sum >= req_sum) {
			id = t.find(cur_sum + req_sum);
		}
		else {
			id = t.find(cur_sum + req_sum - tot);
		}

		series.push_back(arr[id]);
		t.update(id);
		st = id;
		tot--;
	}

	for (auto u : series) cout << u << " ";
}


