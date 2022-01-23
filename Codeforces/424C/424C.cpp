#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = pow(10,6)+10;
ll p[maxn]={};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        p[i]=i^p[i-1];
    }

    ll q = 0;

    for(int i=1;i<=n;i++)
    {
        int j = n/i;
        if(j%2)
        {
            q^=p[i-1];
        }

        ll rem = n%i;
        q^=p[rem];
    }

    for(int i=0;i<n;i++)
    {
        ll a; cin>>a;
        q^=a;
    }

    cout<<q;
}    
   


