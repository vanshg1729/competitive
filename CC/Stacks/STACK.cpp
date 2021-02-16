// https://www.codechef.com/LRNDSA04/problems/STACKS
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int T; cin >> T;

	while (T--) {
		int n; cin >> n;

		vector<int> v = {};
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			v.push_back(a);
		}

		vector<int> tops;

		for (int i = 0; i < n; i++) {
			auto b = upper_bound(tops.begin(), tops.end(), v[i]);
			if (b == tops.end()) tops.push_back(v[i]);
			else {
				auto a = b - tops.begin();
				tops[a] = v[i];
			}
		}

		cout << tops.size() << " ";
		for (auto u : tops) cout << u << " ";
		cout << "\n";
	}
}
