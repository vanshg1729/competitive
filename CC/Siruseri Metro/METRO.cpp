// https://www.codechef.com/IARCSJUD/problems/METRO
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;

struct train{
	int speed, st;
};

struct node{
	int x, y, time;
};

const int INF = INT_MAX;
const int maxn = 60;
train col[maxn] = {}, row[maxn] = {};
int n, m;

bool cmp (node& a, node& b) {
	if (a.time == b.time) return false;
	else return a.time > b.time;
}

pair<int, int> Edge_Row(node& st) {
	int i = st.x, j = st.y;
	int speed = row[i].speed, cur_time = st.time;

	int d = speed * (m - 1), k = (cur_time - row[i].st)/d;
	int a = row[i].st + k * d;
	int left = 0, right = 0;

	if (k % 2 == 0 and a + speed * (j - 1) < cur_time) {
		a += d; k++;
	}
	else if (k % 2 == 1 and a + speed * (m - j) < cur_time) {
		a += d; k++;
	}

	if (k % 2 == 0) {
		right = a + speed * (j - 1); left = a + d + speed * (m - j);
		return {right + speed, left + speed};
	}
	right = a + d + speed * (j - 1); left = a + speed * (m - j);
	return {right + speed, left + speed};	

}

pair<int, int> Edge_col(node& st) {
	int i = st.x, j = st.y;
	int speed = col[j].speed, cur_time = st.time;

	int d = speed * (n - 1), k = (cur_time - col[j].st)/d;
	int a = col[j].st + k * d;
	int up = 0, down = 0;

	if (k % 2 == 0 and a + speed * (i - 1) < cur_time) {
		a += d; k++;
	}
	else if (k % 2 == 1 and a + speed * (n - i) < cur_time) {
		a += d; k++;
	}

	if (k % 2 == 0) {
		down = a + speed * (i - 1); up = a + d + speed * (n - i);
		return {down + speed, up + speed};
	}
	down = a + d + speed * (i - 1); up = a + speed * (n - i);
	return {down + speed, up + speed};
}

int djs(node st, pair<int, int> end) {
	vector<vector<int>> dis(n + 10, vector<int>(m + 10, INF));
	int seen[n + 10][m + 10] = {};

	priority_queue<node, vector<node>, decltype(&cmp)> q(&cmp);
	q.push(st);
	dis[st.x][st.y] = st.time;

	while (!q.empty()) {
		auto b = q.top();
		q.pop();
		//cout << b.x << " " << b.y << " " << b.time << endl;
		if (seen[b.x][b.y]) continue;
		seen[b.x][b.y] = true;
		
		vector<node> adj = {};
		auto r = Edge_Row(b);
		adj.push_back({b.x, b.y + 1, r.fr});
		adj.push_back({b.x, b.y - 1, r.sc});
		auto c = Edge_col(b);
		adj.push_back({b.x + 1, b.y, c.fr});
		adj.push_back({b.x - 1, b.y, c.sc});
		
		for (auto u : adj) {
			if (u.x > n or u.x < 1 or u.y > m or u.y < 1) continue;

			if (u.time < dis[u.x][u.y]) {
				dis[u.x][u.y] = u.time;
				q.push(u);
			}			
		}	
	}

	return dis[end.fr][end.sc];
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		char speed; int st;
		cin >> speed >> st;
		row[i].st = st;

		if (speed == 'F') row[i].speed = 1;
		else if (speed == 'O') row[i].speed = 2;
		else row[i].speed = 3;
	}

	for (int i = 1; i <= m; i++) {
		char speed; int st;
		cin >> speed >> st;
		col[i].st = st;

		if (speed == 'F') col[i].speed = 1;
		else if (speed == 'O') col[i].speed = 2;
		else col[i].speed = 3;		
	}

	node st;
	cin >> st.x >> st.y >> st.time;
	pair<int, int> end = {};
	cin >> end.fr >> end.sc;

	cout << djs(st, end);
}
