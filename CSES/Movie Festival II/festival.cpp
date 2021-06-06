// https://cses.fi/problemset/task/1632/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long

bool comp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.sc < p2.sc) return true;
	if (p2.sc < p1.sc) return false;
	return p1.fr < p2.fr;
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;
	pair<int, int> arr[n + 10] = {};
	for (int i = 0; i < n; i++) cin >> arr[i].fr >> arr[i].sc;

	sort(arr, arr + n, comp);

	int count = 1;
	multiset<int> s; s.insert(arr[0].sc);

	for (int i = 1; i < n; i++) {
		auto b = s.upper_bound(arr[i].fr);
		if (b != s.begin()) b--;
		if ((*b) <= arr[i].fr) {
			count++;
			s.insert(arr[i].sc);
			s.erase(b);
		}
		else if (s.size() < k) {
			count++;
			s.insert(arr[i].sc);
		}
	}

	cout << count;
}
