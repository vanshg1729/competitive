#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = pow(10,5) + 10 ; 
ll p[maxn] = {} , r[maxn]  = {} ; 
ll siz[maxn] = {} , ans[maxn] = {} ; 
ll n ,m , pairs = 0 ;  
vector<pair<ll,ll> > edge = {} ; 

ll get(ll a)
{
    return p[a] = (p[a] == a ? a : get(p[a]) ) ;
}

ll uni(ll a , ll b)
{
    a = get(a) ; 
    b = get(b) ; 

    if(a == b) return 0 ; 

    pairs -= siz[a]*siz[b] ; 

    if(r[a] == r[b]) r[a] ++ ; 

    if(r[a]>r[b])
    {
        p[b] = a ; 
        siz[a]+=siz[b] ; 
    }
    else
    {
        p[a] = b ; 
        siz[b] += siz[a] ; 
    }

    return 0 ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin) ; 
    //freopen("output.txt","w",stdout); 

    cin>>n>>m ; 
    pairs = (n*(n-1))/2 ;

    for(int i = 1 ; i<=n ; i++)
    {
        siz[i] = 1 ; 
        p[i] = i ; 
    }

    for(int i = 1 ; i<=m ; i++)
    {
        int a , b ; cin>>a>>b ; 
        edge.push_back({a,b}) ; 
    }

    ans[m] = pairs ; 
    for(int i = m-1 ; i>=0 ; i--)
    {
        uni(edge[i].fr,edge[i].sc) ; 

        ans[i] = pairs ; 
    }

    for(int i = 1 ; i<=m ; i++) cout<<ans[i]<<"\n" ;
}   
