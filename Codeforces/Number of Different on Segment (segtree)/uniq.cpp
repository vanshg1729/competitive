//https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int maxn = pow(10,5) + 10;
vector<int> v(maxn,0);
int n,q;

struct segtree{

	struct node{
		bool exis[41] = {};

		void combine(node & l, node & r){
			for(int i = 1; i <= 40; i++){
				exis[i] = l.exis[i] or r.exis[i];
			}
		}
	};

	node seg[4*maxn] = {};

	void build(int k, int l, int r){
		if(l == r){
			seg[k].exis[v[l]] = 1;
			return;
		}

		int m = (l+r)/2;
		build(2*k, l, m);
		build(2*k+1, m+1, r);
		seg[k].combine(seg[2*k],seg[2*k+1]);
	}

	void build(){
		build(1, 1, n);
	}

	void update(int k, int l, int r, int pos, int num){

		if(l == r){
			memset(seg[k].exis,0,sizeof(seg[k].exis));
			seg[k].exis[num] = 1;
			return;
		}

		int m = (l+r)/2;
		if(pos <= m) update(2*k, l, m, pos, num);
		else update(2*k+1, m+1, r, pos, num);

		seg[k].combine(seg[2*k],seg[2*k+1]);
	}

	void update(int pos, int num){
		update(1, 1, n, pos, num);
	}

	node uniq(int k, int l, int r, int st, int en){

		if(st > en) return node();
		if(l == st and r == en) return seg[k];

		int m = (l+r)/2;
		node result;
		node a = uniq(2*k, l, m, st, min(en,m));
		node b = uniq(2*k+1, m+1, r, max(st,m+1), en);
		result.combine(a,b);

		return result;
	}

	int uniq(int st, int en){
		node res = uniq(1, 1, n, st, en);

		int ans = 0;
		for(int i = 1; i <= 40; i++){
			ans += res.exis[i];
		}

		return ans;
	}
};

segtree st;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n>>q;

	for(int i = 1; i <= n; i++) cin>>v[i];

	st.build();
	
	while(q--){

		int type; cin>>type;

		if(type == 1){
			int l,r;
			cin>>l>>r;
			cout<<st.uniq(l,r)<<"\n";
		}
		else{
			int pos,num;
			cin>>pos>>num;
			st.update(pos,num);
		}
	}
}
