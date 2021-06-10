// https://cses.fi/problemset/task/1091/
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

	int n, m; cin >> n >> m;
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		s.insert(a);
	}

	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		auto b = upper_bound(s.begin(),s.end(), a);
		if (b == s.begin()) cout << -1 << "\n";
		else {
			b--;
			cout << (*b) << "\n";
			s.erase(b);
		}
	}

}

