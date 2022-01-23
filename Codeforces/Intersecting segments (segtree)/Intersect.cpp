// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/D
#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10,5) + 10;
int n;

struct segtree{
	
	int seg[8*maxn] = {};

	void set(int k, int l, int r, int pos, int num){
		if(l == r){
			seg[k] = num;
			return;
		}

		int m = (l+r)/2;
		if(pos <= m) set(2*k, l, m, pos, num);
		else set(2*k+1, m+1, r, pos, num);
		seg[k] = seg[2*k] + seg[2*k+1];
	}

	void set(int pos,int num){
		set(1, 1, 2*n, pos, num);
	}

	int sum(int k, int tl, int tr, int l, int r){
		
		if(l > r) return 0;
		if(tl == l and tr == r){
			return seg[k];
		}

		int m = (tl+tr)/2;
		return sum(2*k, tl, m, l, min(r,m)) +
			   sum(2*k+1, m+1, tr, max(m+1,l), r);
	}

	int sum(int l, int r){
		return sum(1, 1, 2*n, l, r);
	}
};

segtree st;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n;

	int seen[n+10] = {};

	for(int i = 1; i <= 2*n; i++){
		int a; cin>>a;

		if(seen[a]){
			int b = seen[a];
			seen[a] = st.sum(seen[a],i) - 1;
			st.set(i,1);
			st.set(b,-1);
		}
		else{
			seen[a] = i;
			st.set(i,1);
		}
	}

	for(int i = 1; i <= n; i++) cout<<seen[i]<<" ";
}
