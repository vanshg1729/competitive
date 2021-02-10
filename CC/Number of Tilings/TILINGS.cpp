// https://www.codechef.com/IARCSJUD/problems/TILINGS
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e4;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n; cin >> n;
	int dp[n + 10][2] = {};

	dp[0][0] = 1; dp[1][0] = 1;
	dp[1][1] = 0;

	for(int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][0] += 2 * dp[i - 1][1];
		dp[i][1] = dp[i - 2][0] + dp[i - 1][1];
		dp[i][0] %= MOD;
		dp[i][1] %= MOD;
	}

	cout << dp[n][0];
}
