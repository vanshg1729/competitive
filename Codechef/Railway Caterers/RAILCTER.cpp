// https://www.codechef.com/IARCSJUD/problems/RAILCTER
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc second
#define fr first
int n, k;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> k;
	ll a[n + 10] = {};
	ll pref[n + 10] = {}, dp[n + 10] = {};

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pref[i] = a[i] + pref[i - 1];
	}

	ll ans = pref[k];

	dp[k] = pref[k];

	for(int i = k + 1; i <= n; i++) {
		dp[i] = max(pref[i] - pref[i - k], dp[i - 1] + a[i]);
		ans = max(dp[i], ans);
	}

	cout << ans;
}
