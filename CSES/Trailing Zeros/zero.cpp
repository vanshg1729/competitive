// https://cses.fi/problemset/task/1618/
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

	ll num = 5;
	ll cnt = 0;

	ll n; cin >> n;
	while (num <= n) {
		cnt += n / num;
		num *= 5;
	}

	cout << cnt;
}
