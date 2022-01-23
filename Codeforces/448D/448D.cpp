#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

ll count(ll n , ll m , ll v)
{
    ll ans = 0 ;  

    for(int i = 1 ; i<=n ; i++)
    {
        if(v%i == 0) 
        {
            ans += min(m,v/i -1) ;
        }
        else
        {
            ans += min(m,v/i) ;
        }
    }

    return ans ; 
}


ll bin(ll n , ll m , ll k)
{
    ll x = n*m ; 
    ll d = x , b = 0 ; 

    while(1)
    {
        if(d+b <= x and count(n,m,d+b) < k) b+=d ;

        if(d == 1) break ; 

        d = d/2 + d%2 ; 
    } 

    return b ; 
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    ll n , m , k ; cin>>n>>m>>k ; 


    cout<<bin(n,m,k);
}
