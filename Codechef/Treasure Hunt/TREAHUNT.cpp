// https://www.codechef.com/IARCSJUD/problems/TREAHUNT
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

	int m, t, s, n; cin >> m >> t >> s >> n;
	pair<int, int> st = {s, 1};

	pair<int, int> child[m + 10][t + 10] = {};

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= t; j++) {
			int a, b; cin >> a >> b;
			child[i][j] = {b, a};
		}
	}

	vector<pair<int, int> > cycle = {};

	vector<pair<int, int> > bef_cycle = {};
	pair<int, int> cyc_st = {};

	int seen[m + 10][t + 10] = {};
	
	seen[st.fr][st.sc] = true;

	auto cur = st;


	while (1) {
		auto b = child[cur.fr][cur.sc];

		if (seen[b.fr][b.sc]) {
			cyc_st = b;
			break;
		}

		seen[b.fr][b.sc] = true;
		cur = b;
	}

	cur = st;

	while (cur != cyc_st) {
		bef_cycle.push_back(cur);
		cur = child[cur.fr][cur.sc];
	}

	cycle.push_back(cyc_st);
	cur = child[cyc_st.fr][cyc_st.sc];

	while (cur != cyc_st) {
		cycle.push_back(cur);
		cur = child[cur.fr][cur.sc];
	}

	if (n <= bef_cycle.size()) {
		n--;
		cout << bef_cycle[n].fr;
	}
	else {
		n -= bef_cycle.size() + 1;
		n %= cycle.size();
		cout << cycle[n].fr;
	}
}
