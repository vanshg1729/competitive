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

	int n; cin >> n;
	int Q; cin >> Q;
	
	pair<int, int> arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i].fr;
		arr[i].sc = i;
	}
	
	sort(arr, arr + n);
	
	while (Q--){
		int x, k; cin >> x >> k;
		
		auto index = lower_bound(arr, arr + n, make_pair(x, 0)) - arr;
		if ((index + k - 1) < n && arr[index + k - 1].fr == x){
			cout << arr[index + k - 1].sc + 1 << "\n";
		}
		else cout << "-1\n";

		//cout << "what the f is happening here\n";
	}
	
}
