// https://cses.fi/problemset/task/1623/
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

	int n; cin >> n;
	ll arr[n + 10] = {};
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	ll ans = 1e14;

	for (int i = 1; i < (1 << n); i++) {
		ll gr = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) gr += arr[j];
		}

		ans = min(ans, abs(sum - 2 * gr));
	}

	cout << ans;
}

