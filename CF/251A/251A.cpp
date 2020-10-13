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
     
    ll n , d ; cin>>n>>d ; 

    vector<ll> v = {} ;
    v.push_back(0) ;

    for(int i = 1 ;i<=n ; i++)
    {
        ll a ; cin>>a ;
        v.push_back(a) ;
    } 
    
    ll ans = 0 ;

    for(ll i = 1 ;i<=n ;i++)
    {
        ll k = 0 ; 

        ll b = n ;
        while(1)
        {
            if(k+b<=n and v[k+b]<=v[i]+d) k+=b ;

            if(b==1) break ;
            b = b/2 +b%2 ;
        }

        if(k-i<2) continue ;
        ans+= ((k-i)*(k-i-1))/2 ;
    }

    cout<<ans ; 
}
