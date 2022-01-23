// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = pow(10,5) + 10;
int n,m;

struct segtree{

	ll seg[4*maxn] = {};
	void build(vector<ll> & a, int k, int l, int r){
		if(l == r){
			seg[k] = (l % 2) ? a[l] : -a[l];
			return;
		}

		int tm = (l+r)/2;
		build(a, 2*k, l, tm);
		build(a, 2*k+1, tm+1, r);
		seg[k] = seg[2*k] + seg[2*k+1];
	}

	void build(vector<ll> & a){
		build(a, 1, 1, n);
	}

	void set(int k, int tl, int tr, int pos, int num){
		if(tl == tr){
			seg[k] = (tl % 2) ? (ll) num : (ll) -num;
			return;
		}

		int tm = (tl + tr)/2;
		if(pos <= tm) set(2*k, tl, tm, pos, num);
		else set(2*k+1, tm+1, tr, pos, num);

		seg[k] = seg[2*k] + seg[2*k+1];
	}

	void set(int pos, int num){
		set(1, 1, n, pos, num);
	}

	ll get_sum(int k, int tl, int tr, int st , int en){

		if(st > en) return 0;
		if(tl == st and tr == en) return seg[k];

		int tm = (tl + tr)/2;
		return get_sum(2*k, tl, tm, st, min(en,tm)) +
			   get_sum(2*k+1, tm+1, tr, max(st,tm+1),en);

	}

	ll get_sum(int st, int en){
		return get_sum(1, 1, n, st, en);
	}
};

segtree st;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n;
	vector<ll> a(n+10,0);
	for(int i = 1; i <= n; i++) cin>>a[i];

	st.build(a);

	cin>>m;

	while(m--){

		int type; cin>>type;

		if(type){
			int l,r;
			cin>>l>>r;

			ll sum = st.get_sum(l,r);

			if(l % 2 == 0) sum*=-1;
			cout<<sum<<"\n"; 
		}
		else{
			int pos,num;
			cin>>pos>>num;
			st.set(pos,num);
		}
	}
}
