// https://www.codechef.com/IARCSJUD/problems/WORDHOP
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(string b, string c) {
	if (b == c or b.size() - c.size() > 1 or b.size() - c.size() < 0) return false;

	if (b.size() == c.size()) {

		for (int i = 0; i < b.size(); i++) {
			char d = b[i];

			for (int j = i + 1; j < b.size(); j++) {
				if (b[j] > d) {
					b[i] = b[j];
					if (b == c) return true;
					b[i] = d;
				}
			}
		}

		return false;
	}
	else {

		for (int i = 0; i < b.size(); i++) {
			string d = "";
			for (int j = 0; j < b.size(); j++) {
				if (j != i) d += b[j];
			}
			if (d == c) return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n; cin >> n;
	string a[n + 10] = {};
	int indeg[n + 10] = {};
	
	for (int i = 1; i <= n; i++) cin >> a[i];

	vector<int> adj[n + 10] = {};

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (comp(a[i], a[j])) {
				adj[i].push_back(j);
				indeg[j]++;
			}
		}
	}		

	queue<int> q;
	int dis[n + 10] = {};
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			q.push(i);
			dis[i] = 1;
		}
	}

	while (!q.empty()) {
		int b = q.front();
		q.pop();

		ans = max(dis[b], ans);
		for (auto u : adj[b]) {
			indeg[u]--;
			dis[u] = max(dis[u], dis[b] + 1);
			if (indeg[u] == 0) {
				q.push(u);
			}
		}
	}

	cout << ans;
}
