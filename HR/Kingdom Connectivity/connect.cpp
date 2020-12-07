//https://www.hackerrank.com/challenges/kingdom-connectivity/problem
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = pow(10,4)+10 ; 
ll mod = pow(10,9);

vector<int> edge[maxn] ={} , redge[maxn] = {}; 
int vis[maxn] = {} , cycle[maxn] = {} ; 
ll dp[maxn] = {} ; 
int n , m ; 

void dfs(int i )
{
    vis[i] = 1 ; 
    for(auto u : edge[i])
    {
        if(vis[u] == 0) dfs(u) ;
        if(vis[u] == 1) cycle[u] = 1 ;  
    }

    vis[i] = 2 ; 
}

void dfs2(int i )
{
    vis[i] = 1 ; 

    for(auto u : redge[i])
    {
        if(!vis[u]) dfs2(u) ;
    }
}

bool cyc()
{
    dfs(1) ;

    memset(vis,0,sizeof(vis)) ;

    dfs2(n) ;

    for(int i = 1 ; i<=n ; i++)
    {
        if(vis[i] and cycle[i]) return 1 ;
    }

    return 0 ; 
}

ll calc(int i)
{
    if(cycle[i]) return 0 ; 
    if(dp[i]!=-1) return dp[i] ;

    if(i == n) return 1 ; 

    ll ans = 0 ; 

    for(auto u : edge[i])
    {
        ans = (ans+calc(u))%mod ;
    }

    dp[i] = ans ; 

    return dp[i] ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin) ;
    //freopen("output.txt","w",stdout);

    cin>>n>>m ; 

    for(int i = 1 ; i<=m ; i++)
    {
        int b , c ; cin>>b>>c ; 

        edge[b].push_back(c) ;
        redge[c].push_back(b) ;
    }

    memset(dp,-1,sizeof(dp)) ; 

    if(cyc()) cout<<"INFINITE PATHS ";
    else cout<<calc(1) ; 


}  
