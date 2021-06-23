// https://cses.fi/problemset/task/1754/
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
	while (T--) {
		ll a, b; cin >> a >> b;
		ll x = 2 * b - a, y = 2 * a - b;
		if (x < 0 or y < 0 or x % 3 or y % 3) cout << "NO\n";
		else cout << "YES\n";
	}
}

