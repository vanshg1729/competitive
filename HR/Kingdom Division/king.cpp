#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = pow(10,5) + 10 ; 
ll mod = pow(10,9) + 7 ; 
ll dp[maxn][2][2] = {} ; 
vector<int> a[maxn] = {} ;
int n ; 

ll f(int i , int b , int c , int p)
{

    if(dp[i][b][c] != -1) return dp[i][b][c] ;
    dp[i][b][c] = 0 ;

    if(!a[i].size()) return 0 ;

    if(a[i].size() == 1 and i!=1)
    {
        if(b == c) dp[i][b][c] = 1 ;
        return dp[i][b][c] ;
    }

    if(b == c)
    {
        ll ans = 1 ;
        for(auto u : a[i])
        {
            if(u != p)
            {
                ans*= (f(u,0,b,i) + f(u,1,b,i) ) ;
                ans%=mod ;
            }
        }

        dp[i][b][c] = ans ;
    }
    else
    {
        ll tot = 1 ;
        ll ans = 1 ;

        for(auto u : a[i])
        {
            if( u!=p )
            {
                tot*= (f(u,0,b,i) + f(u,1,b,i) ) ;
                ans*= f(u,c,b,i) ; 
                tot%=mod ; ans%=mod ;
            }
        }

        dp[i][b][c] = (tot - ans + mod)%mod ;
    }

    return dp[i][b][c] ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin) ;
    //freopen("output.txt","w",stdout);

    cin>>n ; 

    for(int i = 1 ; i<n ;i++)
    {
        int b, c ; cin>>b>>c ;
        a[b].push_back(c) ;
        a[c].push_back(b) ;
    }

    memset(dp,-1,sizeof(dp)) ;

   ll ans =  f(1,0,1,0) + f(1,1,0,0) ;

   cout<<ans%mod ;
}  
