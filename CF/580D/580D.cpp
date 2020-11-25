#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = pow(2,20) + 10 ;
ll dp[maxn][28] = {} ;

int count(int b)
{
    int ans = 0 ;
    for(int i = 0 ;i<20 ;i++)
    {
        if(b & (1<<i)) ans++ ;
    }

    return ans ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin) ;
    //freopen("output.txt","w",stdout);

    int n , m , k ; cin>>n>>m>>k ;

    ll a[n+10] = {} ;

    for(int i = 0 ;i<n ;i++) cin>>a[i] ;

    map<pair<int,int> ,ll > rule ;

    for(int i = 1 ;i<=k ; i++)
    {
        int x ,y ; ll c ; cin>>x>>y>>c ;
        x-- ; y-- ;

        rule[{x,y}] = c ;
    }

    ll ans = 0 ;
    for(int x = 1 ; x< (1<<n) ; x++)
    {
        int b = count(x) ;
        if(b > m) continue ;

        for(int i = 0 ;i<n ;i++)
        {
            if(!(x & (1<<i) )) continue ;
            if(b == 1)
            {
                dp[x][i] = a[i] ;
                if(m==1) ans = max((ll)a[i],ans) ;
                continue ;
            }

            for(int j = 0 ; j<n ;j++)
            {
                if(i == j or !(x & (1<<j) ) ) continue ;

                dp[x][i] = max(dp[x^(1<<i)][j] + a[i] + rule[{j,i}] , dp[x][i]) ;
            }

            if(b == m) ans = max(ans, (ll)dp[x][i]) ;
        }
 
    }

    cout<<ans ;
}  
