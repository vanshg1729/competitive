// https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = pow(10,5) + 10;
int n,q;

struct segtree{

	ll seg[4*maxn] = {};

	void add(int k, int l, int r, int st, int en, int val){

		if(st > en) return;
		if(st == l and en == r){
			seg[k] += (ll) val;
			return;
		}

		int m = (l+r)/2;
		add(2*k, l, m, st, min(en,m),val);
		add(2*k+1, m+1, r, max(st,m+1), en, val);
	}

	void add(int st, int en, int val){
		add(1, 0, n-1, st, en, val);
	}

	ll get(int k, int l, int r, int pos){

		if(l == r) return seg[k];

		int m = (l+r)/2;
		if(pos <= m) return seg[k] + get(2*k, l, m, pos);
		else return seg[k] + get(2*k+1, m+1, r, pos);
	}

	ll get(int pos){
		return get(1, 0, n-1, pos);
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

			int l,r,v;
			cin>>l>>r>>v;

			st.add(l,r-1,v);
		}
		else{

			int pos; cin>>pos;
			cout<<st.get(pos)<<"\n";
		}
	}
}
