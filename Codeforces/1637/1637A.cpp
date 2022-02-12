/* https://codeforces.com/contest/1637/problem/A */
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
		int arr[n] = {};
		for (int i = 0; i < n; i++) cin >> arr[i];

		int pref[n] = {}, suff[n] = {};
		pref[0] = arr[0];
		suff[n - 1] = arr[n - 1];

		for (int i = 1; i < n; i++) pref[i] = max(pref[i - 1], arr[i]);

		for (int i = n - 2; i >= 0; i--) suff[i] = min(suff[i + 1], arr[i]);

		bool sorted = true;

		for (int i = 0; i < n - 1; i++) {
			if (pref[i] > suff[i + 1]) sorted = false;
		}

		if (sorted) cout << "NO\n";
		else cout << "YES\n";
	}
}
