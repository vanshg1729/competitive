// https://cses.fi/problemset/task/1642/
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
	ll x; cin >> x;
	ll sum = 0; int id = 0;
	ll arr[n + 10] = {};
	for (int i = 1; i <= n; i++) cin >> arr[i];

	bool b = false;
	set<ll> s; s.insert(arr[1] + arr[2]);
	
	for (int i = 3; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int k = x - arr[i] - arr[j];
			if (s.count(k)) {
				cout << j << " " << i << " ";
				b = true;
				id = i - 1;
				sum = k;
				break;
			}
		}

		if (b) break;

		for (int j = i - 1; j > 0; j--) s.insert(arr[i] + arr[j]);
	}

	for (int i = 1; i <= id; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] + arr[j] == sum) {
				cout << i << " " << j;
				return 0;
			}
		} 
	}

	cout << "IMPOSSIBLE";
}

