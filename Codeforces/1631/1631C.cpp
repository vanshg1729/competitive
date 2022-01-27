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
	while (T--){
		int n, k; cin >> n >> k;
		if (k == n - 1 and n == 4){
			cout << -1 << "\n";
			continue;
		}

		int seen[n + 10] = {};

		if (k == n - 1){
			cout << n - 1 << " " << n - 2 << "\n";
			cout << 1 << " " << 3 << "\n";
			cout << 0 << " " << n - 4 << "\n";
			seen[0] = 1; seen[1] = 1; seen[3] = 1;
			seen[n - 1] = 1; seen[n - 2] = 1; seen[n - 4] = 1;
		}
		else{

			cout << n - 1 << " " << k << "\n";
			seen[n - 1] = 1;
			seen[k] = 1;
			if (k != 0){
				int a = n - k - 1;
				cout << a << " " << 0 << "\n";
				seen[a] = 1;
				seen[0] = 1;
			}
		}

		for (int i = 0; i < n; i++){
			if (seen[i]) continue;
			int b = n - i - 1;
			cout << i << " " << b << "\n";
			seen[i] = 1;
			seen[b] = 1;
		}
	}
}
