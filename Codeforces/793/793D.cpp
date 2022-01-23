#include <bits/stdc++.h>
using namespace std ;
#define ll long long 
#define fr first
#define sc second  

const int maxn = 90 ;
ll INF = INT_MAX ;
vector<pair<int,ll> > adj[maxn] = {} ; 
ll dp[maxn][maxn][maxn] = {} ; 
int n , m , k ; 

ll f(int i , int j , int num)
{
    if(num < 0) return INF ; 
    if(dp[i][j][num]!=-1) return dp[i][j][num] ;

    if(i == j)
    {
        if(num) dp[i][j][num] = INF ;
        else dp[i][j][num] = 0 ;

        return dp[i][j][num] ;
    }

    ll ans = INF ;
    if(i > j)
    {
        ans = min(ans, f(i,j+1,num)) ;

        for(auto u : adj[i])
        {
            if(u.fr < j or u.fr >i) continue ;

            ans = min(ans , (ll)u.sc + min(f(u.fr,j,num-1),f(u.fr , i-1,num-1) )) ;
        }
    }
    else
    {
        ans = min(ans , f(i,j-1,num)) ;

        for(auto u : adj[i])
        {
            if(u.fr > j or u.fr < i) continue ;

            ans = min(ans , (ll)u.sc + min(f(u.fr , i+1,num-1) , f(u.fr ,j ,num-1) ) ) ; 
        }
    }

    dp[i][j][num] = ans ;
    return ans ;

}

int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;
    cout.tie(0) ;
    //freopen("input.txt","r",stdin) ;
    //freopen("output.txt","w",stdout) ;

    cin>>n>>k>>m ; 

    for(int i = 1 ; i<=m ; i++)
    {
        int a , b ; ll c ; cin>>a>>b>>c ; 

        adj[a].push_back({b,c}) ;
    }

    memset(dp,-1,sizeof(dp)) ;

    ll ans = INF ;

    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            ans = min(ans , f(i,j,k-1)) ;
        }
    }

    if(ans == INF) cout<<-1 ;
    else cout<<ans ;
}
