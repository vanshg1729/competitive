// https://cses.fi/problemset/task/1622/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
	set<string> pos;

	sort(s.begin(), s.end());
	do {
		pos.insert(s);
	} while(next_permutation(s.begin(), s.end()));

	cout << pos.size() << "\n";
	for (auto u : pos) cout << u << "\n";
}
