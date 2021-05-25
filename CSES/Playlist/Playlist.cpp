// https://cses.fi/problemset/task/1141/
#include <bits/stdc++.h>
using namespace std;


int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n; cin >> n;
	int arr[n + 10] = {};
	map<int,int> m = {};

	for (int i = 1; i <= n; i++) cin >> arr[i];

	int len = 1, st = 1;
	
	m[arr[1]] = 1;
	for (int i = 2; i <= n; i++) {
		if (m[arr[i]] >= st) {
			st = m[arr[i]] + 1;
		}

		m[arr[i]] = i;
		len = max(len, i - st + 1);
	}

	cout << len;
}
