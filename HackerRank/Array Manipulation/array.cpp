#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = pow(10,7)+10;
ll d[maxn]={};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    ll n,m; cin>>n>>m;
    for(int i=0;i<m;i++)
    {
       ll a,b,k; cin>>a>>b>>k;
       d[a]+=k; d[b+1]-=k;
    }

    ll ans = d[1];
    
    for(int i=2;i<=n;i++)
    {
        d[i]+=d[i-1];
        ans= max(ans,d[i]);
    }

    cout<<ans;
}
