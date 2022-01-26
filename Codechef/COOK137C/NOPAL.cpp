/* https://www.codechef.com/problems/NOPAL */
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
		for (int i = 0; i < n; i++){
			int rem = i % 3;
			char out = 'a' + rem;
			cout << out;
		}
		cout << "\n";
	}
}	
