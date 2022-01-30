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
		int n; cin >> n;
		int seen[n] = {};
		int k = n - 1;
		int power = 0;
		while (k > 1){
			power++;
			k /= 2;
		}

		int ans = 1 << power;
		//cout << "power: " << power << endl;

		//cout << ans << " ";
		int i;
		for (i = n - 1; i >= 0; i--){
			if (i >= ans){
				cout << i << " ";
				seen[i] = 1;
			}
			else break;
		}

		i++;
		int b = i ^ ans;
		seen[b] = 1;
		cout << b << " ";
		for (int j = 0; j < n; j++){
			if (!seen[j]) cout << j << " ";
		}

		cout << "\n";

	}
}
