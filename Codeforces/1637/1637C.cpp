/* https://codeforces.com/contest/1637/problem/C */
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
		int n; cin >> n;
		int arr[n + 10] = {};
		for (int i = 0; i < n; i++) cin >> arr[i];
		if (n == 3 and (arr[1] % 2)) {
			cout << -1 << "\n";
			continue;
		}

		ll total = 0, stacks = 0;
		bool all_one = true;

		for (int i = 1; i < n - 1; i++) {
			if (arr[i] != 1) all_one = false;
			total += arr[i];
			if (arr[i] % 2) stacks++;
		}

		if (all_one) cout << -1 << "\n";
		else cout << (total + stacks)/2 << "\n";

	}
}
