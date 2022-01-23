#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const ll maxm = 2*pow(10,5)+10 ; 
ll m , n , k , t ; 
ll sol[maxm] = {} ; 
vector<vector<ll> > trap(maxm,vector<ll>(3,0)) ; 

bool check(ll num)
{
    ll i = 0 ; 
    ll min = sol[m-num+1] ; 
    ll time = 0 ;
    
    ll a[n+2] = {} ; 

    for(int i = 1 ; i<=k ;i++)
    {
        if(trap[i][2]<=min) continue ; 

        a[trap[i][0]] = max(a[trap[i][0]],trap[i][1]) ; 
    }
    
    while(i<=n)
    {
        if(!a[i+1])
        {
            time++ ; i++ ;
            continue ; 
        }

        ll j = i  , r = a[i+1] ;  

        while(i<r)
        {
            i++ ; 
            r = max(r,a[i]) ; 
        }

        time+= 3*(r-j) ;

    }

    return time <= t ; 
}

ll bin()
{
    ll k = 0 , d = m ; 

    while(1)
    {
        if(k+d<=m and check(k+d)) k+=d ; 

        if(d == 1) break  ; 

        d = d/2 + d%2 ; 
    }

    return k ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    cin>>m>>n>>k>>t ;   
    
    for(int i = 1 ;i<=m ;i++) cin>>sol[i] ; 

    for(int i = 1; i<=k ;i++)
    {
        for(int j = 0 ; j<3 ;j++)
        {
            ll a ; cin>>a ; 
            trap[i][j] = a; 
        }
    }

    sort(sol,sol+m+1) ; 
    sort(trap.begin(),trap.begin()+k+1) ; 

    cout<<bin(); 
}
