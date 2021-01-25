// https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;
int n,q;

struct segtree{

	vector<ll> val = {},oper = {};

	const ll no_oper = 1;
	const ll ini_val = 1;
	const ll no_val = 0;

	ll comb_op(ll a, ll b){
		return (a + b) % mod;
	}

	ll val_op(ll a, ll b){
		return a*b % mod;
	}

	void apply_op(ll & a, ll b){
		a = val_op(a, b);
	}

	void build(int k, int l, int r){

		if(l == r){
			val[k] = ini_val;
			return;
		}

		int m = (l + r)/2;
		build(2*k, l, m);
		build(2*k+1, m+1, r);

		val[k] = comb_op(val[2*k], val[2*k+1]);
	}

	void init(int size){
		size += 10;
		val.assign(4*size, 0);
		oper.assign(4*size, no_oper);
		build(1, 0, n-1);
	}

	void propogate(int k, int l, int r){

		if( l == r ) return;

		apply_op(val[2*k], oper[k]);
		apply_op(val[2*k +1], oper[k]);
		apply_op(oper[2*k], oper[k]);
		apply_op(oper[2*k +1], oper[k]);

		oper[k] = no_oper;
	}

	void modify(int k, int l, int r, int st, int en, int va){

		if(st > en) return;

		propogate(k, l, r);
		if(l == st and r == en){
			apply_op(val[k], (ll) va);
			apply_op(oper[k], (ll) va);
			return;
		}

		int m = (l + r)/2;
		modify(2*k, l, m, st, min(en, m), va);
		modify(2*k + 1, m+1, r, max(st, m+1), en, va);

		val[k] = comb_op(val[2*k], val[2*k + 1]);
	}

	void modify(int st, int en, int va){
		modify(1, 0, n-1, st, en, va);
	}

	ll get(int k, int l, int r, int st, int en){

		if(st > en) return no_val;

		propogate(k , l, r);
		if(l == st and r == en){
			return val[k];
		}

		int m = (l + r)/2;

		ll right = get(2*k, l, m, st, min(en,m));
		ll left = get(2*k + 1, m+1, r, max(st, m+1), en);

		return comb_op(right, left);
	}

	ll get(int st, int en){
		return get(1, 0, n-1, st, en);
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

		int type; cin>>type;

		if(type == 1){

			int l,r,v;
			cin>>l>>r>>v;
			st.modify(l, r-1, v);
		}
		else{

			int l,r;
			cin>>l>>r;
			cout<<st.get(l, r-1)<<"\n";
		}
	}
}
