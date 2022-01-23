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
    int n,m; cin>>n>>m;
    int a[n+1][m+1]={};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c ; cin>>c;
            if(c=='.') a[i][j] =1;
        }
    }

    int r[n+1][m+1]={};
    int c[n+1][m+1]={};
    int dp[n+1][m+1]={};

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            r[i][j] = r[i][j-1];
            c[i][j] = c[i-1][j];
            if(a[i][j]*a[i-1][j])
            {
                dp[i][j]++; c[i][j]++;
            }
            if(a[i][j]*a[i][j-1])
            {
                dp[i][j]++; r[i][j]++;
            }
        }
    }
    
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/

    int q; cin>>q;
    for(int i=0;i<q;i++)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        int b = dp[x2][y2] +dp[x1][y1]-dp[x2][y1]-dp[x1][y2]+(r[x1][y2]-r[x1][y1]) +(c[x2][y1]-c[x1][y1]);
        cout<<b<<endl;
    }
}
