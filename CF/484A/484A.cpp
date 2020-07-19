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
    
    int n; cin>>n;
    while(n--)
    {
        ll l,r;
        cin>>l>>r;
        int count = 0;
        for(int i=0;i<63;i++)
        {
            ll c = 1;
            c = c<<i;
           if(l&c)
           {
             count++;
           }
           else
           {
              l|=c;
              if(l<=r) count++;
              else l^=c;
           }
        }

        cout<<l<<endl;
    }
}  

   

