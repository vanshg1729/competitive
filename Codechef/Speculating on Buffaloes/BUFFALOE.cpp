// https://www.codechef.com/IARCSJUD/problems/BUFFALOE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc second
#define fr first

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	int num = k/2;
	long long a[n + 10] = {}, dp[n + 10][num + 10] = {};
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	long long ans = 0;
	for(int k = 1; k <= num; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				dp[i][k] = max(max(dp[i-1][k],dp[i][k]), a[i] - a[j] + dp[j - 1][k - 1]);
				ans = max(ans, dp[i][k]);
			}
		}
	}

	cout << ans;
}
