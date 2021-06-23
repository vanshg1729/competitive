// https://cses.fi/problemset/task/1092/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n; cin >> n;
	ll sum = (n * (n + 1))/2;
	if (sum % 2) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	sum /= 2;
	vector<int> a = {}, b = {};

	for (int i = n; i >= 1; i--) {
		if (i <= sum) {
			sum -= i;
			a.push_back(i);
		}
		else b.push_back(i);
	}

	cout << a.size() << "\n";
	for (auto u : a) cout << u << " ";
	cout << "\n";
	cout << b.size() << "\n";
	for (auto u : b) cout << u << " ";
}
