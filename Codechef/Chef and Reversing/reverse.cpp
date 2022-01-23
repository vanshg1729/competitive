#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define ll long long
#define pii pair<int,int>

const int maxn = pow(10,5)+10;
vector<pii> adj[maxn] = {};
int dis[maxn] = {},n,m;
bool seen[maxn] = {};

void djs(int s){

	memset(dis,-1,sizeof(dis));
	priority_queue<pii,vector<pii>, greater<pii> > q;
	q.push({0,s});
	dis[s] = 0;

	while(!q.empty()){

		auto b = q.top();
		q.pop();
		if(seen[b.sc]) continue;
		seen[b.sc] = 1;

		for(auto u : adj[b.sc]){

			if(seen[u.fr]) continue;
			int d = b.fr + u.sc;

			if(d < dis[u.fr] or dis[u.fr] == -1){
				dis[u.fr] = d;
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

	cin>>n>>m;

	for(int i = 1; i <= m; i++){

		int a,b; cin>>a>>b;

		adj[a].push_back({b,0});
		if(a != b) adj[b].push_back({a,1});
	}

	djs(1);
	cout<<dis[n];
}
