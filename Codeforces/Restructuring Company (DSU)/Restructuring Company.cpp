// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2*(1e5) + 10;
int n, q;
int par[maxn] = {}, nxt[maxn] = {};
int r[maxn] = {};

int get(int a) {
	return par[a] = (a == par[a] ? a : get(par[a]));
}

int get_nxt(int a) {
	return nxt[a] = (a == nxt[a] ? a : get_nxt(nxt[a]));
}

void uni(int a, int b) {
	a = get(a);
	b = get(b);
	if(a == b) return;
	if(r[a] == r[b]) ++r[a];
	if(r[a] > r[b]) par[b] = a;
	else par[a] = b;
}

void nxt_uni(int a, int b) {
	nxt[a] = get_nxt(b);
}


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin >> n >> q;

	for(int i = 1; i <= n; ++i) {
		par[i] = i;
		nxt[i] = i;
	}

	while(q--) {
		int type, x, y;
		cin >> type >> x >> y;

		if (type == 1) {
			uni(x, y);
		} 
		else if (type == 2) {
			x = get_nxt(x);
			while (x < y) {
				uni(x, x + 1);
				nxt_uni(x , x + 1);
				x = nxt[x];
			}
		}
		else {
			cout << (get(x) == get(y) ? "YES" : "NO") << "\n";
		}

	}

}
