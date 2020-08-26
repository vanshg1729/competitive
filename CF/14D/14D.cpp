#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = 210;
vector<int> adj[maxn] = {};

pair<int,int> dfs(int s,bool seen[],int dis,int k)
{
	seen[s] = true;
	pair<int,int> node = {s,dis};

	for(auto u : adj[s])
	{
		if(seen[u] or u == k) continue;
		auto a = dfs(u,seen,dis+1,k);
		if(a.sc > node.sc)
		{
			node = a;
		}
	}

	return node ;
}
     
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     //freopen("input.txt","r", stdin);
     //freopen("output.txt","w",stdout);
     int n ; cin>>n;
     vector<pair<int,int> > edge = {};
     for(int i = 1;i<n;i++)
     {
     	int a,b; cin>>a>>b;
     	edge.push_back({a,b});
     	adj[a].push_back(b);
     	adj[b].push_back(a);
     }

     int ans = 0;

     for(auto u :edge)
     {
         bool seen[n+1] = {};

         auto node1 = dfs(u.fr,seen,0,u.sc);
         auto node2 = dfs(u.sc,seen,0,u.fr);

         bool vis[n+1] = {};

         auto far1 = dfs(node1.fr,vis,0,u.sc);
         auto far2 = dfs(node2.fr,vis,0,u.fr);

         ans = max(ans,far1.sc*far2.sc);
     }

     cout<<ans;
 }   
     
