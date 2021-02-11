// https://www.codechef.com/IARCSJUD/problems/EQGIFTS
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n; cin >> n;
	int a[n + 10] = {};

	int sum = 0;
	for(int i = 1; i <= n; i++) {
		int b, c; cin >> b >> c;
		a[i] = max(b, c) - min(b, c);
		sum += a[i];
	}

	int s = sum;
	bool dp[n + 10][s + 10] = {};
	dp[0][0] = 1;

	int ans = INT_MAX;
	for(int i = 1; i <= n; i++) {

		for(int j = 0; j <= s; j++) {
			if (j - a[i] < 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j - a[i]] | dp[i - 1][j];
			if(i == n and dp[i][j]) ans = min(ans, abs(sum - 2*j));
		}
	} 

	cout << ans;
}
