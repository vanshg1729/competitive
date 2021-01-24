// https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = pow(10,5) + 10;
ll INF = 1e15;
int n,q;

struct segtree{

	vector<pair<ll,ll>> seg = {};

	void init(int size){
		size += 10;
		pair<ll,ll> p1 = {0,0};
		seg = vector<pair<ll,ll>>(4*size,p1);
	}

	void add(int k, int l, int r, int st, int en, int val){

		if(st > en) return;
		if(st == l and en == r){
			ll v = (ll) val;
			seg[k].fr += v;
			seg[k].sc += v;
			return;
		}

		int m = (l+r)/2;
		add(2*k, l, m, st, min(en,m), val);
		add(2*k+1, m+1, r, max(st,m+1), en, val);
		seg[k].fr = min(seg[2*k].fr, seg[2*k+1].fr) + seg[k].sc;
	}

	void add(int st, int en, int val){
		add(1, 0, n-1, st, en, val);
	}

	ll get_min(int k, int l, int r, int st, int en){

		if(st > en) return INF;
		if(l == st and r == en){
			return seg[k].fr;
		}

		int m = (l+r)/2;

		ll right = get_min(2*k, l, m, st, min(en,m));
		ll left = get_min(2*k+1, m+1, r, max(st,m+1),en);
		return seg[k].sc + min(right, left);
	}

	ll get_min(int st, int en){
		return get_min(1, 0, n-1, st, en);
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
			st.add(l, r-1, v);
		}
		else{

			int l,r;
			cin>>l>>r;
			cout<<st.get_min(l, r-1)<<"\n";
		}
	}

}
