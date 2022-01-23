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
    ll n; cin>>n;
    ll a[n+10]={};
    ll b[n+10]={};
    ll p[n+10][2] = {};
    ll pw[n+10][2] ={};
    ll sw[n+10][2]={};

    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i][0] = p[i-1][0]+a[i];
        pw[i][0] = pw[i-1][0] +i*a[i];
    }

    for(ll i =1;i<=n;i++)
    {
        cin>>b[i];
        p[i][1] = p[i-1][1] +b[i];
        pw[i][1] = pw[i-1][1] +i*b[i];
    }

    sw[n][0] = a[n]; sw[n][1] = b[n];

    for(ll i =n-1;i>0;i--)
    {
        sw[i][0] = sw[i+1][0] + (n-i+1)*a[i];
        sw[i][1] = sw[i+1][1] +(n-i+1)*b[i];
    }
    
    ll zigz = b[1];
    ll c = pw[n][0]-p[n][0]+sw[1][1]+(n-1)*p[n][1];
    ll d = pw[n][1] +sw[2][0]+n*(p[n][0]-p[1][0]) ;
    ll ans = max(c,d);
    
    for(ll i =2;i<=n;i++)
    {
        if(i%2==0)
        {
            zigz+= (2*i-1)*a[i] +(2*i-2)*b[i];
            ll c = zigz + pw[n][0]-pw[i][0] +(i-1)*(p[n][0]-p[i][0])+sw[i+1][1]+(n+i-1)*(p[n][1]-p[i][1]);
            ans = max(ans,c);
        }
        else
        {
            zigz+= (2*i-2)*a[i] + (2*i-1)*b[i];
            ll d = zigz + pw[n][1]-pw[i][1] +(i-1)*(p[n][1]-p[i][1]) +sw[i+1][0] +(n+i-1)*(p[n][0]-p[i][0]);
            ans = max(ans,d);
        }

    }
    
    cout<<ans;
}   

   
