// https://www.codechef.com/LRNDSA07/problems/AUHASH
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

	int max_sum = 0;
	for (int i = 1; i <= 52; i++) max_sum += i;
	int T; cin >> T;
	int Q = T;
	while (T--) {
		int l, s; cin >> l >> s;
		if (l > 52 or s > max_sum) {
			cout << "Case " << Q - T << ": " << "0\n";
			continue;
		}
		
		int coin = 53;
		ll dp[l + 1][coin][s + 1] = {};
		for (int i = 0; i < 53; i++) dp[0][i][0] = 1;

		for (int i = 1; i <= l; i++) {
			for (int j = 1; j < 53; j++) {
				for (int k = 1; k <= s; k++) {
					dp[i][j][k] = dp[i][j - 1][k];
					if (k - j >= 0) dp[i][j][k] += dp[i - 1][j - 1][k - j];
				}
			}
		}

		cout << "Case " << Q - T << ": " << dp[l][52][s] << "\n";
	}
}
