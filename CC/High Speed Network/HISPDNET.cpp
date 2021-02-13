// https://www.codechef.com/IARCSJUD/problems/HISPDNET
#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;

const int maxn = 2010;
int n;
int par[maxn], r[maxn] = {};

struct edge {
	int a, b;
	int cost;
};

bool comp(edge& a, edge& b) {
	if (a.cost == b.cost) return false;
	return a.cost < b.cost;
}

int get(int a) {
	return par[a] = (par[a] == a ? a : get(par[a]));
}

void unite(int a, int b) {
	a = get(a);
	b = get(b);

	if (r[a] == r[b]) r[a]++;
	if (r[a] > r[b]) par[b] = a;
	else par[a] = b;
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;

	vector<edge> v = {};

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a; cin >> a;
			if (i == 1 or j == 1 or i == j) continue;
			v.push_back({i, j, a});			
		}
	}

	for (int i = 1; i <= n; i++) par[i] = i;
	sort(v.begin(), v.end(), comp);

	ll ans = 0;

	for (auto u : v) {
		//cout << u.a << " " << u.b << " " << u.cost << endl;
		if (get(u.a) == get(u.b)) continue;
		ans += u.cost;
		unite(u.a, u.b);
	}

	cout << ans;
}
