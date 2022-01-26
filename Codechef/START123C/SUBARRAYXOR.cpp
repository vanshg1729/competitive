/* https://www.codechef.com/START23C/problems/SUBARRAYXOR */
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
		int arr[n + 1] = {};
		arr[1] = 1;
		int next = 2;

		int x = 1;
		for (int i = 2; i <= n; i++){
			arr[i] = next ^ x;
			x = next;
			next++;
		}
		
		for (int i = 1; i <= n; i++) cout << arr[i] << " ";
		cout << "\n";
	}
}
