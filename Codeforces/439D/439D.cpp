#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = pow(10,5)+10 ; 
int a[maxn] = {} , b[maxn] = {} ; 
int n ,m ; 

ll f(int k )
{
    ll ans = 0 ;
    for(int i = 1 ; i<= n ;i++) ans +=max((ll)0,(ll)(k-a[i])) ;
    for(int i = 1 ;i<=m ;i++) ans +=max((ll)0,(ll)(b[i]-k)) ;

    return ans ; 
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

    for(int i = 1 ;i<=m ;i++) cin>>b[i] ;

    int k = 0 ; 
    for(int d = 1e9; d>=1 ; d/=2)
    {
        while(f(k+d)>f(k+d+1)) k+=d ;
    }
    
    k++ ;
    cout<<f(k);
}
