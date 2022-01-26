/* https://www.codechef.com/START23C/problems/MAXVAC */
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
	while (T--){
		int n, k; cin >> n >> k;

		int arr[n + 10] = {};
		int pref[n + 10] = {};
		int dp[n + 10][2] = {};

		for (int i = 1; i <= n; i++){
			char c; cin >> c;
			arr[i] = c - '0';
			pref[i] = pref[i - 1] + arr[i];
		}

		for (int i = k; i <= n; i++){
			int count = pref[i] - pref[i - k];
			int add1 = 0, add2 = 0;
			if (count == 0) add1 = 1;
			if (count == 1) add2 = 1;
			
			dp[i][0] = dp[i - 1][0];
			dp[i][0] = max(dp[i - k][0] + add1, dp[i][0]);
			dp[i][1] = dp[i - 1][1];
			dp[i][1] = max(dp[i][1], max(dp[i - k][1] + add1, dp[i - k][0] + add2));
		}

		cout << dp[n][1] << "\n";
	}

}
