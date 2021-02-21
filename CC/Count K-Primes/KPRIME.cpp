// https://www.codechef.com/LRNDSA07/problems/KPRIME
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5;
int dp[maxn + 10][6] = {};
int fac[maxn + 10] = {};

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 2; i <= 1e5; i++) {
		bool prime = false;
		for (int j = 1; j < 6; j++) {
			dp[i][j] = dp[i - 1][j];
		}

		if (fac[i] == 0) {
			prime = true;
			fac[i]++;
		}
		if (fac[i] < 6) dp[i][fac[i]]++;
		if (!prime) continue;

		for (int j = 2 * i; j <= 1e5; j += i) {
			fac[j]++;
		}
	}

	int T; cin >> T;

	while (T--) {
		int a, b, k; cin >> a >> b >> k;
		cout << dp[b][k] - dp[a - 1][k] << "\n";
	}
}
