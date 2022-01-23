/* https://codeforces.com/contest/1629/problem/D */
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
		set<string> freq, st; 
		bool awesome = false;

		for (int i = 0; i < n; i++){
			string s; cin >> s;
			if (s.size() == 1){
				awesome = true;
			}
			else if(s.size() == 2){
				freq.insert(s);
				reverse(s.begin(), s.end());
				if (freq.count(s) or st.count(s)){
					awesome = true;
				}
			}
			else{
				freq.insert(s);
				string c1 = s.substr(0, 2);
				st.insert(c1);
				reverse(s.begin(), s.end());

				if (freq.count(s) or freq.count(s.substr(0, 2))){
					awesome = true;
				}
			}
		}

			if (awesome) cout << "YES\n";
			else cout << "NO\n";
	}
}
