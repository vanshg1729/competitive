//https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = pow(10,5) + 10;
vector<int> v = {};
int n,q;

struct segtree{

	struct node{
		int freq[50] = {};
		ll inv = 0;

		void combine(node & l, node & r){

			inv = l.inv + r.inv;
			for(int i = 40; i >= 1; i--){
				for(int j = 1; j < i; j++){
					inv += 1LL * l.freq[i]* r.freq[j];
				}
				freq[i] = l.freq[i] + r.freq[i];
			}
		}
	};

	node seg[4*maxn] = {};

	void build(int k, int l, int r){

		if(l == r){
			seg[k].freq[v[l]] = 1LL;
			return;
		}

		int m = (l + r)/2;
		build(2*k, l, m);
		build(2*k+1, m+1, r);
		seg[k].combine(seg[2*k],seg[2*k+1]);
	}

	void build(){
		build(1,1,n);
	}

	void update(int k, int l, int r, int pos, int num){

		if(l == r){
			memset(seg[k].freq,0,sizeof(seg[k].freq));
			seg[k].freq[num] = 1LL;
			return;
		}

		int m = (l+r)/2;

		if(pos <= m) update(2*k, l, m, pos, num);
		else update(2*k+1, m+1, r, pos, num);

		seg[k].combine(seg[2*k],seg[2*k+1]);
	}

	void update(int pos, int num){
		update(1, 1, n, pos, num);
	}

	node count_inv(int k, int l, int r, int st, int en){

		if(st > en) return node();
		if(l == st and r == en) return seg[k];

		int m = (l+r)/2;

		node result;
		node a = count_inv(2*k, l, m, st, min(en,m));
		node b = count_inv(2*k+1, m+1, r, max(m+1,st),en); 

		result.combine(a,b);
		return result;
	}

	ll count_inv(int st, int en){
		return count_inv(1, 1, n, st, en).inv;
	}
};

segtree st;
int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n>>q;

	v.push_back(0);
	for(int i = 1; i <= n; i++){
		int a; cin>>a;
		v.push_back(a);
	}

	st.build();
	while(q--){

		int type; cin>>type;
		
		if(type == 1){
			int l,r; cin>>l>>r;
			cout<<st.count_inv(l,r)<<"\n";
		}
		else{
			int pos,num; cin>>pos>>num;
			st.update(pos,num);
		}	
	}
}
