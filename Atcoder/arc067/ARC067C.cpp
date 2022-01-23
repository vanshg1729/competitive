#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    int m = pow(10,9)+7;
    long long n; cin>>n;
    long long freq[n+1]={};
    
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

    long long ans = 1;

    for(int i=2;i<=n;i++)
    {
        ans*=(freq[i]+1);
        ans%=m;
    }
    
    cout<<ans;

    //for(int i=1;i<=n;i++) cout<<freq[i]<<endl;
}
