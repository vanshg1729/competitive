// https://cses.fi/problemset/task/1630/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	pair<int, int> arr[n + 10] = {};
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].fr >> arr[i].sc;
		ans += arr[i].sc;
	}

	ll t = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		t += arr[i].fr;
		ans -= t;
	}

	cout << ans;
}

