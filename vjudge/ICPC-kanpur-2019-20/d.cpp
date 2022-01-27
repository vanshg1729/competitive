/* https://vjudge.net/contest/477793#problem/D */
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
		if (l != r) cout << k << "\n";
		else cout << 1 << "\n";
	}
}
