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
    for(int i = 1 ; i<=m ; i++)
    {
        int a,b ; cin>>a>>b ; 
        indeg[b]++ ;
        adj[a].push_back(b)  ;
    }

    if(indeg[1]!=0)
    {
        cout<<"IMPOSSIBLE" ;
        return 0 ; 
    }

    int dis[n+1] = {} ; 
    int par[n+1] = {} ; 
    bool seen[n+1] = {} ; 
    queue<int> q ;

    for(int i = 1 ; i<=n;i++)
    {
        if(indeg[i]== 0 )
        {
            q.push(i) ;
        }
    }
    
    seen[1] = true ; 

    while(!q.empty() )
    {
        int b = q.front() ; q.pop() ;

        for(auto u : adj[b])
        {
            indeg[u]-- ;
            if(indeg[u] == 0) q.push(u) ;

            if(!seen[b]) continue ;

            seen[u] = true ; 
            if(dis[b]+1>dis[u])
            {
                dis[u] = dis[b]+1 ;
                par[u] = b;
            }
        }
    }

    if(!seen[n])
    {
        cout<<"IMPOSSIBLE" ;
        return 0 ;
    }

    vector<int> top = {} ;
    int i = n ;
    while(par[i]!=0)
    {
        top.push_back(i) ;
        i = par[i] ;
    }
    
    top.push_back(1) ; 
    cout<<top.size()<<"\n" ;

    for(int i = top.size()-1 ;i>=0 ; i--)
    {
        cout<<top[i]<<" " ;
    } 
}
