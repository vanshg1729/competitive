// https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,q;

struct segtree{

	struct node{

		ll pref,suff,tot,sum;
	};

	vector<node> val = {};
	vector<ll> oper = {};

	const ll no_op = 1e15;
	const node ini_val = {0,0,0,0};

	void init(int size){
		size += 10;
		val.assign(4*size, ini_val);
		oper.assign(4*size, 0);
	}

	node combine(node a, node b){

		return{
			max(max(a.pref,0LL), a.tot + b.pref),
			max(max(b.suff,0LL), b.tot + a.suff),
			a.tot + b.tot,
			max(max(a.suff + b.pref,0LL) , max(a.sum,b.sum))
		};
	}

	node val_op(node a, ll b, ll len){

		if(b == no_op) return a;
		ll c = b*len;
		return {max(0LL,c),max(0LL,c),c,max(0LL,c)};
	}

	void apply_op(node & a, ll b, ll len){

		a = val_op(a, b, len);
	}

	ll val_op(ll a, ll b){
		if(b == no_op) return a;
		return b;
	}

	void apply_op(ll & a, ll b){
		a = val_op(a, b);
	}

	void propogate(int k, int l, int r){

		if(l == r or oper[k] == no_op) return;
		int m = (l + r)/2;
		ll len1 = m + 1 -l;
		ll len2 = r - m; 

		apply_op(val[2*k], oper[k], len1);
		apply_op(val[2*k +1], oper[k], len2);
		apply_op(oper[2*k], oper[k]);
		apply_op(oper[2*k + 1], oper[k]);

		oper[k] = no_op;
	}	

	void modify(int k, int l, int r, int st, int en, ll v){

		if(st > en) return;

		propogate(k, l, r);
		if(l == st and r == en){

			ll len = r-l + 1;
			apply_op(val[k], v, len);
			apply_op(oper[k], v);
			return;
		}

		int m = (l + r)/2;

		modify(2*k, l, m, st, min(en, m), v);
		modify(2*k + 1, m+1, r, max(st, m+1), en, v);

		val[k] = combine(val[2*k], val[2*k +1]);
	}

	void modify(int st, int en, ll v){
		modify(1, 0, n-1, st, en, v);
	}
};

segtree st;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n>>q;
	st.init(n);

	while(q--){

		int l,r,v; cin>>l>>r>>v;

		st.modify(l, r-1, (ll) v);
		cout<<st.val[1].sum<<"\n";		
	}

}
