// https://cses.fi/problemset/task/1687/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;
int par[maxn][20] = {};

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q; cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		int a; cin >> a;
		par[i][0] = a;
	}

	for (int k = 1; k <= 18; k++) {
		for (int i = 2; i <= n; i++) {
			par[i][k] = par[par[i][k - 1]][k - 1];
		}
	}

	while (q--) {
		int a,k; cin >> a >> k;
		int p = 0;
		while (k >= 1) {
			if (k % 2) {
				a = par[a][p];
			}
			k /= 2;
			p++;
		}

		if (a == 0) cout << -1 << "\n";
		else cout << a << "\n";
	}
}
