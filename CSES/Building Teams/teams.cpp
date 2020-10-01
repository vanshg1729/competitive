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
    int n, m ; cin>>n>>m ; 
 
    vector<int> adj[n+1] = {} ; 
 
    for(int i = 1 ;i<=m ;i++)
    {
        int a,b ; cin>>a>>b ; 
        adj[a].push_back(b) ; 
        adj[b].push_back(a) ; 
    }
 
    int color[n+1] = {} ;
    bool bipap = true ;  
    memset(color,-1,sizeof(color)) ; 
 
   for(int i = 1 ; i<=n;i++)
   {
      if(color[i]!=-1) continue ; 
 
      color[i] = 0 ; 
      queue<int> q ; 
      q.push(i) ; 
      while(!q.empty())
      {
         int b = q.front() ; q.pop() ; 
 
         for(auto u : adj[b])
         {
            if(color[u]==-1)
            {
                color[u] = color[b]^1 ; 
                q.push(u) ; 
                continue ;
            }
 
            if(color[u] == color[b]) bipap = false ; 
         }
      }
   }
 
   if(!bipap) cout<<"IMPOSSIBLE" ; 
   else
   {
      for(int i = 1 ;i<=n; i++) cout<<color[i]+1<<" "; 
   }
}
