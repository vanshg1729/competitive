// https://cses.fi/problemset/task/1085/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long

const int maxn = 2e5 + 5;
int n,k;
ll hi = 0, low = 1e18;
vector<int> v = {};

bool check(ll max) {
	ll sum = 0;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (v[i] > max) return false;
		if (sum + v[i] <= max) sum += v[i];
		else {
			sum = v[i]; cnt++;
		}
	}

	return cnt <= k;
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
		hi += a;
		low = min((ll) a, low);
	}

	ll ans = 0;

	while (low <= hi) {
		ll mid = (low + hi)/2;
		if (check(mid)) {
			ans = mid;
			hi = mid - 1;
		}		
		else low = mid + 1;
	}

	cout << ans;
}
