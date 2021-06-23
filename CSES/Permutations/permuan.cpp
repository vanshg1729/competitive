// https://cses.fi/problemset/task/1070/
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

	int n; cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}

	if (n < 4) {
		cout << "NO SOLUTION"; 
		return 0;
	}

	for (int i = 2; i <= n; i+=2) cout << i << " ";
	for (int i = 1; i <= n; i+=2) cout << i << " ";
}
