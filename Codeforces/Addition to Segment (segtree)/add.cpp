// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = pow(10,5) + 10;
int n , m;

struct segtree{

	ll seg[4*maxn] = {};

	void set(int k, int tl, int tr, int pos , int num){
		if(pos > tr) return;
		if(tl == tr){
			seg[k] += (ll)num;
			return;
		}

		int tm = (tl+tr)/2;
		if(pos <= tm) set(2*k, tl, tm, pos, num);
		else set(2*k+1, tm+1, tr, pos, num);

		seg[k] = seg[2*k] + seg[2*k+1];
		return;
	}

	void set(int pos, int num){
		set(1, 0, n-1, pos, num);
	}

	ll get(int k, int tl, int tr, int st, int en){

		if(st > en) return (ll)0;

		if(tl == st and tr == en){
			return seg[k];
		}

		int tm = (tl + tr)/2;
		return get(2*k, tl, tm, st, min(en,tm)) +
			   get(2*k+1, tm+1, tr, max(tm+1,st),en);
	}

	ll get(int pos){
		return get(1, 0, n-1, 0, pos);
	}
};

segtree st;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n>>m;

	while(m--){

		int type; cin>>type;

		if(type == 1){

			int l,r,v; cin>>l>>r>>v;
			st.set(l,v);
			if(r < n) st.set(r,-v);
		}
		else{
			int pos; cin>>pos;
			cout<<st.get(pos)<<"\n";
		}
	}
}
