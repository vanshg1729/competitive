    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
     
    int main()
    {
       cin.tie(0);
       cout.tie(0);
       //freopen("input.txt","r",stdin);
       //freopen("output.txt","w",stdout);
       int n,k; cin>>n>>k;
       int l = 25*k;
       int t = 2;
       int dp[t][k+1][l+1]={};
       pair<int,int> a[n+1]={};
       for(int i = 1;i<=n;i++)
       {
       	 long long b; 
       	 cin>>b;
       	 int five = 0, two = 0;
       	 while(b%5==0 )
       	 {
       	 	b/=5;
       	 	five++;
       	 }
       	 while(b%2==0 )
       	 {
       	 	b/=2;
       	 	two++;
       	 }
     
       	 a[i] = {five,two};
       }
     
       for(int i = 0 ;i<=k;i++)
       {
           for(int j = 0;j<=l;j++)
           {
     
           	 if(i==0 and j==0) continue;
           	 else dp[0][i][j] = -1;
     
           }
       }
       
       int ans = 0;
     
       for(int i = 1;i<=n;i++)
       {
     
       	 for(int j = 0;j<=k;j++)
       	 {
     
       	 	for(int s = 0;s<=l;s++)
       	 	{
     
              dp[i%2][j][s] = dp[(i+1)%2][j][s];
              if(s-a[i].first>=0 and j-1>=0 and dp[(i+1)%2][j-1][s-a[i].first]!=-1)
              {
              	 dp[i%2][j][s] = max(dp[i%2][j][s],dp[(i+1)%2][j-1][s-a[i].first]+a[i].second);
              }
              
              if(i==n and j==k)
              {
              	 ans = max(ans,min(s,dp[n%2][k][s]));
              }
     
       	 	}
     
       	 }
     
       }
       
       cout<<ans;
    }
