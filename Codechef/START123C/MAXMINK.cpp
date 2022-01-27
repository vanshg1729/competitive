#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// dp[i][j][s] = max(dp[i - 1][j - 1][s - ai] + bi, dp[i - 1][j][s])

	int T; cin >> T;
	while (T--){
		int n, k; cin >> n >> k;

		int a[n], b[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int j = 0; j < n; j++) cin >> b[j];
		
		int dp[k + 1][1601] = {};
		for (int j = 0; j <= k; j++){
			for (int s = 0; s <= 1600; s++){
				dp[j][s] = -1;
			}
		}

		dp[0][0] = 0;

		for (int i = 0; i < n; i++){
			int val = a[i];
			for (int j = k - 1; j >= 0; j--){
				for (int s = 0; s <= 1600; s++){
					if (dp[j][s] != -1){
						dp[j + 1][s + val] = max(dp[j + 1][s + val], dp[j][s] + b[i]);
					}
				}
			}
		}
		
		int ans = 0;
		for (int s = 0; s <= 1600; s++){
			ans = max(ans, min(s, dp[k][s]));
		}

		cout << ans << "\n";
	}
}
