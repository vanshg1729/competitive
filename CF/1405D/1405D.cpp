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
    
    int t ; cin>>t ;

    while(t--)
    {
    	int n,x,y,da,db ; cin>>n>>x>>y>>da>>db ;

    	vector<int> adj[n+1] = {} ;
    	for(int i = 1; i<n; i++)
    	{
    		int a,b ; cin>>a>>b ;
    		adj[a].push_back(b) ;
    		adj[b].push_back(a) ;
    	}

    	int maxd = 0 ,maxn = 0 ; 
        bool seen[n+1] = {} , vis[n+1] = {} ; 
        int dis[n+1] = {} ; 
        
        seen[x] = true ; 
        stack<int> s ; s.push(x) ;

        while(!s.empty())
        {
        	int b = s.top() ; s.pop() ;

        	if(dis[b]> maxd )
        	{
        		maxd = dis[b] ;
        		maxn = b ;
        	}

        	for(auto u : adj[b])
        	{
        		if(seen[u]) continue ; 
        		seen[u] = true ; 
        		dis[u] = dis[b] + 1 ;
        		s.push(u) ;
        	}
        }

        if(da>= dis[y])
        {
        	cout<<"Alice"<<"\n" ;
        	continue ;
        }

        vis[maxn] = true ; dis[maxn] = 0 ;
        s.push(maxn) ;

        while(!s.empty())
        {
        	int b = s.top() ; s.pop() ;
        	maxd = max(maxd,dis[b]); 
        	for(auto u : adj[b])
        	{
        		if(vis[u]) continue ;
        		vis[u] = true ;
        		dis[u] = dis[b] + 1 ;
        		s.push(u) ;
        	}
        }

        if(2*da>=maxd)
        {
        	cout<<"Alice"<<"\n" ;
        }
        else if(db>2*da)
        {
        	cout<<"Bob"<<"\n" ;
        }
        else
        {
        	cout<<"Alice"<<"\n" ; 
        }
    }
   
}
