#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

int check(int a, int b , int n )
{
    if(1<=a and a<=n and b>=1 and b<=n) return true ; 
    else return false ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("input.txt","r", stdin);
 //   freopen("output.txt","w",stdout);
    
    int n,m ; cin>>n>>m ; 
    ll a[n+10][n+10] = {} ; 
    int seen[n+10][n+10] = {} ; 

    for(int i = 1; i<=n ; i++)
    {
        for(int j = 1 ;j<=n ; j++)
        {
            cin>>a[i][j] ; 
        }
    }
    
    vector<pair<int,int> > v = {{1,1},{1,-1},{-1,-1},{-1,1}} ;

    for(int i = 1; i<=m ;i++)
    {
        int x , y , k ; cin>>x>>y>>k ;

      for(int l = 0 ; l<=k ;l++)
      {


        for(int j = 0 ; j<=l ;j++)
        {
            int c = j , b = l-j ; 
            for(auto u : v )
            {
                if(check(x+u.fr*c,y+u.sc*b,n))
                {
                    seen[x+u.fr*c][y+u.sc*b] = 1 ; 
                }
            }
        }

       }     
    }

    ll dp[n+10][n+10] = {} ; 

    for(int i = 1; i<=n ;i++)
    {
        for(int j = 1 ;j<=n ;j++)
        {
            dp[i][j] = INT_MIN ;   
            if(!seen[i][j]) continue ;
            if(i == 1 and j == 1)
            {
                dp[i][j] = a[i][j] ;
            }

            if(check(i-1,j,n) and dp[i-1][j]!=INT_MIN and seen[i-1][j])
            {
               dp[i][j] = dp[i-1][j] + a[i][j] ;
            }

            if(check(i,j-1,n) and dp[i][j-1]!=INT_MIN and seen[i][j-1])
            {
                dp[i][j] = max(dp[i][j],dp[i][j-1]+a[i][j]) ;
            } 
        }
    }

    if(dp[n][n]==INT_MIN) cout<<"NO"<<endl ; 
    else
    {
        cout<<"YES"<<"\n" ; 
        cout<<dp[n][n] ; 
    }


}
