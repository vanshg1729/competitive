/* https://vjudge.net/contest/477793#problem/A */
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;
const long long MOD = 998244353;

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	while (T--){
		int n, m; cin >> n >> m;
		long long temp = 0;
		long long sum_a = 0, sum_b = 0;

		for (int i = 0; i < n; i++){
			cin >> temp;
			sum_a += temp;
			sum_a = ((sum_a % MOD) + MOD) % MOD;
		}

		for (int i = 0; i < m; i++){
			cin >> temp;
			sum_b += temp;
			sum_b = ((sum_b % MOD) + MOD) % MOD;
		}

		int q; cin >> q;

		while (q--){
			int query = 0;
			cin >> query;

			long long add, l, r, x;
			if (query != 3){
				cin >> l >> r >> x;
				add = (r - l + 1) * x;
				add = ((add % MOD) + MOD) % MOD;
			}

			if (query == 1){
				sum_a += add;
				sum_a = ((sum_a % MOD) + MOD) % MOD;
			}
			else if (query == 2){
				sum_b += add;
				sum_b = ((sum_b % MOD) + MOD) % MOD;
			}
			else{
				long long product = sum_a * sum_b;
				product = ((product % MOD) + MOD) % MOD;
				cout << product << "\n";
			}
		}
	}

}
