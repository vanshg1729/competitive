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
        int n,m; cin>>n>>m;
        if(n==0 and m==0) return 0;

        long long a[n],b[m];
        long long ans = 0;
        bool t = true;

        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
        
        sort(a,a+n);
        sort(b,b+m);
        
        int i=0,j=0;

        while(i<n and j<m)
        {
            if(a[i]<=b[j])
            {
                ans+=b[j];
                i++; j++;
            }
            else
            {
                j++;
            }

            if(j==m and i<n) t=false;
        }
        
        if(!t) cout<<"Loowater is doomed!"<<endl;
        else cout<<ans<<endl;
    }
}
