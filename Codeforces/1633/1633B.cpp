/* https://codeforces.com/contest/1633/problem/B */
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
		string s; cin >> s;
		int one = 0, zero = 0;
		int n = s.size();
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '0') zero++;
			else one++;
		}

		if (one > zero){
			cout << zero << "\n";
		}
		else if (zero > one){
			cout << one << "\n";
		}
		else{
			if (s[n - 1] == '0') zero--;
			if (s[n - 1] == '1') one--;

			if (one > zero) cout << zero << "\n";
			else cout << one << "\n";
		}

	}
}
