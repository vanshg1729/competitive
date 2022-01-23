#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

vector<ll> v = {} ; 

int bin(ll t , int i)
{
    int n = v.size() ; n-- ;
    int d = n ,k = 0 ;
   
    while(1)
    {
        if(k+d<=n and t>= v[k+d]-v[i-1]) k+=d ;
        if(d == 1) break ; 

        d = d/2 + d%2 ;
    }

    return k-i+1 ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r", stdin);
    freopen("output.txt","w",stdout);

    ll n ,t ; cin>>n>>t ;
    v.push_back(0) ;
    
    for(int i = 1 ;i<=n ;i++)
    {
        ll a ; cin>>a ;
        v.push_back(v[i-1]+a) ; 
    }
    
    int ans = 0 ;
    for(int i = 1 ;i<=n ;i++)
    {
       ans = max(bin(t,i),ans) ;
    }

    cout<<ans ;
}
