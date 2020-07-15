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
    
    int n; 
    while(cin>>n)
    {
        int a[n+1][n+1]={};
        int p[n+1][n+1]={};
        int ans = INT_MIN;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
               cin>>a[i][j];
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                p[i][j]=p[i-1][j]+a[i][j];
            }
        }

        for(int x=1;x<=n;x++)
        {
            for(int y=x;y<=n;y++)
            {
               int cur = p[y][1]-p[x-1][1];
               int best = cur;

               for(int j=2;j<=n;j++)
               {
                 cur = max(p[y][j]-p[x-1][j],cur+p[y][j]-p[x-1][j]);
                 best = max(best,cur);
               }

               ans = max(ans,best);
            }
        }

        cout<<ans<<endl;
    }   

}
