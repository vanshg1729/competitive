// https://www.codechef.com/IARCSJUD/problems/MINTURN
#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;

struct vertex {
	char col[4];

	void build(char a, char b, char c, char d) {
		col[0] = a; col[1] = b;
		col[2] = c; col[3] = d;
	}

	int weight(int pos, char c) {
		int ans = 0;
		if (col[pos] == c) return ans;

		for (int i = 1; i < 4; i++) {
			pos = (pos + 3) % 4;
			ans++;
			if (col[pos] == c) return ans;
		}

		return ans;
	}
};

struct edge {
	int len, x, y;
};

bool cmp(edge& a, edge& b) {
	if (a.len == b.len) return false;
	return a.len > b.len;
}

int n, m;
const int maxn = 1010;
const int INF = INT_MAX;
vertex node[maxn][maxn] = {};
vector<pair<int, int> > moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void djs(pair<int, int> st) {

	vector<vector<int> > dis(maxn, vector<int>(maxn, INF));
	int seen[maxn][maxn] = {};

	priority_queue<edge, vector<edge>, decltype(&cmp)> q(&cmp);

	q.push({0, st.fr, st.sc});
	dis[st.fr][st.sc] = 0;

	while (!q.empty()) {
		auto b = q.top();
		q.pop();
		if (seen[b.x][b.y]) continue;
		//cout << b.x << " " << b.y << " " << b.len << "\n";
		seen[b.x][b.y] = true;
		vertex v = node[b.x][b.y];

		for (auto u : moves) {
			int x = b.x + u.fr;
			int y = b.y + u.sc;

			if (x < 1 or x > n) continue;
			if (y < 1 or y > m) continue;

			int d = 0;
			if (x == b.x and y > b.y) d = v.weight(1, node[x][y].col[3]);
			else if (x == b.x and y < b.y) d = v.weight(3, node[x][y].col[1]);
			else if (y == b.y and x > b.x) d = v.weight(2, node[x][y].col[0]);
			else d = v.weight(0, node[x][y].col[2]);

			if (b.len + d < dis[x][y]) {
				dis[x][y] = b.len + d;
				q.push({dis[x][y], x, y});
			}
		}	
	}

	cout << dis[n][m];
} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char a, b, c, d; cin >> a >> b >> c >> d;
			node[i][j].build(a, b, c, d);			
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << "{" << i << "," << j << "}" << ": ";
			for (auto u : node[i][j].col) {
				cout << u << " ";
			}
			cout << "\n";
		}
	}*/

	djs({1, 1});
}
