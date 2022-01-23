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
   // freopen("input.txt","r", stdin);
   // freopen("output.txt","w",stdout);
    
    int n ; cin>>n ; 
    int m = pow(10,5) + 1 ;
    vector<int> v = {} ;
    int seen[m] = {} ; 
    for(int i = 0 ; i<n ; i++)
    {
        int b ; cin>>b ;  
        v.push_back(b) ; 
    }

    sort(v.begin(),v.end()) ;
    memset(seen,-1,sizeof(seen)) ; 

    for(int i = 0 ; i<n ;i++)
    {
        seen[v[i]] = i ; 
    } 
    
    int dp[n][m] = {} ;
    
    int ans = 1 ; 
    for(int i = 0 ;i<n ;i++)
    {
       for(int j = 1 ;j<=m;j++)
       {
          dp[i][j] = 1 ;
          if(seen[v[i]-j]!=-1 and v[i]-j>=0)
          {
             dp[i][j] = max(dp[i][j],dp[seen[v[i]-j] ][j]+1) ; 
          }

          ans = max(ans,dp[i][j]) ;
       }
    }

    cout<<ans ;
}
