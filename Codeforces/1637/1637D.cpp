/* https://codeforces.com/contest/1637/problem/D */
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long int
const int maxn = 2e5 + 10;

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;

		if (n == 1) {
			cin >> n >> n;
			cout << 0 << "\n";
			continue;
		}

		ll a[n + 10] = {}, b[n + 10] = {};
		ll ans = 0, x = 0, y = 0;
		ll coins[n + 10] = {};
		ll max_sum = 0;
		ll square = 0;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			square += (a[i] * a[i]);
			x += a[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> b[i];
			square += (b[i] * b[i]);
			y += b[i];
		}

		if (x > y) {
			swap(x, y);
			for (int i = 0; i < n; i++) swap(a[i], b[i]);
		}
		
		for (int i = 0; i < n; i++) {
			ll c = b[i] - a[i];
			max_sum += abs(c);
			coins[i] = c;
		}

		sort(coins, coins + n, greater<ll>());

		square = square * (n - 2);
		ans = square + (x * x + y * y);
		
		ll dp[max_sum + 10][n + 10] = {};

		dp[0][0] = 1;
		dp[coins[0]][0] = 1;
		ll sum = coins[0];
		ll add = (x + sum) * (x + sum) + (y - sum) * (y - sum);
		ans = min(ans, square + add);

		for (int i = 1; i < n; i++) {
			for (ll s = 0; s <= max_sum; s++) {
				ll sum = s - coins[i];
				dp[s][i] = dp[s][i - 1];
				if (sum >= 0 and sum <= max_sum) dp[s][i] |= dp[sum][i - 1]; 

				if (dp[s][i] == 1) {
					ll add = (x + s) * (x + s) + (y - s) * (y - s);
					ans = min(ans, square + add);
				}
			}
		}

		cout << ans << "\n";
	}
}
