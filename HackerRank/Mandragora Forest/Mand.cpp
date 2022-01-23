#include <bits/stdc++.h>
using namespace std;

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
        long long a[n]={},s[n]={};
        long long ans =0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        sort(a,a+n);
        s[n-1]=a[n-1];

        for(int i=n-2;i>=0;i--) s[i]=a[i]+s[i+1];

        for(int i=n-1;i>=0;i--)
        {
            ans = max(ans,(i+1)*s[i]);
        }

        cout<<ans<<endl;
    }
}
