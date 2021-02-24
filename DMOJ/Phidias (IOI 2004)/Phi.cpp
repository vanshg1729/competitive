// https://dmoj.ca/problem/ioi04p4
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;

const int INF = INT_MAX;
const int maxw = 610;

vector<pair<int, int>> v = {};
int dp[maxw][maxw] = {}, seen[maxw][maxw] = {};
int min_area = INF;
int w, h, n;

int f(int a, int b) {
	
	if (seen[a][b]) return dp[a][b];
	if (a * b < min_area) return a * b;

	auto it = lower_bound(v.begin(), v.end(), make_pair(a, b)) - v.begin();
	if (it != n) {
		if (v[it].fr == a and v[it].sc == b) {
			seen[a][b] = 1;
			return 0;
		}
	}

	dp[a][b] = INF;
	for (int i = 1; i < a; i++) {
		dp[a][b] = min(f(i, b) + f(a - i, b), dp[a][b]);
	} 

	for (int j = 1; j < b; j++) {
		dp[a][b] = min(f(a, j) + f(a, b - j), dp[a][b]);
	}

	seen[a][b] = 1;
	return dp[a][b];
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> w >> h >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		min_area = min(a * b, min_area);
		v.push_back({a, b});
	}

	sort(v.begin(), v.end());

	cout << f(w, h);
}
