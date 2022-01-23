/* https://codeforces.com/contest/1629/problem/C */
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;

int n;
int seen[maxn] = {};

void solve(int arr[], int st, vector<pair<int, int>>& v, vector<int>& ans){
	if (st >= n) return;

	//cout << "Start : " << st << endl;
	
	int num = 0;
	memset(seen, 0, sizeof(seen));
	
	while(1){
		//printf("num, st : %d, %d ", num, st);
		auto b = lower_bound(v.begin(), v.end(), make_pair(num, st)) - v.begin();
		//cout << "b " << b << endl;
		if (b >= n or arr[v[b].sc] != num) break;

		int end = v[b].sc;
		for (;st <= end; st++) seen[arr[st]] = 1;
		st--;

		while(seen[num]) num++;
	}

	ans.push_back(num);
	solve(arr, st + 1, v, ans);
	return;
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	while (T--){
		cin >> n;
		int arr[n] = {};
		vector<pair<int, int>> v = {};
		vector<int> ans = {};

		for (int i = 0; i < n; i++){
			cin >> arr[i];
			v.push_back({arr[i], i});
		}
		
		sort(v.begin(), v.end());
		//cout << n << endl;
		solve(arr, 0, v, ans);

		cout << ans.size() << "\n";
		for (auto u : ans) cout << u << " ";
		cout << "\n";

	}

}
