#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1010;
const int maxc = 10010; 
ll dp[maxn][maxc];
ll cost[maxn],c[maxn];

int main()
{
   cin.tie(0);
   cout.tie(0);
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   ll n,w,b,x; cin>>n>>w>>b>>x;
   ll sum = 0,ans = 0;
   
   for(int i = 1;i<=n;i++)
   {
    	 cin>>c[i];
    	 sum+=c[i];
   }

   for(int i = 1;i<=n;i++) cin>>cost[i];

   memset(dp,-1,sizeof(dp));
   
   dp[0][0] = w;
   
   for(ll i = 1;i<=n;i++)
   {
   	 for(ll j = 0;j<=sum;j++)
   	 {
   	 	for(ll k = 0;k<= min(j,c[i]);k++)
   	 	{
   	 		if(dp[i-1][j-k]==-1)
   	 		{
   	 			continue;
   	 		}

   	 		ll new_mana = min(w+(j-k)*b,dp[i-1][j-k]+x) - cost[i]*k;
   	 		if(new_mana<0) continue;
            
   	 		dp[i][j] = max(dp[i][j],new_mana);
   	 		ans = max(ans,j);
   	 	}

   	 }
   	 
   }

   cout<<ans;
}
