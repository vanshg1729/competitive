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
   // freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);

    int n ,m ; cin>>n>>m ; 
    int pro[n] = {} ; 
    vector<int> adj[n] = {} ; 
    int indeg[n] = {} ; 
    int le[n] = {} ; 
    
    for(int i = 0 ;i<n ; i++)
    {
        cin>>pro[i] ;
    }

    for(int i = 0 ; i<m ;i++)
    {
        int a, b ; cin>>a>>b ; 
        indeg[a]++ ; 
        adj[b].push_back(a) ; 
    }

    int ans = 0 ;

    queue<int> q ; 

    for(int i = 0 ; i<n ; i++)
    {
        if(indeg[i]) continue ; 

        le[i] = pro[i] ;
        q.push(i) ;  
    }

    while(!q.empty())
    {
        int b = q.front() ; q.pop() ; 
        ans = max(ans,le[b]) ; 

        for(auto u : adj[b])
        { 
            indeg[u]-- ; 
            if(!indeg[u]) q.push(u) ; 

            if(pro[u]^pro[b] == 0)
            {
                le[u] = max(le[u],le[b]) ;
                continue ;  
            }
            
            if(pro[u] == 0 and pro[b] == 1 )
            {
                le[u] = max(le[u],le[b]) ; 
                continue ; 
            }

            le[u] = max(le[u],le[b]+1) ; 
        }
    }

    cout<<ans ;   
}
