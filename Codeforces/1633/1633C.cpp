/* https://codeforces.com/contest/1633/problem/C */
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	while (T--){
		long long h[2] = {};
		long long d[2] = {};
		long long k, w, a;

		cin >> h[0] >> d[0];
		cin >> h[1] >> d[1];
		cin >> k >> w >> a;
		int pos = false;

		for (long long i = 0; i <= k; i++){
			long long j = k - i;
			long long health = h[0] + j * a;
			long long attack = d[0] + i * w;

			long long ch = h[1]/attack;
			if (h[1] % attack) ch++;
			long long monster = health/d[1];
			if (health % d[1]) monster++;

			if (ch <= monster){
				cout << "YES\n";
				pos = true;
				break;
			}
		}

		if (!pos) cout << "NO\n";
	}
}
