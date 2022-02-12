/* https://codeforces.com/contest/1637/problem/B */
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		int arr[n] = {};
		for (int i = 0; i < n; i++) cin >> arr[i];

		int dp[n + 10][n + 10] = {};
		dp[0][0] = 1;
		if (arr[0] == 0) dp[0][0]++;

		ll ans = dp[0][0];
		for (int r = 1; r < n; r++) {
			if (arr[r]) dp[r][r] = 1;
			else dp[r][r] = 2;
			ans += dp[r][r];

			for (int l = r - 1; l >= 0; l--) {
				int size = r - l + 1;
				int seen[size + 1] = {};
				int mex = 0;

				for (int k = l; k <= r; k++) {
					if (arr[k] <= size) {
						seen[arr[k]] = 1;
						while (seen[mex]) mex++;
					}

					if (k == r) {
						dp[l][r] = max(dp[l][r], 1 + mex);
						continue;
					}

					dp[l][r] = max(dp[l][r], 1 + mex + dp[k + 1][r]);
				}
				
				ans += dp[l][r];
			}
		}

		cout << ans << "\n";
	}
}
