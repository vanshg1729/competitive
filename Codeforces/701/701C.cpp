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
    
    int m  = 70 ; 
    
    int n ; cin>>n ;
    vector<int> v[m] = {} ;
    int a[n+1] = {} ;

    for(int i = 1 ;i<= n ;i++)
    {
        char b ; cin>>b ;
        a[i] = b-'A' ;
        v[a[i]].push_back(i) ; 
    }

    for(int i = 0 ;i<m ;i++) v[i].push_back(INT_MAX) ;
    
    int ans = INT_MAX ; 
    for(int i = 1 ;i<=n ;i++)
    {
        int idx = i ;
        for(int j = 0 ;j<70 ;j++)
        {
            if(v[j].size()==1 or a[i] == j ) continue ;

            auto k = upper_bound(v[j].begin(),v[j].end(),i) -v[j].begin() ;

            idx = max(idx,v[j][k]) ;
        }

        if(idx<INT_MAX) ans = min(ans,idx-i+1) ;
    }

    cout<<ans ;
}
