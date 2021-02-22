// https://www.codechef.com/LRNDSA07/problems/AMSGAME2
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
		int n; cin >> n;
		int arr[n + 10] = {};
		for (int i = 0; i < n; i++) cin >> arr[i];

		int cnt[10010] = {};
		for (int i = 0; i < n; i++) {
			for (int j = 1; j * j <= arr[i]; j++) {
				if (arr[i] % j == 0) {
					cnt[j]++;
					if (j != arr[i]/j) cnt[arr[i]/j]++;
				}
			}
		}

		ll gcd[10010] = {};
		for (int i = 10000; i >= 1; i--) {
			if (!cnt[i]) continue;
			gcd[i] = (1LL << cnt[i]) - 1;
			for (int j = 2 * i; j <= 10000; j += i) {
				gcd[i] -= gcd[j];
			}
		}

		cout << gcd[1] << "\n";
	}
}
