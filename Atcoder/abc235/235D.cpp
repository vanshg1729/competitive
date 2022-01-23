#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
#define INF 10000000

const int maxn = 1e6 + 10;
int seen[maxn] = {};
int dis[maxn] = {};

int left_shift(int n){
	if (n < 10) return -1;
	int len1 = 0;
	int k = n;
	int q = 1;

	while (k){
		k /= 10;
		len1++; q *= 10;
	}

	q /= 10;
	int rem = n % q;
	int last_digit = n/q;
	int new_num = rem * 10 + last_digit;
	k = new_num;

	int len2 = 0;
	while (k){
		k /= 10;
		len2++;
	}

	if (len1 != len2) return -1;
	return new_num;
}


int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a, n; cin >> a >> n;

	memset(dis, -1, sizeof(dis));
	seen[n] = 1;
	dis[n] = 0;

	queue<int> q;
	q.push(n);
	while (!q.empty() and !seen[1]){
		auto b = q.front();
		q.pop();

		vector<int> v;
		if (b % a == 0) v.push_back(b/a);
		int c = left_shift(b);
		if (c != -1) v.push_back(c);

		for (auto u : v){
			if (seen[u]) continue;
			if (dis[u] == -1) dis[u] = dis[b] + 1;
			else dis[u] = min(dis[u], dis[b] + 1);
			seen[u] = 1;
			q.push(u);
		}
	}
	
	cout << dis[1];
}
