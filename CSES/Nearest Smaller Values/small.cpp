// https://cses.fi/problemset/task/1645/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int arr[n + 10] = {};
	for (int i = 1; i <= n; i++) cin >> arr[i];

	stack<pair<int, int> > s; s.push({arr[1],1});
	cout << 0 << " ";

	for (int i = 2; i <= n; i++) {
		while(1) {
			if (s.empty()) {cout << 0 << " "; break;}
			if (s.top().fr < arr[i]) {cout << s.top().sc << " "; break;}
			else s.pop();
		}
		s.push({arr[i], i});
	}
}
