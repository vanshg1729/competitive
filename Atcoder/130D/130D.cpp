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

    ll n , k ; cin>>n>>k ;
    ll a[n+1] = {} ; 
    for(int i = 1 ;i<=n ;i++) cin>>a[i] ;
    ll sum = a[1] ;

    ll ans = 0 ; 
    ll i = 1 , j = 1 ;

    while(i<=j and j<=n)
    {
        if(sum>=k)
        {
            ans+=n-j+1 ;
            sum-=a[i];
            if(i==j){ i++;j++ ; sum+=a[j] ;}
            else i++ ;
        }
        else
        {
            j++ ;
            sum+=a[j] ;
        }
    }

    cout<<ans ;
}
