// https://www.codechef.com/IARCSJUD/problems/PYRAMID
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int m; cin >> m;
	vector<pair<int, int> > v = {};
	for(int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		v.push_back({min(a,b), max(a,b)});
	}

	sort(v.begin(), v.end());

	int ans = 1;
	for(int i = 0; i < v.size(); i++) {
		if (v[i].fr >= ans) ans++;
	}

	cout << ans - 1;
}
