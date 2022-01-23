// https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = pow(10,5) + 10;
int n,q;

struct segtree{

	struct node{
		ll oper,val;
	};

	node seg[4*maxn] = {};

	const ll no_op = 1e15;

	void propogate(int k, int l, int r){

		if(l == r or seg[k].oper == no_op) return;

		int m = (l + r)/2;

		seg[2*k].oper = seg[2*k + 1].oper = seg[k].oper;
		seg[2*k].val = seg[k].oper*((ll) m - l + 1);
		seg[2*k + 1].val = seg[k].oper*((ll) r - m);

		seg[k].oper = no_op;
	}

	void assign(int k, int l, int r, int st, int en, ll v){

		if(st > en) return;
		propogate(k, l, r);

		if(l == st and r == en){

			ll len = r - l + 1;
			seg[k].oper = v;
			seg[k].val = v*len;
			return;
		}

		int m = (l + r)/2;
		assign(2*k, l, m, st, min(en,m), v);
		assign(2*k + 1, m + 1, r, max(st, m + 1), en, v);
		seg[k].val = seg[2*k].val + seg[2*k + 1].val;
	}

	void assign(int st, int en, ll v){
		assign(1, 0, n - 1, st, en, v);
	}

	void add(int k, int l, int r, int st, int en, ll v){

		if(st > en) return;

		if(seg[k].oper != no_op){
			if(l == st and r == en){
				
				ll len = r - l + 1;
				seg[k].oper += v;
				seg[k].val += v*len;
				return;
			}
		}

		propogate(k, l, r);

		int m = (l + r)/2;
		add(2*k, l, m, st, min(en, m), v);
		add(2*k + 1, m + 1, r, max(st, m + 1), en, v);
		seg[k].val = seg[2*k].val + seg[2*k + 1].val;
		return;
	}

	void add(int st, int en, ll v){
		add(1, 0 , n - 1, st, en, v);
	}

	ll get(int k, int l, int r, int st, int en){

		if(st > en) return 0;
		propogate(k, l, r);
		if(l == st and r == en) return seg[k].val;

		int m = (l + r)/2;
		ll left = get(2*k, l, m, st, min(en, m));
		ll right = get(2*k + 1, m + 1, r, max(st, m + 1), en);
		return left + right;
	}

	ll get(int st, int en){
		return get(1, 0, n - 1, st, en);
	}
};

segtree st;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n>>q;

	while(q--){

		int type; cin>>type;

		if(type == 1){
			int l,r,v; cin>>l>>r>>v;
			st.assign(l, r - 1, v);
		}
		else if(type == 2){
			int l,r,v; cin>>l>>r>>v;
			st.add(l, r - 1, v);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<st.get(l, r - 1)<<"\n";
		}
	}

}
