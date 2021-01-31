#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 10;
int n,m;
int par[maxn] = {};

int get(int a){
	return par[a] = (a == par[a] ? a : get(par[a]));
}

void uni(int a, int b){
	par[a] = get(b);
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n>>m;
	for(int i = 1; i <= n + 1; i++) par[i] = i;

	while(m--){
		
		char type;
		int a;

		cin>>type>>a;
		if(type == '-') {
			uni(a, a + 1);
		}
		else {
			int ans = get(a);
			cout<<(ans > n ? -1 : ans)<<"\n";
		}
	}
}
