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
    
    string s; cin>>s;
    int n = s.size();
    int a[n+1]={};
    int b[n+1]={};
    for(int i=0;i<n;i++)
    {
        a[i+1] = a[i]; b[i+1]=b[i];
        if(s[i]=='a') a[i+1]++;
        else b[i+1]++;
    }
    
    int ans = INT_MAX;
    ans = min(b[n],a[n]);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            ans = min(ans,min(b[i-1]+a[j]-a[i-1]+b[n]-b[j],b[i]+a[n]-a[i]));
            ans = min(ans,a[i]+b[n]-b[i]);
        }
    }

    cout<<n-ans;
}
