// https://www.codechef.com/LRNDSA07/problems/FROGV
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, p, k; cin >> n >> k >> p;
	int mat[n + 10] = {};
	vector<pair<int, int> > v = {};

	for (int i = 1; i <= n; i++) {
		cin >> mat[i];
		v.push_back({mat[i], i});
	}

	sort(v.begin(), v.end());
	int dp[n + 10] = {};

	for (int i = 0; i < n; i++) {
		auto idx = lower_bound(v.begin(), v.end(), make_pair(v[i].fr - k, 0) ) - v.begin();
		int j = v[i].sc;
		if (i == idx) dp[j] = v[i].fr;
		else dp[j] = dp[v[idx].sc];
	}

	while (p--) {
		int a, b; cin >> a >> b;
		if (mat[b] > mat[a]) swap(a, b);
		if (mat[b] >= dp[a]) cout << "Yes\n";
		else cout << "No\n";
	}
}
