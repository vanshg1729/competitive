// https://cses.fi/problemset/task/1662/
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
	vector<pair<int, int> > v = {}; v.push_back({0, 0});
	ll count = 0;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		arr[i] = ((a % n) + n) % n;
		int rem = (v[i -1].fr + arr[i])%n;
		v.push_back({rem, i});
	}

	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum = (sum + arr[i]) % n;
		int rem = sum;
		auto sm_it = lower_bound(v.begin(), v.end(), make_pair(rem, -1));
		auto bg_it = upper_bound(v.begin(), v.end(), make_pair(rem, i - 1));
		bg_it--;

		if ((*bg_it).fr == rem) count += bg_it - sm_it + 1;
	}

	cout << count;
}

