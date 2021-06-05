// https://cses.fi/problemset/task/1661/
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
	vector<pair<ll, int> > v = {}; v.push_back({0, 0});

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		v.push_back({v[i - 1].fr + arr[i], i});
	}

	sort(v.begin(), v.end());
	ll count = 0;
	ll pref = 0;

	for (int i = 1; i <= n; i++) {
		pref += arr[i];
		ll k = pref - x;
		auto its = lower_bound(v.begin(), v.end(), make_pair(k, -1));
		auto itg = upper_bound(v.begin(), v.end(), make_pair(k, i - 1));
		itg--;
		if ((*itg).fr == k) count += itg - its + 1;
	}

	cout << count;
}
