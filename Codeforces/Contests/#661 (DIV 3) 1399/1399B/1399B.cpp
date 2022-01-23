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
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        long long a[n]={};
        long long b[n] = {};
        long long sa = LLONG_MAX;
        long long sb = LLONG_MAX;
 
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sa = min(sa,a[i]);
        }
 
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            sb = min(sb,b[i]);
        }
 
        long long ans = 0;
 
        for(int i=0;i<n;i++)
        {
            ans+=max(a[i]-sa,b[i]-sb);
        }
 
        cout<<ans<<"\n";
    }
}   
 
