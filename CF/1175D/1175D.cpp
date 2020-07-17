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
    int n,k;
    cin>>n>>k;
    ll ans = 0;
    ll num = 0;
    ll a[n]={};
    pair<ll,ll> s[n]={};

    for(int i=0;i<n;i++) cin>>a[i];

    s[n-1].first = a[n-1];
    s[n-1].second = n-1;

    for(int i=n-2;i>=0;i--)
    {
        s[i].second = i;
        s[i].first = s[i+1].first +a[i];
    }
    
    ans+=s[0].first;
    num++;
    sort(s,s+n);
    
    for(int i=n-1;i>=0;i--)
    {
        if(s[i].second!=0 and num<k)
        {
            num++;
            ans+=s[i].first;
        }

        if(num==k) break;
    }

    cout<<ans;
}  
   
