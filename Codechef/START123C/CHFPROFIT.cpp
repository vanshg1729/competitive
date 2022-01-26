/* https://www.codechef.com/START23C/problems/CHFPROFIT */
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
		long long x, y, z; cin >> x >> y >> z;

		long long ans = x * (z - y);
		cout << ans << endl;
	}
}
