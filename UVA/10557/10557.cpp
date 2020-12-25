#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define fr first 
#define sc second

const int INF = INT_MAX;
const int maxn = pow(10,5) + 10;
vector<int> adj[maxn] = {};
int energy[maxn] = {},par[maxn] = {};
int n, seen[maxn] = {};
vector<int> dis(maxn,0) ;

void dfs(int s){
	seen[s] = true;

	for(auto u : adj[s]){
		if(seen[u] == 0) dfs(u); 
	}
}

bool solve(){

	memset(seen,0,sizeof(seen));
	memset(par,-1,sizeof(par));
	dis.assign(maxn,INF);
	dis[1] = -100;
	int x = -1;

	for(int i = 1; i <= n; i++){
		x = -1;
		for(int j = 1; j <= n; j++){
			if(dis[j] == INF) continue;

			for(auto u : adj[j]){
				if(dis[j] + energy[u] >= 0) continue;

				if(dis[j] + energy[u] < dis[u]){
					dis[u] = dis[j] + energy[u];
					x = u;
					par[u] = j;
				}
			}
		}
	}

	if(dis[n] < 0) return true;
	if(x == -1) return false;

	for(int i = 1; i <= n; i++) x = par[x];
	dfs(x);
	if(seen[n]) return true;
	return false;
}


int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	while(cin>>n){
		if(n == -1) break;

		for(int i = 1; i <= n; i++) adj[i].clear();
		for(int i = 1; i <= n; i++){

			cin>>energy[i];
			energy[i]*=-1;

			int siz ; cin>>siz;
			for(int j = 1; j <= siz; j++){
				int a; cin>>a; 
				adj[i].push_back(a);
			}
		}

		if(solve()) cout<<"winnable"<<"\n";
		else cout<<"hopeless"<<"\n";
	}
}
