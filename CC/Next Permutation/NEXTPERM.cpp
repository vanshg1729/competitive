// https://www.codechef.com/IARCSJUD/problems/NEXTPERM
#include <bits/stdc++.h>
using namespace std;

int main(){

	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	while (k--) {

		int a[n + 10] = {}, max_el = 0;
		vector<int> v = {}, ans = {};

		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		for(int i = n; i >= 1; i--) {
		
			v.push_back(a[i]);
			if (a[i] < max_el) {
				max_el = a[i];
				break;
			}
			else {
				max_el = a[i];
			}
		}

		for(int i = 1; i <= n; i++) {
			if (a[i] == max_el) break;
			ans.push_back(a[i]);
		}

		ans.push_back(0);
		int idx = ans.size() - 1;

		sort(v.begin(), v.end());
		bool gone = false;

		for(int i = 0; i < v.size(); i++) {
			if (v[i] <= max_el or gone) ans.push_back(v[i]);
			if (v[i] > max_el and !gone) { 
				ans[idx] = v[i];
				gone = true;
			}  
		}

		for(int i = 0; i < n; i++) cout << ans[i] << " ";

		cout << "\n";
	}
}
