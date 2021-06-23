// https://cses.fi/problemset/task/1094/
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
	int prev; cin >> prev;
	ll cnt = 0;
	for (int i = 2; i <= n; i++) {
		int a; cin >> a;
		if (a >= prev) {
			prev = a;
		}
		else {
			cnt += prev - a;
		}
	}

	cout << cnt;
}
