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
    
    int n, m ; cin>>n>>m ;

    vector<ll> v = {} ; v.push_back(0) ;

    for(int i = 1 ;i<=n ;i++)
    {
        ll a ; cin>>a ;
        v.push_back(v[i-1]+a) ;
    }

    while(m--)
    {
        ll b ; cin>>b ;

        int k = 0 ;

        int d = n/2 + n%2 ;

        while(d>=1)
        {
            if(k+d<=n and v[k+d]<b) k+=d ;
            
            if(d==1) break ;
            d = d/2 + d%2 ;
        }

        cout<<k+1<<" "<<b-v[k]<<"\n" ;
    }
}
