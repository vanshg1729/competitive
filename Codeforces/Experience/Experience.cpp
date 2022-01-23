// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2*(1e5) + 10;
ll par[maxn] = {},val[maxn] = {},r[maxn] = {}, extra[maxn] = {};
vector<ll> adj = {};

ll get_val(int a){
	return (a == par[a] ? val[a] : val[a] - extra[a] + get_val(par[a]));
}

int get(int a){
	return (a == par[a] ? a : get(par[a]));
}

void uni(int a, int b){

	a = get(a);
	b = get(b);
	if(a == b) return;
	if(r[a] == r[b]) r[a]++;
	if(r[a] > r[b]){
		par[b] = a;
		extra[b] += val[a];
	}
	else {
		par[a] = b;
		extra[a] += val[b];
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int n,m;
	cin>>n>>m;

	for(int i = 1; i <= n; i++) par[i] = i;

	while(m--){

		string s;
		cin>>s;
		if(s == "add"){

			int a; cin>>a;
			ll add; cin>>add;
			a = get(a);
			val[a] += add;
		}
		else if(s == "join"){

			int x,y; cin>>x>>y;
			uni(x,y);
		}
		else{
			int x; cin>>x;
			cout<<get_val(x)<<"\n";
		}
	}
}
