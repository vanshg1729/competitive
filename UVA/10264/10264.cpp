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
    int m = pow(2,n);
    int a[m+1]={};
    for(int i=0;i<m;i++) cin>>a[i];

    int we[m+1]={};
    int ans = 0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int c =i;
            c^=(1<<j);
            we[i]+=a[c];
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int c = i;
            c^=(1<<j);
            ans = max(ans,we[i]+we[c]);
        }
    }

    cout<<ans<<endl;
}

}  
   


