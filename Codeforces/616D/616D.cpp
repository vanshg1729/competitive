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
    
    int n , k ;  cin>>n>>k ;
    int a[n+1] = {} ;
    for(int i = 1 ;i<=n ;i++) cin>>a[i] ;

    map<int,int> m ; 
    int dis = 1 ;
    int ans = 0 ; 
    pair<int,int> idx = {0,0} ;
    int i = 1 , j = 1 ;
    m[a[1]] = 1 ;

    while(i<=j and j<=n)
    {
        if(dis<=k)
        {
            if(j-i+1>ans)
            {
                ans = j-i+1 ;
                idx = {i,j} ;
            }

            if(j<n)
            {
                j++ ;
                m[a[j]]++ ;
                if(m[a[j]]==1) dis++ ;
            }
            else
            {
                m[a[i]]--; 
                if(m[a[i]]==0) dis-- ;
                i++ ;
            }
        }
        else
        {
            m[a[i]]-- ;
            if(m[a[i]]==0) dis-- ;
            i++ ;
        }
    }

    cout<<idx.fr<<" "<<idx.sc ;
}
