// https://cses.fi/problemset/task/2183/
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
	int arr[n + 10] = {};
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);
	ll ans = (arr[0] == 1) ? 2 : 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] > ans) break;
		else {
			ans += arr[i];
		}
	}

	cout << ans;
}
