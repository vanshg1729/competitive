#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    int n; cin>>n;
    int b[n+1]={};
    int dp[n+1][n+1]={};
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        dp[0][i]=b[i];
    }

    for(int i=1;i<n;i++)
    {
        for(int j =1;j<=n-i;j++)
        {
            dp[i][j] = dp[i-1][j]^dp[i-1][j+1];
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i-1][j+1]));
        }
    }

    int q; cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r; cin>>l>>r;
        cout<<dp[r-l][l]<<endl;
    }
   
}
