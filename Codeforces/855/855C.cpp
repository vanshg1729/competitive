#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = pow(10,5)+10 ; 
ll mod = pow(10,9)+7 ; 
ll dp[maxn][20][4] = {} ; 
vector<int> a[maxn] = {} ; 
int n,m,k,x ; 

void dfs(int i , int p)
{
    dp[i][0][0] = (ll)k-1 ;
    dp[i][0][2] = (ll)m-k ;
    dp[i][1][1] = (ll)1 ;

    vector<int> v ; 

    for(auto u : a[i])
    {
        if(u==p) continue ;

        v.push_back(u) ;
        dfs(u,i) ;
    }

    for(auto u : v)
    {
        for(int s = x ; s>=0 ;s--)
        {          
            dp[i][s][0] = dp[i][s][0]*(dp[u][0][0]+dp[u][0][2]) ;
            dp[i][s][1] = dp[i][s][1]*dp[u][0][0] ;
            dp[i][s][2] = dp[i][s][2]*(dp[u][0][0] + dp[u][0][2]) ;
            dp[i][s][0]%=mod ; 
            dp[i][s][1]%=mod ;
            dp[i][s][2]%=mod ;

            for(int j = s-1 ; j>=0 ;j--)
            {
                dp[i][s][0]+= dp[i][j][0]*(dp[u][s-j][0]+dp[u][s-j][1]+dp[u][s-j][2]) ;
                dp[i][s][0]%= mod ;

                dp[i][s][1] += dp[i][j][1]*(dp[u][s-j][0]) ;
                dp[i][s][1]%=mod ;

                dp[i][s][2] += dp[i][j][2]*(dp[u][s-j][0] + dp[u][s-j][2]) ;
                dp[i][s][2]%=mod ;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin) ;
    //freopen("output.txt","w",stdout);
    
    cin>>n>>m ; 

    for(int i = 1 ; i<n ;i++)
    {
        int b , c ; cin>>b>>c ; 

        a[b].push_back(c) ;
        a[c].push_back(b) ;
    }

    cin>>k>>x ;

    dfs(1,0) ;

    ll ans = 0 ;

    for(int i = 0 ; i<=x ;i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            ans+=dp[1][i][j] ;
            ans%=mod ;
        }
    }

    cout<<ans ;
}  
