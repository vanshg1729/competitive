// https://cses.fi/problemset/task/1620/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long

const int maxn = 2*1e5 + 10;
int arr[maxn] = {};
int n,k;

bool check(ll t) {
	ll mach = 0;
	for (int i = 1; i <= n; i++) {
		mach += (t/arr[i]);
		if (mach >= k) return true;
	}

	return false;
}

long long bin_search() {
	long long ans = 0;
	for (long long d = (ll)1e18; d >= 1; d /= 2) {
		while (ans + d <= (ll)1e18 and !check(ans + d)) ans += d;
	}
	return ans + 1;
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	cout << bin_search();
}
