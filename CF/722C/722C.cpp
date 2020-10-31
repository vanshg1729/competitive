#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = pow(10,5)+10 ;
int n ; 
ll max_sum = 0 ; 
ll m[maxn] = {} , order[maxn] = {} , ans[maxn] = {} ;  
ll p[maxn] = {} , sum[maxn] = {} , r[maxn] = {} ;  

ll get(int a)
{
    return p[a] = (p[a] == a? a: get(p[a])) ; 
}

ll uni(ll a , ll b)
{
    a = get(a) ; 
    b = get(b) ; 

    if(a == b or a*b == 0) return 0 ; 

    if(r[a] == r[b]) r[a]++ ; 

    if(r[a]>r[b])
    {
        p[b] = a ; 
        sum[a]+=sum[b] ; 
    }
    else
    {
        p[a] = b ; 
        sum[b]+=sum[a] ; 
    }

    max_sum = max(max_sum , max(sum[a],sum[b])) ; 
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

    for(int i = 1 ; i<=n ; i++) cin>>m[i] ;

    for(int i = 1 ; i<=n ;i++ ) cin>>order[i] ; 

    for(int i = n ; i>=1;i--)
    {
        int j = order[i] ; 
        sum[j] = m[j] ; 
        p[j] = j ; 
        r[j] = 1 ; 

        uni(j,j+1) ; 
        uni(j,j-1) ; 

        max_sum = max(sum[j],max_sum) ;
        ans[i-1] = max_sum ; 
    }

    for(int i = 1 ; i<=n ; i++) cout<<ans[i]<<"\n" ;
}   
