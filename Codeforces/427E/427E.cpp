#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = pow(10,6) + 10 ; 
int n , m ; 
ll a[maxn] = {} ;

ll dis(ll x)
{
    ll ans = 0 ;
    stack<ll> r  ;
    queue<ll> l ;

    for(int i = 1 ;i<=n ;i++)
    {
        if(a[i]<x) l.push(a[i]) ;
        if(a[i]>x) r.push(a[i]) ;
    }

    while(!l.empty())
    {
        ans+= 2*(x-l.front()) ;

        for(int i = 1 ;i<=m ;i++)
        {
            if(l.empty()) break ;
            l.pop() ;
        }
    }

    while(!r.empty())
    {
        ans+= 2*(r.top()-x) ;

        for(int i = 1 ;i<=m ;i++) 
        {
            if(r.empty()) break ; 
            r.pop() ;
        }
    }

    return ans ;
}

ll bin()
{
    ll l = a[1], r = a[n] ;

    while(l<r)
    {
        if(r-l == 1) break ;
        ll m = (l+r)/2 ;
        if(dis(m)<dis(m+1)) r = m ;
        else l = m ;
    }
    
    return min(dis(l),dis(r));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);    
    
    cin>>n>>m ; 
    for(int i = 1 ;i<=n ;i++) cin>>a[i] ;
    
    cout<<bin();
}   
