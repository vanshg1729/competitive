// https://www.codechef.com/IARCSJUD/problems/NUMTRIPL
#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define pli pair<ll, int>
typedef long long ll;

const int maxn = 2010;
const ll INF = 1e15;
vector<pair<int, int> > adj[maxn] = {};
int m, A, B;
vector<ll> dis(maxn, INF);

void djs(int s) {
	bool seen[maxn] = {};
	dis[s] = 0;
	priority_queue<pli, vector<pli>, greater<pli> > q;
	q.push({0, s});

	while (!q.empty()) {
		auto b = q.top();
		q.pop();
		if (seen[b.sc]) continue;
		seen[b.sc] = true;

		for (auto u : adj[b.sc]) {
			if (dis[b.sc] + (ll) u.sc < dis[u.fr]) {
				dis[u.fr] = dis[b.sc] + (ll) u.sc;
				q.push({dis[u.fr], u.fr});
			}
		}
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> m >> A >> B;

	for (int i = 1; i <= m; i++) {
		int a, w, b; cin >> a >> w >> b;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}

	djs(A);

	if (dis[B] < INF) cout << "YES\n" << dis[B];
	else cout << "NO";
}
