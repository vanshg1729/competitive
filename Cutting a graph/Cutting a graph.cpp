// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 50010;
struct node{
	string type;
	int a,b;
};

int n,m,k;
int par[maxn] = {},r[maxn] = {};

int get(int a){
	return a = (a == par[a] ? a : get(par[a]));
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

	cin>>n>>m>>k;
	stack<node> q = {};
	vector<string> ans = {};

	for(int i = 1; i <= m; i++){
		int a,b; cin>>a>>b;
	}

	for(int i = 1; i <= n; i++) par[i] = i;

	while(k--){
		string type;
		int a,b;
		cin>>type>>a>>b;

		q.push({type, a, b});
	}

	while(!q.empty()){
		auto cur = q.top();
		q.pop();

		if(cur.type == "ask"){
			
			int a = get(cur.a);
			int b = get(cur.b);
			if(a == b) ans.push_back("YES");
			else ans.push_back("NO");
		}
		else{
			uni(cur.a, cur.b);
		}
	}

	for(int i = ans.size() - 1; i >= 0; i--) cout<<ans[i]<<"\n";
}
