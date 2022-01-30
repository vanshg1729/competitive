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
		int n; cin >> n;
		string s; cin >> s;
		if (n == 1){
			cout << "YES\n";
			continue;
		}

		if (n == 2){
			if (s[0] == s[1])
				cout << "NO\n";
			else
				cout << "YES\n";
			continue;
		}

		cout << "NO\n";
	}
}
