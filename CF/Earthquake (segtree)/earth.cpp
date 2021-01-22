// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/E
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second 
#define ll long long

const int maxn = pow(10,5) + 10;
const int INF = INT_MAX;
int n,q;

struct segtree{

	vector<int> seg = vector<int>(4*maxn,INF);

	void update(int k, int l, int r, int pos, int num){

		if(l == r){
			seg[k] = num;
			return;
		}

		int m = (l+r)/2;
		if(pos <= m) update(2*k, l, m, pos, num);
		else update(2*k+1, m+1, r, pos, num);

		seg[k] = min(seg[2*k],seg[2*k+1]);
	}

	void update(int pos, int num){
		update(1, 0, n-1, pos, num);
	}

	int count(int k, int l, int r, int st, int en, int pow){

		if(st > en or seg[k] > pow) return 0;

		if(l == r){
			seg[k] = INF;
			return 1;
		}

		int m = (l+r)/2;
		int ans = count(2*k, l, m, st, min(en,m), pow) +
				count(2*k+1, m+1, r, max(st,m+1), en, pow);

		seg[k] = min(seg[2*k+1],seg[2*k]);

		return ans;
	}

	int count(int st, int en, int pow){

		return count(1, 0, n-1, st, en, pow);
	}
};

segtree st;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>q;

	while(q--){

		int type; cin>>type;

		if(type == 1){
			int pos,num; cin>>pos>>num;
			st.update(pos,num);
		}
		else{
			int l,r,pow;
			cin>>l>>r>>pow;

			cout<<st.count(l,r-1,pow)<<"\n";
		}
	}		
}

