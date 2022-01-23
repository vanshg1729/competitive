// https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;
int n,q;

struct segtree{

	vector<ll> seg;
	vector<ll> mul;

	void build(int k, int l, int r){
		if(l == r){
			seg[k] = 1;
			return;
		}

		int m = (l+r)/2;
		build(2*k, l, m);
		build(2*k+1, m+1, r);
		seg[k] = seg[2*k] + seg[2*k+1];
	}

	void init(int size){
		size+=10;
		seg.assign(4*size, 0LL);
		mul.assign(4*size, 1LL);
		build(1, 0, n-1);
	}

	ll operation(ll a, ll b){
		return (a*b % mod);
	}

	void multiply(int k, int l, int r, int st, int en, int val){

		if(st > en) return;
		if(st == l and en == r){
			mul[k] = operation(mul[k],val);
			seg[k] = operation(seg[k],val);
			return;
		}

		int m = (l + r)/2;
		multiply(2*k, l, m, st, min(en,m), val);
		multiply(2*k+1, m+1, r, max(st,m+1), en, val);
		seg[k] = mul[k]*(seg[2*k] + seg[2*k+1]);
		seg[k] %= mod;
	}

	void multiply(int st, int en, int val){
		multiply(1, 0, n-1, st, en, val);
	}


	ll get_sum(int k, int l, int r, int st, int en){

		if(st > en) return 0LL;
		if(st == l and en == r){
			return seg[k];
		}

		int m = (l + r)/2;
		ll right = get_sum(2*k, l, m, st, min(en,m));
		ll left = get_sum(2*k+1, m+1, r, max(st,m+1), en);
		
		return ( ((right + left) % mod)*mul[k] % mod);
	}

	ll get_sum(int st, int en){
		return get_sum(1, 0, n-1, st, en);
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
			st.multiply(l, r-1, v);
		}
		else{

			int l,r;
			cin>>l>>r;
			cout<<st.get_sum(l, r-1)<<"\n";
		}
	}
}
