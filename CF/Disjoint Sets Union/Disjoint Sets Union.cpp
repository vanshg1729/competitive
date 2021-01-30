// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int p[maxn] = {};
int r[maxn] = {};

int get(int a){
	return a = (a == p[a] ? a : get(p[a]));
}

void uni(int a, int b){

	a = get(a);
	b = get(b);
	if(a == b) return;
	if(r[a] == r[b]) r[a]++;
	if(r[a] > r[b]) p[b] = a;
	else p[a] = b;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int n,m; 
	cin>>n>>m;
	for(int i = 1; i <= n; i++) p[i] = i;
	
	while(m--){
		string s; int a,b;
		cin>>s>>a>>b;
		if(s == "get"){
			string ans = get(a) == get(b) ? "YES" : "NO";
			cout<<ans<<"\n";
		}
		else{
			uni(a,b);
		}
	}
}
