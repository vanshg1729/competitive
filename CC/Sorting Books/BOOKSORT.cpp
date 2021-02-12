// https://www.codechef.com/IARCSJUD/problems/BOOKSORT
#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
const int INF = 1e9;
int a[maxn] = {};
int n;

int LIS() {

	vector<int> d(n + 1, INF);
	d[0] = -INF;

	for (int i = 1; i <= n; i++) {
		auto j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		if (a[i] >= d[j - 1] and a[i] < d[j]) {
			d[j] = a[i];
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (d[i] < INF) ans = i;
	}

	return ans;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	cout << n - LIS();
}
