// https://cses.fi/problemset/task/1071/
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
		ll x, y; cin >> x >> y;
		ll n = max(x, y);
		pair<int, int> p = {-1, 1};
		if (n % 2) swap(p.fr, p.sc);
		ll cor = n * n - n + 1;
		ll ans = cor + p.fr * (n - x) + p.sc * (n - y);
		cout << ans << "\n";
	}
}
