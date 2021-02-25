// https://dmoj.ca/problem/apio08p3
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;

int type(char c) {
	if (c == 'N') return 0;
	if (c == 'A') return 1;
	if (c == 'C') return 2;
	if (c == 'G') return 3;
	return 4;
}

char get(int ty) {
	if (ty == 1) return 'A';
	if (ty == 2) return 'C';
	if (ty == 3) return 'G';
	return 'T';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll m, k, r; cin >> m >> k >> r;
    int arr[m + 10] = {};
    
    for (int i = 1; i <= m; i++) {
    	char c; cin >> c;
    	arr[i] = type(c);
    }

    ll dp[m + 10][k + 10][5] = {};
    if (arr[m]) dp[m][1][arr[m]]++;
    else for (int i = 1; i < 5; i++) dp[m][1][i]++;

    for (int j = 1; j <= k; j++) {
    	for (int i = m - 1; i > 0; i--) {
    		for (int l = 1; l < 5; l++) {
    			
    			if (arr[i] and l != arr[i]) continue;
    			ll b = 0;
    			for (int y = 1; y < 5; y++) {
    				if (y < l) b += dp[i + 1][j - 1][y];
    				else b += dp[i + 1][j][y];
    			}

    			dp[i][j][l] += b;
    		}
    	}
    }

    for (int j = 1; j <= k; j++) {
    	for (int i = 1; i <= m; i++) {
    		for (int l = 1; l < 5; l++) {
    			dp[i][j][l] += dp[i][j - 1][l];
    		}
    	}
    }

    int ans[m + 10] = {}; ans[0] = 1;

    int j = k;
    for (int i = 1; i <= m; i++) {
    	int c = ans[i - 1];
    	int d = 0;

    	for (int l = 1; l < 5; l++) {
    		if (l < c) {
    			if (dp[i][j - 1][l] >= r) {
    				d = l;
    				break;
    			}
    			else r -= dp[i][j - 1][l];
    		}
    		else {
    			if (dp[i][j][l] >= r) {
    				d = l;
    				break;
    			}
    			else r -= dp[i][j][l];
    		}
    	}

    	if (d < c) j--;
    	while (dp[i][j][d] == dp[i][j - 1][d]) j--;
    	ans[i] = d;
    }

    for (int i = 1; i <= m; i++) cout << get(ans[i]);
}
