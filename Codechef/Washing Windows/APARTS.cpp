// https://www.codechef.com/LRNDSA07/problems/APARTS
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		int mat[n + 10][m + 10] = {};
		int dirt[n + 10][m + 10] = {}, ans[n + 10][m + 10] = {};
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> mat[i][j];

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int b = max(dirt[i - 1][j - 1], max(dirt[i - 1][j], dirt[i - 1][j + 1]));
				if (b < mat[i][j]) ans[i][j] = 1;
				dirt[i][j] = max(b, mat[i][j]); 
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << ans[i][j];
			}
			cout << "\n";
		}
	}
}
