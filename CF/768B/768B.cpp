#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

ll siz(ll n)
{
    ll ans = 1 ; 
    while(n>1)
    {
        n/=2 ; 
        ans*=2 ; 
    }

    return ans ; 
}

ll f(ll i , ll siz , ll n)
{
    if(n<2) return n ;

    if(siz+1 == 2*i) return n%2 ; 

    n/=2  ; siz/=2 ; 

    if(siz+1 < i)
    {
        i -= (siz+1) ; 
    }

    return f(i,siz,n) ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);

    ll n, l ,r ; cin>>n>>l>>r ;

    ll x = siz(n) ; x = 2*x -1 ; 
    ll ans = 0 ; 

    for(ll i = l ; i<=r ; i++) ans+=f(i,x,n) ; 

    cout<<ans;  
}
