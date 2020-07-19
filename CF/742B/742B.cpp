#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2*pow(10,5);
ll a[maxn+10]={};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    int n; ll x;
    cin>>n>>x;
    ll b[n+1]={};
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        a[b[i]]++;
    }

    ll ans = 0;

    for(int i=0;i<n;i++)
    {
        if(x==0)
        {
          int c = b[i];
          ll d = a[c];
          if(d>0) ans+= (d*(d-(ll)1))/2 ;
          a[c] = 0;
        }
        else
        {
            int c = b[i]^x;
            ans+=a[c];
        }
    }

    if(x!=0) ans/=2;

    cout<<ans;
}  

   
