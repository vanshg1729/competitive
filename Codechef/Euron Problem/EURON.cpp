// https://www.codechef.com/LRNDSA04/problems/EURON
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


long long combine_inv(vector<int>& v, int l, int m, int r) {
	int i = l, j = m + 1;
	vector<int> s = {};

	long long inv = 0;
	while (i <= m or j <= r) {
		if (i > m) {
			s.push_back(v[j]);
			j++;
			continue;
		}
		if (j > r or v[i] <= v[j]) {
			s.push_back(v[i]);
			i++;
		}
		else {
			s.push_back(v[j]);
			j++;
			inv += (ll) m + 1 - i;
		}
	}

	j = l;
	for (auto u : s) {
		v[j] = u;
		j++;
	}
	return inv;
}

long long count_inv(vector<int>& v, int l, int r) {
	if (l == r) return 0;
	if (r - l == 1) {
		if (v[l] > v[r]) {
			swap(v[l], v[r]);
			return 1;
		}
		return 0;
	}

	int m = (l + r)/2;
	return count_inv(v, l, m) +
	count_inv(v, m + 1, r) +
	combine_inv(v, l, m, r);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n; cin >> n;
	vector<int> v = {};
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	cout << count_inv(v, 0, n - 1);	
}
