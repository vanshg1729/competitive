// https://cses.fi/problemset/task/2428/
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

	int n, k; cin >> n >> k;
	int arr[n + 10] = {};
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int dis = 1, st = 1;
	ll count = 1;
	map<int, int> m; m[arr[1]] = 1;

	for (int i = 2; i <= n; i++) {
		if (m[arr[i]] == 0) dis++;
		m[arr[i]]++;

		while (dis > k) {
			if (m[arr[st]] == 1) dis--;
			m[arr[st]]--;
			st++;
		}

		count += (ll)(i - st + 1);
	}

	cout << count;
}
