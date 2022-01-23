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
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
 
        sort(a,a+n);
 
        long long b[110]={};
        long long ans = 0;
 
        for(int k=1;k<=100;k++)
        {
           int i =0; int j =n-1;
           
           while(j>i)
           {
              if(a[i]+a[j]==k)
              {
                i++; j--;
                b[k]++;
              }
              else if(a[i]+a[j]>k)
              {
                j--;
              }
              else
              {
                i++;
              }
           }
 
           ans = max(ans,b[k]);
        }
 
        cout<<ans<<"\n"; 
    }
}   
