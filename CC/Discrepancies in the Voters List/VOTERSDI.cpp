#include <bits/stdc++.h>
using namespace std;
int i = 1, j = 1, k = 1;
int n[4] = {};
const int INF = INT_MAX;
vector<int> val[4] = {};

bool in_range() {
	i %= n[1];
	j %= n[2];
	k %= n[3];
	return ((i and j) or (j and k) or (k and i));
}

void increment() {
	int min_el = min(val[1][i], min(val[2][j],val[3][k]));
	if (min_el == val[1][i]) i++;
	else if (min_el == val[2][j]) j++;
	else k++;
}

int main() {

	ios::sync_with_stdio(NULL);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n[1] >> n[2] >> n[3];

	for(int i = 1; i < 4; i++) {
		val[i].push_back(INF);
	}

	for(int i = 1; i < 4; i++) {
		for(int j = 1; j <= n[i]; j++) {
			int a; cin >> a;
			val[i].push_back(a);
		}
	}

	n[1]++; n[2]++; n[3]++;
	vector<int> ans = {};

	while (in_range()) {
		if (val[1][i] == val[2][j]) {
			ans.push_back(val[1][i]);
			i++;
			j++;
		}
		else if (val[2][j] == val[3][k]) {
			ans.push_back(val[2][j]);
			j++;
			k++;
		}
		else if (val[3][k] == val[1][i]) {
			ans.push_back(val[3][k]);
			k++;
			i++;
		}
		else {
			increment();
		}
	}

	cout << ans.size() << "\n";
	for (auto u : ans) cout << u << "\n";
}
