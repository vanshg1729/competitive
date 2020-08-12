    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    const int maxn = 5010;
    int palin[maxn][maxn]={};
    int dp[maxn][maxn]={};
    string s;
    int f(int i,int j)
    {
    	if(dp[i][j]) return dp[i][j];
    	if(i>j)
    	{
    		dp[i][j] = 0;
    		return 0;
    	}
    	else if(i==j)
    	{
    		palin[i][i] = 1;
    		dp[i][i] = 1; return 1;
    	}
    	else if(j-i==1)
    	{
    		dp[i][j] = 2;
    		if(s[i]==s[j])
    		{
    			dp[i][j]+=1;
    			palin[i][j] = 1;
    		}
    		return dp[i][j];
    	}
     
    	dp[i][j] = f(i+1,j) + f(i,j-1) - f(i+1,j-1);
    	if(palin[i+1][j-1] and s[i]==s[j])
    	{
    		palin[i][j] = 1;
    		dp[i][j]++;
    	}
    	return dp[i][j];
    }
     
    int main()
    {
       cin.tie(0);
       cout.tie(0);
       //freopen("input.txt","r",stdin);
       //freopen("output.txt","w",stdout);
       cin>>s;
     
       int n = s.size();
       for(int i = 0;i<n;i++)
       {
       	 for(int j = i;j>=0;j--)
       	 {
       	 	f(j,i);
       	 }
       }
     
       int q; cin>>q;
       for(int i =1;i<=q;i++)
       {
       	 int l,r; cin>>l>>r;
       	 cout<<dp[l-1][r-1]<<"\n";
       }
    }    
     
