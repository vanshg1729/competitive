/* https://codeforces.com/contest/1629/problem/A */
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
		int n, k; cin >> n >> k;

		pair<int, int > arr[n + 10] = {};
		for (int i = 0; i < n; i++){
			cin >> arr[i].fr;
		}

		for (int i = 0; i < n; i++) cin >> arr[i].sc;

		sort(arr, arr + n);

		for (int i = 0; i < n; i++){
			if (arr[i].fr > k) break;
			k += arr[i].sc;
		}

		cout << k << "\n";
	}
}
