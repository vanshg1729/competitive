#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const ll maxn = 1010 ; 
ll prex[maxn] = {} , prey[maxn] = {} ;
ll n , m ; 

ll fx(ll x)
{
    ll ans = 0 ; 

    for(int i = 1 ;i<=n ; i++)
    {
        ll p = pow((4*i-2-4*x),2) ; 
        p*= prex[i] ; 
        ans += p ;  
    }

    return ans ;
}

ll fy(ll y)
{
    ll ans = 0 ; 

    for(int j = 1 ;j<=m ; j++)
    {
        ll p = pow((4*j-2-4*y),2) ;
        p*=prey[j] ;
        ans+=p ;
    }

    return ans ;
}

ll bin()
{
    ll x = 0 ;

    for(ll d = n ;d>=1 ;d/=2)
    {
        while(x+d<n and fx(x+d) > fx(x+d+1) ) x+=d ;
    }

    if(fx(x)>fx(x+1) and x+1<=n) x++ ;

    ll y = 0 ; 

    for(ll d = m ;d>=1 ;d/=2)
    {
        while(y+d<m and fy(y+d) > fy(y+d+1)) y+=d ; 
    }

    if(fy(y)>fy(y+1) and y+1<=m) y++ ;

    cout<<fx(x)+fy(y)<<"\n" ;
    cout<<x<<" "<<y<<"\n" ;

    return 0 ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);    
    
    cin>>n>>m ;

    for(int i = 1 ;i<=n ;i++)
    {
        for(int j = 1 ;j<=m ;j++) 
        {
            ll a ; 
            cin>>a ;
            prex[i]+= a;
            prey[j]+= a;
        }
    }

    bin() ;
}   
