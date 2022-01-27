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
		int arr[n + 10] = {};
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
		}

		int size = 1;
		int j = n - 1;
		int num = arr[n];
		int ans = 0;

		while (j > 0){
			if (arr[j] == num){
				j--;
				size++;
			}
			else{
				size *= 2;
				j = n - size;
				ans++;
			}
		}

		cout << ans << "\n";
	}
}
