/* https://www.codechef.com/START23C/problems/AVGOF3 */
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
		int x; cin >> x;
		cout << x - 1 << " " << x << " " << x + 1 << endl;
	}
}
