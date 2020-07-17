#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(  0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    ll n; cin>>n;
    ll a[n+10][2]={};
    pair<ll,ll> b[n]={};
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0];

        b[i].first = a[i][0];
        b[i].second = i;
    }

    if(n==1) {cout<<0; return 0;}

    sort(b,b+n);

    ll count = 0;
    ll i = 0;
    ll ans = 0;
    while(count<n)
    {
        
       ll pos = b[i].second;
       if(a[pos][1]==0)
       {

         ll j = pos-1;
         ll k = pos+1;
         while(j>0 and a[j][1]!=0) j--;

         while(k<n-1 and a[k][1]!=0) k++;

         if(j>=0 and a[j][0]<=a[pos][0] and a[j][1]==0)
         {
            count++; a[j][1]=-1; ans +=a[pos][0]; 
         }
         else if(k<n and a[k][0]<=a[pos][0] and a[k][1]==0)
         {
            count++; a[k][1]=-1; ans+=a[pos][0];
         }
         else
         {
            i++;
         }

       }
       else
       {
         i++; continue;
       }

       if(count == n-1) break;
    }

    cout<<ans;
}   

   
