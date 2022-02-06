/* https://codeforces.com/contest/1633/problem/A */
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
		int n; cin >> n;
		if (n % 7 == 0){
			cout << n << "\n";
			continue;
		}

		int rem = n % 7;
		//cout << rem << endl;
		int add = 7 - rem;
		int sub = rem;

		int m = n + add, k = n - sub;
		//cout << m << " " << k << endl;
		if ((n % 100)/10 == (m % 100)/10){
			cout << m << "\n";
		}
		else cout << k << "\n";
	}

}
