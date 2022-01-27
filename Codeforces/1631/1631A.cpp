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
		int a[n + 10] = {};
		int b[n + 10] = {};

		for (int i = 0; i < n; i++){
			cin >> a[i];
		}

		for (int i = 0; i < n; i++){
			cin >> b[i];
		}

		for (int i = 0; i < n; i++){
			if (b[i] < a[i]) swap(a[i], b[i]);
		}

		sort(a, a + n);
		sort(b, b + n);

		long long ans = a[n - 1] * b[n - 1];
		cout << ans << "\n";
	}

}
