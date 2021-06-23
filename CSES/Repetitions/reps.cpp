// https://cses.fi/problemset/task/1069/
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

	int cur = 1, ans = 1;
	string s; cin >> s;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) cur++;
		else cur = 1;
		ans = max(cur, ans);
	}

	cout << ans;
}
