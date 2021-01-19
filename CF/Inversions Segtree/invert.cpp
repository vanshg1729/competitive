// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A
#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10,5) + 10;
int n;

struct segtree{

	int seg[4*maxn] = {};

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

	void build(){
		build(1, 1, n);
	}

	void set(int k, int l, int r, int pos){
		if(l == r){
			seg[k] = 0;
			return;
		}

		int m = (l+r)/2;
		if(pos <= m) set(2*k, l, m, pos);
		else set(2*k+1, m+1, r, pos);

		seg[k] = seg[2*k] + seg[2*k+1];
	}
	
	void set(int pos){
		set(1, 1, n, pos);
	}

	int find(int k, int l, int r, int num){

		if(l == r){
			return l;
		}

		int m = (l+r)/2;
		if(num <= seg[2*k+1]) return find(2*k+1, m+1, r, num);
		else return find(2*k, l, m, num - seg[2*k+1]);

	}

	int find(int num){
		return find(1, 1, n, num);
	}
};

segtree st;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n;

	st.build();
	vector<int> v(n+10,0);

	for(int i = 1; i <= n; i++) cin>>v[i];

	vector<int> per = {};

	for(int i = n; i > 0; i--){
		int a = st.find(v[i]+1);
		per.push_back(a);
		st.set(a);
	}

	for(int i = n-1; i >= 0; i--){
		cout<<per[i]<<" ";
	}
}
