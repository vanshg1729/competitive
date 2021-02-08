#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(NULL);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m;

	priority_queue<int> q;
	for(int i = 1; i <= n + m; i++) {
		int a; cin >> a;
		if (a == -1) {
			cout << q.top() << endl;
			q.pop();
		}
		else {
			q.push(a);
		}
	}
}
