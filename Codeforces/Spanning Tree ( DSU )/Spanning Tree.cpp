// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2*(1e5) + 10;
int par[maxn] = {}, r[maxn] = {};
int n,m;

struct edge{
	int st,en;
	ll we;
};

bool comp(edge a, edge b){
	 return a.we <= b.we;
}

int get(int a){
	return par[a] = (par[a] == a ? a : get(par[a]));
}

void uni(int a, int b){

	a = get(a);
	b = get(b);
	if(r[a] == r[b]) r[a]++;
	if(r[a] > r[b]) par[b] = a;
	else par[a] = b;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n>>m;
	vector<edge> mat = {};

	for(int i = 1; i <= n; i++) par[i] = i;

	for(int i = 1; i <= m; i++){
		int st, en;
		ll we;
		cin>>st>>en>>we;
		mat.push_back( {st, en, we} );
	}

	sort(mat.begin(), mat.end(), comp);
	ll ans = 0;

	for(auto u : mat){

		int x = get(u.st);
		int y = get(u.en);
		if(x == y) continue;
		uni(x,y);
		ans += u.we;
	}

	cout<<ans;
}
