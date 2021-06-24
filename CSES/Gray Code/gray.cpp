// https://cses.fi/problemset/task/2205
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;

void print(int a, int n) {
	for (int i = n - 1; i >= 0; i--) {
		if (a & (1 << i)) cout << 1;
		else cout << 0;
	}

	cout << "\n";
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> v = {0, 1};

	for (int i = 1; i < n; i++) {
		int add = 1 << i;
		int m = v.size();
		for (int j = m - 1; j >= 0; j--) {
			v.push_back(add + v[j]);
		}
	}

	for (auto u : v) print(u, n);
}
