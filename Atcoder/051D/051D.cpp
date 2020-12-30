#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc second
#define fr first

const ll INF = 1e9;
const int maxn = 310;
int dis[maxn][maxn] = {};
vector<pair<int,int>> adj[maxn] = {};
int path[maxn][maxn] = {};
int n,m; 

void solve(){

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dis[i][k] == INF or dis[k][j] == INF) continue;

				if(dis[i][k] + dis[k][j] < dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
					path[i][j] = path[i][k] + path[k][j];
				}
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

	cin>>n>>m;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dis[i][j] = INF;
		}
	}

	for(int i = 1; i <= m; i++){
		int a,b,c; cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
		dis[a][b] = min(dis[a][b],c);
		dis[b][a] = min(dis[b][a],c);
		path[a][b] = 1;
		path[b][a] = 1;
	}

	int ans = 0;
	solve();

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(path[i][j] == 1) ans++;
		}
	}

	ans/=2;

	cout<<m-ans;
}
