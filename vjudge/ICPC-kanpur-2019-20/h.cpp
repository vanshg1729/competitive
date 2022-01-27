/* https://vjudge.net/contest/477793#problem/H */
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e6 + 10;
int prime[maxn] = {};
long long smallest_factor[maxn] = {};

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;

	for (int i = 0; i <= n; i++){
		smallest_factor[i] = 1;
		prime[i] = 1;
	}

	//cout << smallest_factor[4] << endl;
	
	prime[1] = prime[0] = 0;

	for (int i = 2; i <= n; i++){
		if (prime[i] == 0) continue;
		smallest_factor[i] = i;
		long long prod = (long long) i * i;
		if (prod > n) continue;

		for (long long j = i * i; j <= n; j += i){
			prime[j] = 0;
			if (smallest_factor[j] == 1){
				smallest_factor[j] = i;
			}
		}
	}

	/*
	for (int i = 1; i <= n; i++){
		if (prime[i]) cout << "prime : " << i << endl;
	}
	*/

	/*
	for (int i = 2; i <= n; i++){
		cout << "small " << i << " : " << smallest_factor[i] << endl;
	}
	*/


	int Q; cin >> Q;
	while(Q--){
		int a, b; cin >> a >> b;
		if (n == 1){
			cout << -1 << "\n";
			continue;
		}

		if (a == b) {
			cout << 0 << "\n";
			continue;
		}

		if ( (prime[a] and (b % a == 0)) or (prime[b] and (a % b == 0))){
			cout << 1 << "\n";
			continue;
		}

		int hcf = __gcd(a, b);
		if (hcf > 1){
			cout << 2 << "\n";
			continue;
		}
		
		int big_factor = max(smallest_factor[a], smallest_factor[b]);
		long long biggest_num = smallest_factor[a] * smallest_factor[b];
		
		if (big_factor * 2 > n){
			cout << -1 << "\n";
			continue;
		}

		if (biggest_num > n){
			int ans = 4;
			if (smallest_factor[a] != a) ans++;
			if (smallest_factor[b] != b) ans++;
			cout << ans << "\n";
			continue;
		}

		if (prime[a] and prime[b]){
			cout << 2 << "\n";
			continue;
		}

		if (prime[a] or prime[b]) {
			cout << 3 << "\n";
			continue;
		}

		cout << 4 << "\n";
	}
}
