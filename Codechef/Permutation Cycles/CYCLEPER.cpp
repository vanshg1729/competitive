// https://www.codechef.com/IARCSJUD/problems/CYCLEPER
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);	
    //freopen("input.txt", "r", stdin);
  	//freopen("output.txt", "w", stdout);

  	int n; cin >> n;
  	int child[n + 10] = {};
  	for(int i = 1; i <= n; i++) {
  		int a; cin >> a;
  		child[i] = a;
  	}

  	int cycles = 0;
  	int seen[n + 10] = {};
  	vector<int> v[n + 10] = {};
  	for(int i = 1; i <= n; i++) {
  		if(seen[i]) continue;
  		seen[i] = true;
  		cycles++;
  		v[cycles].push_back(i);
  		int j = child[i];
  		while(j != i) {
  			seen[j] = true;
  			v[cycles].push_back(j);
  			j = child[j];
  		}

  		v[cycles].push_back(i);
  	}

  	cout << cycles << "\n";
  	for(int i = 1; i <= cycles; i++) {
  		for(auto u : v[i]) cout << u << " ";
  		cout << "\n";
  	}
}	
