// https://www.codechef.com/IARCSJUD/problems/WORDLIST
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);	
    //freopen("input.txt", "r", stdin);
  	//freopen("output.txt", "w", stdout);

  	int n; cin >> n;
  	vector<char> punc = {'\'', '.', ',', ';', ':', '\n', ' '};
  	string v[n + 10] = {};

  	for(int i = 0; i <= n; i++) {
  		string s;
  		getline(cin , s);
  		s += '.';
  		v[i] = s;
  	}

  	int pos = 0;

  	set<string> ans;
  	for(int i = 1; i <= n; i++) {
  		pos = 0;
  		for(int j = 0; j < v[i].size(); j++) {
			
			char c = v[i][j];
			if(v[i][j] >= 65 and v[i][j] < 91) v[i][j] += 32;
			bool b = false;
			for(auto u : punc) {
				if(c == u) b = true;
			}

			if (b) {
				if (pos != j) {
					string s = v[i].substr(pos, j - pos);
					ans.insert(s);
				}
				pos = j + 1;
			}
  		}
  	}

  	cout << ans.size() << "\n";
  	for(auto u : ans) cout << u << "\n";


}	
