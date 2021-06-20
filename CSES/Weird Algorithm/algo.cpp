// https://cses.fi/problemset/task/1068
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

	ll n; cin >> n;
	cout << n << " ";
	while (n > 1) {
		if (n % 2) n = 3 * n + 1;
		else n /= 2;
		cout << n << " ";
	}

}
