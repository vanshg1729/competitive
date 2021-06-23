// https://cses.fi/problemset/task/1617/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;
const int MOD = 1e9 + 7;

ll solve(int a, int p) {
	if (p == 1) return a % MOD;

	ll b = solve(a, p / 2);
	ll ans = b * b;
	ans % MOD;
	if (p % 2) ans *= a;
	return ans % MOD;
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	cout << solve(2, n);
}
