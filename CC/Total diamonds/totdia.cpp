#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2*pow(10,6);
ll dp[maxn+1]={};
ll f[2*maxn+1]={};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    for(ll i=1;i<=2*maxn;i++)
    {
        ll a=0 ,b=0; 
        ll num =i;
        while(num>0)
        {
            ll rem = num%10;
            if(rem%2) a+=rem;
            else b+=rem;
            num/=10;
        }

        f[i] = abs(a-b);
    }

    for(int i=1;i<=2*maxn;i++)
    {
        f[i]+=f[i-1];
    }

    dp[1]=2;

    for(int i=2;i<=maxn;i++)
    {
       dp[i]=dp[i-1]+f[2*i]+f[2*i-1]-2*f[i];
    }
    
    int t; cin>>t;
    while(t--)
    {
        int n ; cin>>n; 
        cout<<dp[n]<<endl;
    }
}
