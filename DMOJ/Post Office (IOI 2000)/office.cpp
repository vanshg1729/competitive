// https://dmoj.ca/problem/ioi00p5
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = INT_MAX;
const int maxn = 310, maxp = 40;

int arr[maxn] = {}, sum[maxn][maxn] = {};
int dp[maxn][maxp] = {}, par[maxn][maxp] = {};
bool seen[maxn][maxp] = {};
int n, p;

int f(int i, int k) {

	if (seen[i][k]) return dp[i][k];
	if (i > 0 and k == 0) return INF;
	if (i == 0 and k > 0) return INF;
	if (i == 0 and k == 0) return 0;

	dp[i][k] = INF;
	for (int j = i - 1; j >= 0; j--) {
		int d = f(j, k - 1);
		if (d == INF) continue;
		if (d + sum[j][i] < dp[i][k]) {
			dp[i][k] = d + sum[j][i];
			par[i][k] = j;
		}
	}

	seen[i][k] = 1;
	return dp[i][k];
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> p;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	arr[0] = arr[n + 1] = 1e5;
	
	for (int i = 0; i < n + 2; i++) {
		for (int j = i + 1; j < n + 2; j++) {
			for (int k = i + 1; k < j; k++) {
				sum[i][j] += min(abs(arr[k] - arr[i]), abs(arr[k] - arr[j]));
			}
		}
	}

	/*for (int i = 0; i < n + 2; i++) {
		for (int j = i + 1; j < n + 2; j++) {
			cout << sum[i][j] << " ";
		}
		cout << "\n";
	}*/

	int ans = f(n + 1, p + 1);
	cout << ans << "\n";

	vector<int> pos = {};
	int cur = n + 1;
	cur = par[cur][p + 1];

	while (cur) {
		pos.push_back(cur);
		cur = par[cur][p];
		p--;
	}

	sort(pos.begin(), pos.end());
	for (auto u : pos) cout << arr[u] << " ";
}
