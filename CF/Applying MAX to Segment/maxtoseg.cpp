#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10,5) + 10;
int n,q;

struct segtree{

	int seg[4*maxn] = {};

	void apply_operation(int & a, int b){
		a = max(a,b);
	}

	void modify(int k, int l, int r, int st, int en, int val){

		if(st > en) return;
		if(st == l and en == r){
			apply_operation(seg[k],val);			
			return;
		}

		int m = (l+r)/2;
		modify(2*k, l, m, st, min(en,m),val);
		modify(2*k+1, m+1, r, max(st,m+1), en, val);
	}

	void modify(int st, int en, int val){
		modify(1, 0, n-1, st, en, val);
	}

	int get(int k, int l, int r, int pos){

		if(l == r) return seg[k];

		int m = (l+r)/2;
		if(pos <= m) return max(seg[k], get(2*k, l, m, pos) );
		else return max( seg[k], get(2*k+1, m+1, r, pos) );
	}

	int get(int pos){
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

			st.modify(l,r-1,v);
		}
		else{

			int pos; cin>>pos;
			cout<<st.get(pos)<<"\n";
		}
	}
}
