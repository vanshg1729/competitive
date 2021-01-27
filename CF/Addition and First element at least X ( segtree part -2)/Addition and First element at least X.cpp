// https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e5 + 10;
int n,q;

struct segtree{

	ll val[4*maxn] = {}, oper[4*maxn] = {};
	const ll no_op = 0;

	void apply_op(ll & a, ll b){
		a += b;
	}

	void propogate(int k, int l, int r){

		if(l == r) return;

		apply_op(val[2*k], oper[k]);
		apply_op(val[2*k + 1], oper[k]);
		apply_op(oper[2*k], oper[k]);
		apply_op(oper[2*k + 1], oper[k]);

		oper[k] = no_op;
	}

	void modify(int k, int l, int r, int st, int en, ll v){

		if(st > en) return;
		propogate(k, l, r);

		if(l == st and r == en){
			apply_op(oper[k], v);
			apply_op(val[k], v);
			return;
		}

		int m = (l + r)/2;

		modify(2*k, l, m, st, min(en, m), v);
		modify(2*k + 1, m + 1, r, max(st, m + 1), en, v);

		val[k] = max(val[2 * k], val[2 * k + 1]);
	}

	void modify(int st, int en, ll v){
		modify(1, 0, n-1, st, en, v);
	}

	ll get(int k, int l, int r, int pos, ll num){

		propogate(k, l, r);

		if(num > val[k] or pos > r) return -1LL;
		if(l == r){
			if(l >= pos and val[k] >= num) return l;
			return -1LL;
		}

		int m = (l + r)/2;
		ll ans = -1;
		if(val[2*k] >= num and m >= pos) ans = get(2*k , l, m, pos, num);
		if(val[2*k+1] >= num and ans == -1LL) ans = get(2*k + 1, m + 1, r, pos, num);
		return ans;
	}

	ll get(int pos, ll num){
		return get(1, 0, n - 1, pos, num);
	}

};

segtree st;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin >> n >> q;

	while(q--){

		int type; cin >> type;

		if(type == 1){

			int l,r,v; cin >> l >> r >> v;
			st.modify(l, r - 1, (ll) v);
		}
		else{

			int pos, num; cin >> num >> pos;
			cout<<st.get(pos, (ll) num)<<"\n";
		}
	}

}
