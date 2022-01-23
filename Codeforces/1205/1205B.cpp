#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     //freopen("input.txt","r", stdin);
     //freopen("output.txt","w",stdout);

     int n; cin>>n;
     vector<int> adj[n+74] = {};
     for(int i = 1;i<=n;i++)
     {
     	long long a ; cin>>a;
     	int b = i+64;
     	for(int j = 0;j<64;j++)
     	{
     		if(a & (ll)(pow(2,j)))
     		{
     			adj[j].push_back(b);
     			adj[b].push_back(j);
     		}
     	}
     }


     for(int i = 0;i<64;i++)
     {
     	if(adj[i].size()>2)
     	{
     		cout<<3;
     		return 0;
     	}
     }

     int ans = INT_MAX;
     set<int> s[n+1] = {};
     
     for(int i = 0;i<64;i++)
     {
          if(adj[i].size()<2) continue;

          int a = adj[i][0]; a-=64;
          int b = adj[i][1]; b-=64;

          s[a].insert(b);
          s[b].insert(a);
     }

     for(int i = 1;i<=n;i++)
     {
          for(auto j : s[i])
          {
               bool seen[n+1] = {};

               int dis[n+1] = {};

               queue<int> q; q.push(i);
               seen[i] = true;

               while(!q.empty())
               {
                    int b = q.front();
                    q.pop();

                    for(auto u : s[b])
                    {
                         if(u == j and b == i) continue;
                         if(seen[u]) continue;

                         seen[u] = true;
                         q.push(u);
                         dis[u] = dis[b]+1;
                    }
               }

               if(dis[j])
               {
                    ans = min(ans,dis[j]+1);
               }
          }
     }

     if(ans<INT_MAX)
     {
          cout<<ans;
     }
     else
     {
          cout<<-1;
     }
 }   
     
