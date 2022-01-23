#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
   cin.tie(0);
   cout.tie(0);
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n; cin>>n;
   long long mod = pow(10,9)+7;
   char a[n+1]={};
   for(int i=1;i<=n;i++) cin>>a[i];
 
   long long dp[n+1][n+1]={};
   for(int j = 0;j<=n;j++) dp[1][j] = 1;
 
   for(int i=2;i<=n;i++)
   {
   	 for(int j =0;j<=n;j++)
   	 {
   	 	if(a[i-1]=='f')
   	 	{
   	 		if(j==0) continue;
   	 		dp[i][j] = dp[i][j-1];
   	 		if(j==1)
   	 		{
   	 			dp[i][1]+=dp[i-1][0];
   	 		}
   	 		else
   	 		{
   	 			dp[i][j]+=dp[i-1][j-1]-dp[i-1][j-2];
   	 		}
 
   	 	}
   	 	else
   	 	{
   	 		if(j==0)
   	 		{
   	 			dp[i][0] = dp[i-1][n];
   	 		}
   	 		else
   	 		{
   	 			dp[i][j] = dp[i][j-1]+dp[i-1][n]-dp[i-1][j-1];
   	 		}
   	 	}
 
   	 	dp[i][j]+=mod; dp[i][j]%=mod;
   	 }
 
   }
 
   cout<<dp[n][n];
}    
