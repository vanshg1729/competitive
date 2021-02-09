// https://www.codechef.com/IARCSJUD/problems/DIVSEQ
#include <bits/stdc++.h>
using namespace std;

int main() {
	
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);  

  int n; cin >> n;
  int dp[n + 10] = {}, v[n + 10] = {};
  v[0] = 1;

  int ans = 0;
  for(int i = 1; i <= n; i++) {
  	cin >> v[i];

  	for(int j = 0; j < i; j++) {
  		if(v[i] % v[j] == 0) dp[i] = max(dp[i], dp[j] + 1);
  	}

  	ans = max(ans, dp[i]);
  }

  cout << ans;
}
