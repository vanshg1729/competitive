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
	
	int dig[3];
	for (int i = 0; i < 3; i++){
		char a; cin >> a;
		dig[i] = a - '0';
	}

	int ans = 0;
	ans += dig[0] * 100 + dig[1] * 10 + dig[2];
	ans += dig[1] * 100 + dig[2] * 10 + dig[0];
	ans += dig[2] * 100 + dig[0] * 10 + dig[1];
	cout << ans;
}
