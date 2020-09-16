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
    
    long long mod = pow(10,9)+7 ;

    int n,m ; cin>>n>>m ; 
    vector<int> adj[n+1] = {} ; 
    int indeg[n+1] = {} ; 
    for(int i = 1 ; i<=m ; i++)
    {
        int a,b ; cin>>a>>b ; 
        indeg[b]++ ;
        adj[a].push_back(b)  ;
    }
 
    long long count[n+1] = {} ; 
    bool seen[n+1] = {} ; 
    queue<int> q ;

    for(int i = 1 ; i<=n;i++)
    {
        if(indeg[i]== 0 )
        {
            q.push(i) ;
        }
    }
    
    seen[1] = true ; count[1] = 1 ; 

    while(!q.empty() )
    {
        int b = q.front() ; q.pop() ;

        for(auto u : adj[b])
        {
            indeg[u]-- ;
            if(indeg[u] == 0) q.push(u) ;

            if(!seen[b]) continue ;

            seen[u] = true ; 
            count[u]+=count[b] ;
            count[u]%=mod ;            
        }
    }

    cout<<count[n];  
}
