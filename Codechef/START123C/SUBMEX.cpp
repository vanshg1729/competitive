/* https://www.codechef.com/START23C/problems/SUBMEX */
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
	while(T--){
		int n, k, x; cin >> n >> k >> x;
		if (x > k){
			cout << "-1\n";
			continue;
		}
		
		vector<int> v;
		for (int i = 0; i <= k; i++){
			if (i == x) continue;
			v.push_back(i);
		}

		for (int i = 0; i < n; i++){
			int j = i % k;
			cout << v[j] << " ";
		}

		cout << "\n";
	}

}
