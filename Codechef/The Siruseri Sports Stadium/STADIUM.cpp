// https://www.codechef.com/IARCSJUD/problems/STADIUM
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n; cin >> n;
	vector<pair<int, int> > v = {};

	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a + b + 1, a});
	}

	sort(v.begin(), v.end());

	pair<int, int> end = {0, 0};
	int ans = 0;

	for(int i = 0; i < n; i++) {

		if (v[i].sc >= end.fr) {
			ans++;
			end = v[i];
		}
	}

	cout << ans;
}
