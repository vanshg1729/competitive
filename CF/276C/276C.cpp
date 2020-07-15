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
    int n,q;
    cin>>n>>q;
    ll a[n];
    ll diff[n]={};
    for(int i=0;i<n;i++) cin>>a[i];
    
    for(int i=0;i<q;i++)
    {
        int a,b; cin>>a>>b;
        diff[a-1]++;
        diff[b]--;
    }

    for(int i=1;i<n;i++)
    {
        diff[i]+=diff[i-1];
    }

    sort(a,a+n);
    sort(diff,diff+n);

    ll ans = 0;
    for(int i=0;i<n;i++) ans+=diff[i]*a[i];

    cout<<ans;


}
