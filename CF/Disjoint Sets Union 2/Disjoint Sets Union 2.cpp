// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
#include <bits/stdc++.h>
using namespace std;

const int maxn = 3*(1e5) + 10;
int par[maxn] = {},size[maxn] = {},big[maxn] = {},small[maxn] = {};

int get(int a){
	return a = (a == par[a] ? a : get(par[a]));
}

void uni(int a, int b){

	a = get(a);
	b = get(b);

	if(a == b) return;
	if(size[a] >= size[b]){
		size[a] += size[b];
		big[a] = max(big[a],big[b]);
		par[b] = a;
		small[a] = min(small[b],small[a]);
	}
	else{
		size[b] += size[a];
		big[b] = max(big[a],big[b]);
		par[a] = b;
		small[b] = min(small[b],small[a]);
	}
}


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int n,m; 
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		par[i] = i;
		size[i] = 1;
		big[i] = i;
		small[i] = i;
	}
	
	while(m--){

		string type;
		cin>>type;

		if(type == "union"){
			int a,b;
			cin>>a>>b;
			uni(a,b);
		}
		else{
			int a;
			cin>>a;
			a = get(a);
			cout<<small[a]<<" "<<big[a]<<" "<<size[a]<<"\n";
		}
	}
}
