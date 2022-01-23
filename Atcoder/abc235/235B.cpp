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

	int n; cin >> n;
	int a; cin >> a;
	int ans = 0;
	for (int i = 1; i < n; i++){
		int b; cin >> b;
		if (b > a){
			ans++;
			a = b;
		}
		else break;
	}

	cout << a;
}
