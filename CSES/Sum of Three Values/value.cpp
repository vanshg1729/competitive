// https://cses.fi/problemset/task/1641/
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
	pair<int, int> arr[n + 10] = {};
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].fr;
		arr[i].sc = i;
	}

	sort(arr + 1, arr + n + 1);

	for (int i = 2; i < n; i++) {
		for (int j = 1; j < i; j++) {
			int k = x - arr[i].fr - arr[j].fr;
			if (k < arr[i].fr) continue;
			if (k == arr[i + 1].fr) {
				cout << arr[i + 1].sc << " " << arr[i].sc << " " << arr[j].sc;
				return 0;
			}

			auto id = upper_bound(arr + i + 1, arr + n + 1, make_pair(k, 0)) - arr;
			if (arr[id].fr == k) {
				cout << arr[j].sc << " " << arr[i].sc << " " << arr[id].sc;
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE";
}
