// https://www.codechef.com/IARCSJUD/problems/AVERAGE
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);	
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  	int n; cin >> n;
  	int a[n + 10] = {};
  	for(int i = 0; i < n; i++) cin >> a[i];

  	sort(a, a + n);

  	int ans = 0;
  	for(int i = 0; i < n; i++) {
  		int val = 2*a[i];
  		int l = 0, r = n - 1;

  		while (l < r) {
  			if (a[l] + a[r] == val) {
  				ans++;
  				break;
  			}
  			else if (a[l] + a[r] < val) l++;
  			else r--;
  		}
  	}  

  	cout << ans;
}	
