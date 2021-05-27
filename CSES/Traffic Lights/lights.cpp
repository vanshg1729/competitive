// https://cses.fi/problemset/task/1163/
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second

bool comp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.sc - p1. fr > p2.sc - p2.fr) return false;
	if (p1.sc - p1.fr < p2.sc - p2.fr) return true;
	return p1.fr < p2.fr;
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x,n; cin >> x >> n;

	set<pair<int, int> > range;
	set<pair<int, int>, decltype(&comp)> s(&comp);

	range.insert({0, x}); s.insert({0, x});

	for (int i = 1; i <= n; i++) {
		int pos; cin >> pos;
		if (pos == 0 or pos == x) {
			auto it = s.end(); it--;
			cout << (*it).sc - (*it).fr << " ";
			continue;			
		}

		auto it = range.lower_bound({pos, pos}); it--;
		auto el = *it;
		range.erase(el); range.insert({el.fr, pos}); range.insert({pos, el.sc});
		s.erase(el); s.insert({el.fr, pos}); s.insert({pos, el.sc});

		it = s.end(); it--;
		cout << (*it).sc - (*it).fr << " ";
	}

}
