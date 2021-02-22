// https://www.codechef.com/LRNDSA07/problems/ATCH
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

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		ll dp[n + 10][2] = {};
		ll arr[n + 10] = {};

		for (int i = 0; i < n; i++) cin >> arr[i];

		if (n == 1) {
			cout << arr[0] << "\n";
			continue;
		}
		ll ans = -1e15, min_el = 1e15, max_el = arr[0];
		dp[0][0] = arr[0], dp[0][1] = arr[0];

		for (int i = 1; i < n; i++) {
			max_el = max(arr[i], max_el);
			dp[i][1] = arr[i];
			dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);
			if (dp[i - 1][0] + arr[i] >= arr[i]) {
				dp[i][1] = min(arr[i], dp[i - 1][1]);
			}

			ll el = min(dp[i - 1][1], arr[i]);
			if (dp[i - 1][0] + arr[i] > ans) {
				ans = dp[i - 1][0] + arr[i];
				min_el = el;
			}
			else if (dp[i - 1][0] + arr[i] == ans and el < min_el) {
				min_el = el;
			}
		}

		if (ans > max_el) {
			cout << max(ans, ans - min_el) << "\n";
		}	
		else if (ans == max_el) {
			cout << max(ans, max(max_el, ans - min_el)) << "\n";
		}
		else cout << max_el << "\n";
	}	
}
