// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/D
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second

const int maxn = 3*(1e5) + 10;
int n,q;
int par[maxn] = {}, len[maxn] = {};

pair<int,int> get(int a) {
	if(a == par[a]) return {a,0};
	auto up = get(par[a]);
	par[a] = up.fr;
	len[a] += up.sc;
	return {par[a], len[a]};
}

void uni(int a, int b) {
	par[a] = b;
	len[a] = 1;
}


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin >> n >> q;
	for(int i = 1; i <= n; ++i) par[i] = i;

	while(q--) {
		int type; cin >> type;
		if(type == 1) {
			int a,b;
			cin >> a >> b;
			uni(a, b);
		}
		else {
			int c;
			cin >> c;
			cout << get(c).sc << "\n";
		}
	} 
}
