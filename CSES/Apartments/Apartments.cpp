// https://cses.fi/problemset/task/1084/
#include <bits/stdc++.h>
using namespace std;


int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m, k; cin >> n >> m >> k;

	// n = applicants
	// m = apartments
	int app[n + 10] = {}, apar[m + 10] = {};
	for (int i = 0; i < n; i++) cin >> app[i];
	for (int j = 0; j < m; j++) cin >> apar[j];

	sort(app, app + n);
	sort(apar, apar + m);

	int count = 0;
	int i = 0, j = 0;
	while (i < n and j < m) {
		if (abs(app[i] - apar[j]) <= k) {
			i++; j++;
			count++;
		}
		else if (apar[j] > app[i]) i++;
		else j++;
	}

	cout << count;
}
