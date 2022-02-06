/* https://codeforces.com/contest/1634/problem/C */
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
		int n, k; cin >> n >> k;
		if (n % 2 and k != 1) {
			cout << "NO\n";
			continue;
		}

		if (k == 1){
			cout << "YES\n";

			for (int i = 1; i <= n; i++) cout << i << "\n";

			continue;
		}
		
		cout << "YES\n";
		int size = n / 2;

		int j = 0;
		for (int row = 1; row <= size; row++) {
			for (int col = 1; col <= k; col++) {
				j++;
				cout << 2 * j << " ";
			}

			cout << "\n";
		}
		
		j = 0;

		for (int row = 1; row <= size; row++) {
			for (int col = 1; col <= k; col++) {
				j++;
				cout << 2 * j - 1 << " ";
			}
			
			cout << "\n";
		}
	}
}
