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
    
    long long n ; cin>>n ; 
    vector<int> adj[n+1] = {} ; 

    for(int i = 1;i<n ; i++)
    {
        int a,b ; cin>>a>>b ; 
        adj[a].push_back(b) ; 
        adj[b].push_back(a) ; 
    }

    bool seen[n+1] = {} ;
    int col[n+1] ; 
    memset(col,-1,sizeof(col)) ;
    long long a[3] = {} ; 

    seen[1] = true ; 
    col[1] = 0 ;
    queue<int> q ;
    q.push(1) ; 

    while(!q.empty())
    {
        int b = q.front() ; q.pop() ; 
        a[col[b]]++ ; 

        for(auto u : adj[b])
        {
            if(seen[u]) continue ; 

            seen[u] = true ; 
            col[u] = col[b]^1 ; 
            q.push(u) ; 
        }
    }
    
    long long ans = 0 ;
    ans = a[0]*a[1] - n ; 
    ans++ ; 

    cout<<ans ;    
}
