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
   // freopen("output.txt","w",stdout);
    
    int n , t ;cin>>n>>t ;
    int a[n+1] = {} ;
    for(int i = 0 ;i<n ;i++) cin>>a[i] ;

    ll freq[t+1] = {} ;
    ll ans = 0 ;
    for(int i = 0 ; i<n ;i++)
    {
        for(int j = i+1 ;j<n ;j++)
        {
            if(a[i]+a[j]<t)
            {
                ans+=freq[t-a[i]-a[j]] ;
            }
        }

        for(int j = 0 ;j<i ;j++)
        {
            if(a[j]+a[i]<t) freq[a[i]+a[j]]++ ;
        }
    }    
    
    cout<<ans ; 
}
