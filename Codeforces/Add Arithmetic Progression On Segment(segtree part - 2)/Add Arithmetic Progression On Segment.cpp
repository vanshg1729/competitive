// https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2*pow(10,5) + 10;
int n,q;

struct segtree{

	struct node{
		ll start,d;
	};

	node seg[4*maxn] = {};

	void propogate(int k, ll l, ll r){
		if(l == r) return;
		ll m = (l + r)/2;

		seg[2*k].start += seg[k].start;
		seg[2*k + 1].start += seg[k].start + seg[k].d*(m + 1 - l);
		seg[2*k].d += seg[k].d;
		seg[2*k + 1].d += seg[k].d;

		seg[k].start = seg[k].d = 0LL;
	}

	void update(int k, ll l, ll r, ll st, ll en, ll a, ll d){

		if(st > en) return;
		propogate(k, l, r);
		if(l == st and r == en){
			seg[k].start += a;
			seg[k].d += d;
			return;
		}

		ll m = (l + r)/2;
		update(2*k, l, m, st, min(en, m), a, d);
		update(2*k + 1, m + 1, r, max(st, m + 1), en, a + (m + 1 - min(m + 1,st))*d, d);
	}

	void update(ll st, ll en, ll a, ll d){
		update(1, 1, n, st, en, a, d);
	}

	ll get(int k, ll l, ll r, ll pos){

		propogate(k, l, r);
		if(l == r) return seg[k].start;

		ll m = (l + r)/2;
		ll ans = 0;
		if(pos <= m) ans += get(2*k, l, m, pos);
		else ans += get(2*k + 1, m + 1, r, pos);

		return ans;
	}

	ll get(ll pos){
		return get(1, 1, n, pos);
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
			ll l,r,a,d;
			cin>>l>>r>>a>>d;
			st.update(l, r, a, d);
		}
		else{
			ll pos; cin>>pos;
			cout<<st.get(pos)<<"\n";
		}
	}
}
