#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

ll count(ll v , ll n , ll div)
{
    ll ans = 0 ; 
    ll p = 1 ; 

    while(v>=p)
    {
        ans+= v/p ; 

        p*=div ; 
    }

    return ans < n ;
}


ll bin(ll n ,ll div )
{
    ll k = 0 ; 
    ll d = n ; 

    while(1)
    {
        if(k+d<=n and count(k+d,n,div)) k+=d ; 

        if(d == 1 ) break ; 

        d = d/2 + d%2 ;
    }

    k++ ; 
    return k ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    ll n , k ; cin>>n>>k ;

    cout<<bin(n,k) ; 
}
