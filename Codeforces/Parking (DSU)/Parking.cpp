// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3*(1e5) + 10;
int par[maxn] = {};
int n;

int get(int a){
	return par[a] = (a == par[a] ? a : get(par[a]));
}

void uni(int a, int b){
	par[a] = get(b);
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n;
	for(int i = 1; i <= n; i++) par[i] = i;

	int q = n;
	while(q--){

		int a;
		cin>>a;
		cout<<get(a - 1) + 1<<" ";
		if(q > 0) uni(par[a - 1], (par[a - 1] + 1) % n);
	}
}
