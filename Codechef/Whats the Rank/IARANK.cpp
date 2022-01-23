// https://www.codechef.com/IARCSJUD/problems/IARANK
#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

int main() {
	
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);  
	
  int n; cin >> n;
  vector<int> v;
  for(int i = 0; i < n; i++) {
  	int a; cin >> a;
  	v.push_back(a);
  	int pos = 1;

  	for(int j = 0; j < i; j++) {
  		if(v[j] > v[i]) pos++;
  	}

  	cout << pos << "\n";
  } 

}
