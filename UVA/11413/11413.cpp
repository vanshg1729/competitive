#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = 1010 ; 
ll a[maxn] = {} ; 
ll n , m , big = 0; 
ll sum = 0 ; 

bool check(ll siz)
{
    int cap = 1 ; 
    int i = 1 ; 
    ll sum = 0 ; 

    while(i<=n)
    {
        if(cap == m and sum+a[i]>siz) return 0 ; 

        if(sum+a[i]<=siz and n-i>=m-cap)
        {
            sum+=a[i] ; 
            i++ ; 
        }
        else
        {
            sum = 0 ; 
            cap++ ;
        }
    }

    return 1 ; 
}

ll bin()
{
    ll k = 0 , d = sum ; 

    while(1)
    {
        if(k+d <= sum and !check(k+d)) k+=d ;
        
        if(d == 1) break ; 
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
    
    while(cin>>n>>m)
    {
        sum = 0 ; big = 0 ;

        for(int i = 1 ;i<=n ;i++) 
        {
            cin>>a[i] ;
            sum+= a[i] ; 
            big = max(big,a[i]) ;
        }

        if(m>=n)
        {
            cout<<big<<"\n" ; 
        }
        else cout<<bin()<<"\n" ;

        memset(a,0,sizeof(a)) ;
    }
}
