// https://cses.fi/problemset/task/1083/
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
	int seen[n + 10] = {};
	for (int i = 1; i < n; i++) {
		int a; cin >> a;
		seen[a] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) if (!seen[i]) {cout << i; return 0;}
}
