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
    cin>>n;
    int a[n+1]={};
    int p[n+1]={};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }

    int ans =0;
    for(int i=1;i<n;i++)
    {
        if(p[i]==p[n]-p[i]) ans++;
    }

    cout<<ans;
}
