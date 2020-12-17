#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define ll long long

const int maxn = pow(10,5)+10;
vector<pair<int,int>> adj[maxn] = {};
int tr[maxn] = {};
ll dis[maxn] = {};
bool seen[maxn] = {};
int p[maxn] = {};
int n,m,k;

void djs(int s){

	memset(dis,-1,sizeof(dis));
	set<tuple<ll,int,int>> q;
	dis[s] = 0;
	q.insert({0,s,0});

	for(int i = 2; i <= n; i++){

		if(tr[i]){

			p[i] = 1;
			dis[i] = tr[i];
			q.insert({(ll)tr[i],i,1});
		}
	}

	while(!q.empty()){

		auto a = q.begin();
		auto b = *a;
		q.erase(b);
		int route = get<2>(b) , node = get<1>(b);
		ll d = get<0>(b);

		if(seen[node]) continue;
		seen[node] = 1;
		if(route and d == tr[node] and p[node] == 1){
			k--;
		}

		for(auto u : adj[node]){

			ll len = d + (ll)u.sc;

			if(len <= dis[u.fr] or dis[u.fr] == -1){

				if(route) p[u.fr] = node;
				dis[u.fr] = len;
				q.insert({len,u.fr,route});
			}
		}
	}
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n>>m>>k;

	for(int i = 1; i <= m; i++){

		int a,b,c;
		cin>>a>>b>>c;

		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}

	for(int i = 1; i <= k; i++){

		int a,b; cin>>a>>b;
		tr[a] = (tr[a] == 0) ? b : min(tr[a],b);
	}

	djs(1);
	cout<<k;
}
