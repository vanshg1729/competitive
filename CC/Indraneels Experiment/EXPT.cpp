// https://www.codechef.com/IARCSJUD/problems/EXPT
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n; cin >> n;

	int two = 2;
	int arr[two][n + 10] = {};

	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	int dp[n + 10][n + 10] = {};
	pair<int, int> par[n + 10][n + 10] = {}, cur = {0, 0};

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k < i; k++) {
				for (int l = 1; l < j; l++) {
					if (arr[0][i] - arr[0][k] == arr[1][j] - arr[1][l]) {
						if (dp[k][l] + 1 > dp[i][j]) {
							dp[i][j] = dp[k][l] + 1;
							par[i][j] = {k, l};
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] > dp[cur.fr][cur.sc]) {
				cur = {i, j};
			}
		}
	}

	vector<int> v[2] = {};

	while (cur != make_pair(0, 0)) {
		v[0].push_back(arr[0][cur.fr]);
		v[1].push_back(arr[1][cur.sc]);
		cur = par[cur.fr][cur.sc];
	}

	int m = v[0].size();
	cout << m << "\n";

	for (int j = 0; j < 2; j++) {
		for (int i = m - 1; i >= 0; i--) {
			cout << v[j][i] << " ";
		}
		cout << "\n";
	}
}
