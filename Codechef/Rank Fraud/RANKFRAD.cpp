// https://www.codechef.com/IARCSJUD/problems/RANKFRAD
#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n; cin >> n;

	int win[n + 10][n + 10] = {};
	for (int i = 1; i <= n; i++) {
		int m; cin >> m;
		for (int j = 1; j <= m; j++) {
			int a; cin >> a;
			win[i][a] = 1;
		}
	}

	vector<int> ans(1, 1);

	for (int i = 2; i <= n; i++) {

		if (win[ans.back()][i]) {
			ans.push_back(i);
		}
		else if (win[i][ans.front()]) {
			ans.insert(ans.begin(), i);
		}
		else {
			for (int j = 0; j < ans.size(); j++) {
				if (win[ans[j]][i] and win[i][ans[j + 1]]) {
					ans.insert(ans.begin() + j + 1, i);
					break;
				}
			}
		}
	}

	cout << "YES\n";
	for (auto u : ans) cout << u << " ";
}
