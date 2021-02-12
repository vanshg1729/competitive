// https://www.codechef.com/IARCSJUD/problems/DRAWFIX
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr first
#define sc second

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n; cin >> n;
	set<int> remain;
	int seen[n + 10] = {};

	vector<pair<int, int> > siru = {}, naval = {};

	for (int i = 1; i <= n; i++) remain.insert(i);

	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		siru.push_back({a, i});
	}

	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		naval.push_back({a, i});
	}

	sort(siru.begin(), siru.end());
	sort(naval.begin(), naval.end());

	int i = 0, j = 0;
	int ans = 0;

	while (i < n) {

		if (siru[i].fr > naval[j].fr) {
			seen[siru[i].sc] = naval[j].sc;
			remain.erase(naval[j].sc);
			i++; j++;
			ans++;
		}
		else {
			i++;
		}
	}

	cout << ans << "\n";

	for (int i = 1; i <= n; i++) {
		if (seen[i] != 0) cout << seen[i] << "\n";
		else {
			auto a = remain.begin();
			cout << *a << "\n";
			remain.erase(a);
		}
	}
}
