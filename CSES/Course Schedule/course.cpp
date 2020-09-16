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
    int n,m ; cin>>n>>m ;
 
    vector<int> adj[n+1] = {} ; 
    int indeg[n+1] = {} ;
    
    for(int i = 0 ;i<m ;i++)
    {
        int a, b ; cin>>a>>b  ;
 
        indeg[b]++ ;
        adj[a].push_back(b) ; 
    }
 
    queue<int> q ; 
    for(int i = 1;i<=n;i++)
    {
        if(!indeg[i])
        {
            q.push(i) ;  
        }
    }
 
    vector<int> top = {} ; 
    while(!q.empty())
    {
        int b = q.front() ; q.pop() ;
        top.push_back(b) ; 
 
        for(auto u : adj[b])
        {
           indeg[u]-- ;
           if(indeg[u]==0)
           {
              q.push(u) ;
           }
        }
    }
 
    if(top.size()!=n) cout<<"IMPOSSIBLE";
    else 
    {
        for(auto u : top)
        {
            cout<<u<<" "; 
        }
    }
}
