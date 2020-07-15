#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      //freopen("input.txt","r", stdin);
     // freopen("output.txt","w",stdout);
      
int n;
while(cin>>n)
{


       int a[n+1][n+1]={};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }

    int p[n+1][n+1]={};

    for(int i =1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            p[i][j]=p[i-1][j]+p[i][j-1]+a[i][j]-p[i-1][j-1];
        }
    }

    int ans = INT_MIN;

    for(int x1 =1;x1<=n;x1++)
    {
        for(int x2=x1;x2<=n;x2++)
        {
            for(int y1=1;y1<=n;y1++)
            {
                for(int y2=y1;y2<=n;y2++)
                {
                    int b = p[x2][y2]-p[x1-1][y2]-p[x2][y1-1]+p[x1-1][y1-1];
                    ans = max(ans,b);    
                }
            }
        }
    }

    cout<<ans<<endl; 

    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
        for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
}

}
