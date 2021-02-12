// https://www.codechef.com/IARCSJUD/problems/TIMBER
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m;
	ll dp[n + 10][m + 10] = {};

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int a; cin >> a;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a;
		}
	}

	int q; cin >> q;

	while (q--) {
		int x_1, y_1, x_2, y_2;
		cin >> x_1 >> y_1 >> x_2 >> y_2;

		ll ans = dp[x_2][y_2] - dp[x_1 - 1][y_2] - dp[x_2][y_1 - 1] 
		+ dp[x_1 - 1][y_1 - 1];
		cout << ans << "\n";
	}
}
