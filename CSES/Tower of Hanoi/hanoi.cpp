// https://cses.fi/problemset/task/2165/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;

void solve(int n, int a, int b) {
	if (n == 1) {
		cout << a << " " << b << "\n";
		return;
	}

	solve(n - 1, a, 6 - a - b);
	cout << a << " " << b << "\n";
	solve(n - 1, 6 - a - b, b);
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	cout << pow(2, n) - 1 << "\n";
	solve(n, 1, 3);
}
