// https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/C
#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10,5) + 10, INF = INT_MAX;
int n,q;

struct segtree{

	int seg[4*maxn] = {};

	int operation(int a, int b){
		
		if(b == INF) return a;
		else return b;
	}

	void propogate(int k, int l, int r){
		
		if(l == r) return;
		seg[2*k] = operation(seg[2*k],seg[k]);
		seg[2*k+1] = operation(seg[2*k+1],seg[k]);
		seg[k] = INF;
	}

	void modify(int k, int l, int r, int st, int en, int val){

		if(st > en) return;
		propogate(k, l, r);

		if(l == st and r == en){
			seg[k] = val;
			return;
		}

		int m = (l+r)/2;
		modify(2*k, l, m, st, min(en,m), val);
		modify(2*k+1, m+1, r, max(st,m+1), en, val);
	}

	void modify(int st, int en, int val){
		modify(1, 0, n-1, st, en, val);
	}

	int get(int k, int l, int r, int pos){

		propogate(k, l, r);
		if(l == r) return seg[k];

		int m = (l+r)/2;
		if(pos <= m) return get(2*k, l, m, pos);
		else return get(2*k+1, m+1, r, pos);
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
			st.modify(l, r-1, v);
		}
		else{

			int pos; cin>>pos;
			cout<<st.get(pos)<<"\n";
		}
	}

}
