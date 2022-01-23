    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    const int maxn = 202;
    long long r[maxn],g[maxn],b[maxn];
    long long dp[maxn][maxn][maxn];
     
    int f(int i, int j,int k)
    {
    	if(dp[i][j][k]>=0) return dp[i][j][k];
        
        long long ans = 0;
    	if(i and j) ans = max(ans,f(i-1,j-1,k) + r[i]*g[j]);
    	if(j and k) ans = max(ans,f(i,j-1,k-1) + g[j]*b[k]);
    	if(k and i) ans = max(ans,f(i-1,j,k-1) + b[k]*r[i]);
        
        dp[i][j][k] = ans;
        return ans;
    }
     
    int main()
    {
       cin.tie(0);
       cout.tie(0);
       //freopen("input.txt","r",stdin);
       //freopen("output.txt","w",stdout);
       int R,G,B; cin>>R>>G>>B;
     
       for(int i = 1;i<=R;i++) cin>>r[i];
       for(int i = 1;i<=G;i++) cin>>g[i];
       for(int i = 1;i<=B;i++) cin>>b[i];
       sort(r,r+R+1);
       sort(g,g+G+1);
       sort(b,b+B+1);
     
       	memset(dp,-1,sizeof(dp));
        cout<<f(R,G,B)<<endl;
    }
