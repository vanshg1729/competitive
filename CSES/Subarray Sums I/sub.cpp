// https://cses.fi/problemset/task/1660/
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

	int n, x; cin >> n >> x;
	int arr[n + 10] = {};
	for (int i = 1; i <= n; i++) cin >> arr[i];

	vector<ll> v; v.push_back(0);
	for (int i = 1; i <= n; i++) v.push_back(v[i - 1] + arr[i]);

	int count = 0;
	for (int i = 1; i <= n; i++) {
		ll k = v[i] - x;
		auto b = upper_bound(v.begin(), v.begin() + i, k - 1);
		if (*b == k) count++;
	}

	cout << count;
}



