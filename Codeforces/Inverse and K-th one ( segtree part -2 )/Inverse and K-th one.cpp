// https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,q;

struct segtree{

	vector<int> val = {},oper = {};

	const int no_op = 0;

	void init(int size){
		size += 10;
		val.assign(4*size, 0);
		oper.assign(4*size, no_op);

	}

	int val_op(int a, int b, int len){
		if(b == no_op) return a;
		return len - a;
	}

	void apply_op(int & a, int b, int len){
		a = val_op(a, b, len);
	}

	void propogate(int k, int l, int r){

		if(l == r) return;
		int m = (l + r)/2;

		apply_op(val[2*k], oper[k], m + 1 -l);
		apply_op(val[2*k + 1], oper[k], r - m);
		oper[2*k] ^= oper[k];
		oper[2*k + 1] ^= oper[k];
		oper[k] = no_op;
	}

	void modify(int k, int l, int r, int st, int en){

		if(st > en) return;
		propogate(k, l, r);

		if(l == st and r == en){
			oper[k] ^= 1;
			apply_op(val[k], 1, r - l + 1);
			return;
		}

		int m = (l + r)/2;

		modify(2*k, l, m, st, min(en, m));
		modify(2*k + 1, m + 1, r, max(st, m + 1), en);

		val[k] = val[2*k] + val[2*k + 1];
	}

	void modify(int st, int en){
		modify(1, 0, n-1, st, en);
	}

	int get(int k, int l, int r, int num){

		propogate(k, l, r);
		if(l == r){
			return l;
		}

		int m = (l + r)/2;
		if(num <= val[2*k]) return get(2*k, l, m, num);
		else return get(2*k + 1, m + 1, r, num - val[2*k]);
	}

	int get(int num){
		return get(1, 0, n-1, num);
	}
};

segtree st;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	st.init(n);

	while(q--){

		int type; cin >> type;

		if(type == 1){

			int l,r; cin >> l >> r;
			st.modify(l, r - 1);
		}
		else{

			int num; cin>>num;
			cout << st.get(num + 1) << "\n";
		}
	}
}
