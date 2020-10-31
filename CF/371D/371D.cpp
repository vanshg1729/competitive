#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = 2*pow(10,5) +10 ; 
int n , m ; 
ll vess[maxn] = {}, p[maxn] = {} , cap[maxn] = {} ; 

ll get(ll a)
{
    return p[a] = (p[a] == a ? a : get(p[a])) ; 
}

ll find(ll a , ll b)
{
    ll c = get(a) ; 

    if(cap[c] + b <= vess[c])
    {
        cap[c]+= b ; 
    }
    else
    {
        b = (cap[c] + b - vess[c]) ; 
        cap[c] = vess[c] ; 
        p[c] = get(c+1) ; 
        c = p[c] ; 
        find(c,b) ; 
    }

    return 0 ; 
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    cin>>n ; 

    for(int i = 1 ; i<=n ; i++)
    {
        cin>>vess[i] ; 
        p[i] = i ; 
    }
    
    vess[n+1] = 1e15 ; p[n+1] = n+1 ; 
    cin>>m ; 

    while(m--)
    {
        ll t , a , b ; cin>>t ; 

        cin>>a ; 

        if(t == 1) cin>>b ; 

        if(t == 2) cout<<cap[a]<<"\n" ;
        else find(a,b) ; 
    }

}   
