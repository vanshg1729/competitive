// https://cses.fi/problemset/task/1631/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	ll sum = 0, m = 0;
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		sum += a;
		m = max(m, a);
	}

	if (m > sum - m) cout << 2*m;
	else cout << sum;
}
