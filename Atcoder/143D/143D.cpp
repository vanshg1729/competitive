#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second


vector<int> v = {} ;

int bin(int x)
{
    int n = v.size(); n-- ;
    int k = 0 ;
    int d = n ;

    while(1)
    {
       if(k+d<=n and v[k+d]<x) k+=d ;

       if(d == 1) break ; 

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
    
    int n ; cin>>n ; 

    for(int i = 1 ;i<=n ;i++)
    {
        int a ;cin>>a ;
        v.push_back(a) ;
    }

    v.push_back(0) ;

    sort(v.begin(),v.end()) ;
    
    ll ans = 0 ;
    for(int i = 1 ;i<=n ;i++)
    {
        for(int j = i+1 ;j<=n ;j++)
        {
            int k = bin(v[i]+v[j]) ;

            ans+=(ll)(k-j) ;
        }
    }
    
    cout<<ans ;
}
