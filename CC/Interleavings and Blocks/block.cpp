#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = 110 ;
const int maxk = 210 ;
ll dp[maxn][maxn][maxk][2] = {} ;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    int T ; cin>>T ;
    while(T--)
    {
       ll n , m , k ; cin>>n>>m>>k ;
       
       ll mod = pow(10,8)+7 ;
       ll a[n+10] = {} ,b[m+10] = {} ; 
  
       for(int i = 1;i<=n ;i++) cin>>a[i] ;

       for(int j = 1 ;j<=m ;j++) cin>>b[j] ; 
       
       memset(dp,0,sizeof(dp)) ;
       int j = 1 ;
       dp[1][0][1][0] = 1 ;
       for(int i = 2 ;i<=n ;i++)
       {
          if(a[i]!= a[i-1]) j++ ;

          if(j<=k) dp[i][0][j][0] = 1 ;
       }

       j = 1 ; dp[0][1][1][1] = 1 ;

       for(int i = 2 ;i<=m ; i++)
       {
          if(b[i]!=b[i-1]) j++ ;

          if(j<=k) dp[0][i][j][1] = 1 ;
       }

       for(int i = 1 ;i<=n ;i++)
       {
          for(int j = 1 ;j<=m ;j++)
          {
              for(int x = 1 ;x<=k ;x++)
              {
                   dp[i][j][x][0]+=(a[i]==a[i-1]) ? (dp[i-1][j][x][0]):(dp[i-1][j][x-1][0]) ;

                   dp[i][j][x][0]+=(a[i]==b[j]) ? (dp[i-1][j][x][1]):(dp[i-1][j][x-1][1]) ;

                   dp[i][j][x][1]+= (b[j]==b[j-1]) ? (dp[i][j-1][x][1]):(dp[i][j-1][x-1][1]) ;

                   dp[i][j][x][1] += (b[j]==a[i]) ? (dp[i][j-1][x][0]):(dp[i][j-1][x-1][0]) ;

                  dp[i][j][x][0]%=mod ;
                  dp[i][j][x][1]%=mod ;
              }
           }
       }

       cout<<(dp[n][m][k][1]+dp[n][m][k][0])%mod<<"\n" ;
    }

}
