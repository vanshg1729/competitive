#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc second
#define fr first
struct edge
{
	int a,b;
	ll cost;
};
const ll INF = 1e16;
const int maxn = 1010;
vector<edge> e = {};
vector<ll> dis(maxn,0);
vector<ll> par(maxn,0);
int n,m;

bool solve(){

	dis.assign(maxn,INF);
	par.assign(maxn,0);
	dis[1] = 0;

	for(int i = 1; i <= n; i++){

		for(auto u : e){
			if(dis[u.a] == INF) continue;

			if(dis[u.a] + u.cost < dis[u.b]){
				dis[u.b] = max(dis[u.a] + u.cost,-INF);
				par[u.b] = u.a;
			}
		}
	}

	int a = n;
	for(int i = 1; i <= n; i++){
		a = par[a];
	}

	if(a == 0) return true;
	return false;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n>>m;

	for(int i = 1; i <=m; i++){
		int a,b; cin>>a>>b;
		ll c ; cin>>c;

		e.push_back({a,b,-c});
	}

	if(solve()) cout<<-dis[n];
	else cout<<"inf";
}
