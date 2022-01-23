// https://www.codechef.com/LRNDSA04/problems/LOWSUM
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll>& v1, vector<ll>& v2, ll el, int q) {
	
	int less = 0;
	int n = v1.size();
	int end = n - 1;

	for (int i = 0; i < n; i++) {
		ll a = el - v1[i];
		if (a < 1) break;
		auto cnt = lower_bound(v2.begin(), v2.begin() + end + 1, a) - v2.begin();
		
		less += cnt;
		end = min((long int) n - 1, cnt);
		if (less >= q) return false;
	}

	if (less >= q) return false;
	return true;
}

ll Solve(vector<ll>& v1, vector<ll>& v2, int q) {
	int n = v1.size();
	ll max_el = v1[n - 1] + v2[n - 1];
	ll k = 0;

	for (ll d = max_el; d > 0; d /= 2) {
		while (k + d <= max_el and check(v1, v2, k + d, q)) k += d;
	}

	return k;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T; cin >> T;

	while (T--) {

		int n, Q; cin >> n >> Q;
		vector<ll> v1 = {}, v2 = {};

		for (int i = 0; i < n; i++) {
			ll a; cin >> a;
			v1.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			ll a; cin >> a;
			v2.push_back(a);
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		while (Q--) {
			int q; cin >> q;
			cout << Solve(v1, v2, q) << "\n";
		}
	}
}
