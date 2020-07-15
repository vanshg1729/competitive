#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    int n; cin>>n;
    int freq[n+1]={};
    
    for(int i=2;i<=n;i++)
    {
        int cur = i;
        for(int j=2;j<=i;j++)
        {
            while(cur%j==0)
            {
                freq[j]++;
                cur/=j;
            }
        }
    }

    int a[6]={};

    for(int i=2;i<=n;i++)
    {
        if(freq[i]>=1) a[0]++;
        if(freq[i]>=2) a[1]++;
        if(freq[i]>=4) a[2]++;
        if(freq[i]>=14) a[3]++;
        if(freq[i]>=24) a[4]++;
        if(freq[i]>=74) a[5]++;
    }

    int ans = 0;

    if((a[2]*(a[2]-1)*(a[1]-2))/2>0) ans+=(a[2]*(a[2]-1)*(a[1]-2))/2;
    if(a[3]*(a[2]-1)>0) ans+=a[3]*(a[2]-1);
    if(a[4]*(a[1]-1)>0) ans+=a[4]*(a[1]-1);
    if(a[5]>0) ans+=1;

    cout<<ans;
   
}
