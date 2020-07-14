#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    while(1)
    {
        int n,d,r;
        cin>>n>>d>>r;
        if(n*d*r==0) return 0;
        
        long long a[n],b[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];

        sort(a,a+n);
        sort(b,b+n);

        long long ans = 0;

        for(int i=0;i<n;i++)
        {
            if(a[i]+b[n-i-1]>d)
            {
                ans+=r*(a[i]+b[n-i-1]-d);
            }
        }

        cout<<ans<<endl;

    }
}
