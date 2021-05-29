// https://cses.fi/problemset/task/1164/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first

struct tim{
	int st, en, id;
};

bool comp(tim a, tim b) {
	if (a.st < b.st) return true;
	if (a.st > b.st) return false;
	return a.en < b.en;
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	tim arr[n + 10] = {};
	for (int i = 0; i < n; i++) {
		cin >> arr[i].st >> arr[i].en;
		arr[i].id = i;
	}

	sort(arr, arr + n,comp);

	int count = 1, col[n + 10] = {}; col[arr[0].id] = 1;
	set<pair<int, int> > s; s.insert({arr[0].en, 1});

	for (int i = 1; i < n; i++) {
		auto b = *s.begin();

		if (b.fr < arr[i].st) {
			col[arr[i].id] = b.sc;
			s.erase(b);
		}
		else {
			count++;
			col[arr[i].id] = count;
		}

		s.insert({arr[i].en, col[arr[i].id]});
	}

	cout << count << "\n";
	for (int i = 0; i < n; i++) cout << col[i] << " ";
}




