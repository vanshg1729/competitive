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
    int outeg[n+1] = {} ; 

    for(int i = 1 ;i<=m;i++)
    {
       int a ,b ; cin>>a>>b ; 
       outeg[a]++ ; 
       adj[b].push_back(a) ; 
    }

    priority_queue<int> q ; 

    for(int i = 1; i<=n;i++)
    {
    	if(!outeg[i]) q.push(i) ;
    }

    int label[n+1] = {} ; 
    int i = n ; 
    while(!q.empty())
    {
    	int b = q.top() ; q.pop() ; 
        label[b] = i ; 
        i-- ;

    	for(auto u : adj[b])
    	{
    		outeg[u]-- ; 
    		if(!outeg[u]) q.push(u) ; 
    	}
    }
    
    for(int i = 1;i<=n;i++) cout<<label[i]<<" "; 
}
