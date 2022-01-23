#include <bits/stdc++.h>
using namespace std;
#define fr first 
#define sc second 
#define ll long long 
#define pli pair<long long,int>

const int INF = INT_MAX;
const int maxn = pow(10,5)+10;
vector<pair<int,int>> adj[maxn] = {};
vector<int> path = {};
ll dis[maxn] = {};
int p[maxn] = {}, n ,m;

void djs(int s ){

	memset(dis,-1,sizeof(dis));
	dis[s] = 0;

	priority_queue<pli,vector<pli>,greater<pli> > q;

	q.push({0,s});

	while(!q.empty()){
		auto b = q.top();
		q.pop();

		if(b.fr!=dis[b.sc]) continue;

		for(auto u : adj[b.sc]){

			ll d = (ll)u.sc + dis[b.sc];

			if(d < dis[u.fr] or dis[u.fr] == -1){
 
				dis[u.fr] = d;
				p[u.fr] = b.sc;
				q.push({dis[u.fr],u.fr});
			}
		}
	}
}

void calcp(int k){

	for(int i = k; i>0; i = p[i]){
		path.push_back(i);
	}

	reverse(path.begin(),path.end());
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n>>m;
	for(int i = 1; i <= m; i++){

		int a,b,d; cin>>a>>b>>d;
		adj[a].push_back({b,d});
		adj[b].push_back({a,d});
	}

	djs(1);

	if(dis[n]!=-1){
		calcp(n);

		for(auto u:path) cout<<u<<" ";
	}
	else{
		cout<<-1;
	}
}
