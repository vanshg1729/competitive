#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define ll long long
#define pli pair<long long,int>

const int maxn = pow(10,5)+10;
vector<pair<int,int>> adj[maxn] = {};
ll dis[4][maxn] = {};
int test;
int n,m,S,T,V;

void djs(int s, int k){

	memset(dis[k],-1,sizeof(dis[k]));

	dis[k][s] = 0;
	priority_queue<pli,vector<pli> ,greater<pli> > q;
	q.push({0,s});

	while(!q.empty()){

		auto b = q.top();
		q.pop();

		if(b.fr != dis[k][b.sc]) continue;

		for(auto u : adj[b.sc]){

			ll d = (ll)u.sc + b.fr;

			if(d < dis[k][u.fr] or dis[k][u.fr] == -1){

				dis[k][u.fr] = d;
				q.push({d,u.fr});
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

	cin>>test;

	while(test--){

		cin>>n>>m>>S>>T>>V;
		
		for(int i = 0; i <= n; i++){

			adj[i].clear();
		}

		for(int i = 1; i <= m; i++){

			int a,b,c; cin>>a>>b>>c;

			adj[a].push_back({b,c});
			adj[b].push_back({a,c});
		}

		djs(S,1);
		djs(V,2);
		djs(T,3);

		ll ans = LLONG_MAX;

		for(int i = 1; i <= n; i++){
			ans = min(dis[1][i]+dis[2][i] + dis[3][i],ans);
		}

		cout<<ans<<"\n";
	}
}
