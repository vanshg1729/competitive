// https://www.codechef.com/IARCSJUD/problems/LEAFEAT/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = (1 << 20) + 10;
ll lc[MAXN] = {};

ll lcm(ll a, ll b) {

	ll res = (a * b)/__gcd(a, b);
	if (res > (ll) 1e9) return 1e9 + 1;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ll n, k; cin >> n >> k;

	int a[k + 10] = {};
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < k; i++) {
		lc[1 << i] = a[i];
	}

	for (int i = 1; i < (1 << k); i++) {

		if (lc[i] == 0) {
			lc[i] = lcm(lc[i ^ (i & -i)], lc[(i & -i)]);
		}
	}

	ll ans = 0;

	for (int i = 1; i < (1 << k); i++) {

		if (__builtin_parity(i)) {
			ans += (ll) (n - 1)/lc[i] + 1;
		}
		else {
			ans -= (ll) (n - 1)/lc[i] + 1;
		}
	}

	cout <<n - ans;
}
