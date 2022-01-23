/* https://codeforces.com/contest/1629/problem/B */
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
		int l, r, k; cin >> l >> r >> k;
		int size = r - l + 1;

		if (size == 1){
			if (l != 1) cout << "YES\n";
			else cout << "NO\n";
			continue;
		}

		int odd = size / 2 + (size % 2) * (r % 2);
		//cout << "SIze : " << size << endl;
		//cout << "Odd : " << odd << endl;
		int min_step = 0;

		while (odd > 1){
			int steps = odd/2;
			odd = odd/2 + (odd % 2);
			min_step += steps;
		}

		min_step++;
		//cout << min_step << endl;
		if (k < min_step){
			cout << "NO\n";
		}
		else cout << "YES\n";
	}
}
