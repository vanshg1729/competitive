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
    
    int n,m,k ;cin>>n>>m>>k ;

    int seen[n+10][m+10] = {} ; 

    for(int i = 1 ;i<=k ;i++)
    {
        int x,y , t,f ;cin>>x>>y>>t>>f ;

        seen[x][y] = 1 ;

        int a = x+y-t-2 ;
        
        if(a<0) continue ;     
        if(a%f == 0) for(int j = 1 ; j+x<=n ;j++) seen[x+j][y] = 1 ;

        if(a%f == 0) for(int j = 1; j+y<=m ;j++) seen[x][y+j] = 1 ;

        for(int j = 0 ;j*f<=n+m-2 ;j++)
        {
           int b = a - j*f ;
           if(b%2 or b<0) continue ; 
           b/=2 ;

           if(x-b>=1) seen[x-b][y] = 1 ;
           if(y-b>=1) seen[x][y-b] = 1 ;
        }
    }

    int dp[n+10][m+10] = {} ;
    
    dp[1][1] = 1 ;
    for(int i = 1 ;i<=n ;i++)
    {
        for(int j = 1 ;j<=m ; j++)
        {
            if(seen[i][j]) continue ;
            if(i == 1 and j ==1 ) continue ; 
            dp[i][j] = (dp[i-1][j] or dp[i][j-1]) ;
        }
    }
    
    if(dp[n][m])
    {
        cout<<"YES"<<endl<<n+m-2 ;
    }
    else cout<<"NO" ;
}
