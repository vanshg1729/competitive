#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = pow(2,19) + 10 ; 
ll dp[maxn][110] = {} ; 

ll fac(int k)
{
    ll ans = 1 ;
    for(int i = 2 ;i<=k ;i++) ans*= (ll)i ;

    return ans ;
}

int count(int k)
{
    int ans = 0 ; 
    for(int i = 0 ;i<20 ;i++)
    {
        if(k & (1<<i)) ans++ ;
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

    ll n ; int m ; cin>>n>>m ; 

    int freq[10] = {} ; 
    vector<int> v ;

    ll b = n ;

    while(b)
    {
        int c = b%10 ;
        v.push_back(c) ;
        freq[c]++ ;
        if(c) dp[1<<(v.size()-1)][c%m]++ ;
        b/=10 ;
    }

    n = v.size() ;
    for(int x = 1 ; x < (1<<n) ; x++)
    {
        for(int i = 0 ;i<n ;i++)
        {
            if(x & (1<<i)) continue ; 

            for(int j = 0 ; j<m ;j++)
            {
                dp[x^(1<<i)][(10*j+v[i])%m]+= dp[x][j] ;
            }
        }
    }

    ll ans = dp[(1<<n)-1][0] ;

    for(int i = 0 ;i<10 ;i++) ans/=fac(freq[i]) ;

    cout<<ans ; 
}  
