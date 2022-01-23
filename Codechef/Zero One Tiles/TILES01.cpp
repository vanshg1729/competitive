#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
const int MOD = 15746;

int main(){

	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n; cin >> n;
	int dp[n + 10] = {};
	dp[0] = dp[1] = 1;
	dp[2] = 2;

	for(int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= MOD;
	}

	cout << dp[n];
}
