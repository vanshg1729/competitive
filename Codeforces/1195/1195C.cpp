/* https://codeforces.com/contest/1195/problem/C */
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
	
	int n; cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < n; j++) cin >> b[j];

	long long dp[n][2] = {};
	dp[0][0] = a[0], dp[0][1] = b[0];

	for (int i = 1; i < n; i++){
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + b[i]);
	}

	cout << max(dp[n - 1][0], dp[n - 1][1]);
}
