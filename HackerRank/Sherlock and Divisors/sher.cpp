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
        int n ; cin>>n;
        int ans = 0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                if(i%2==0) ans++;
            }
            if(n/i!=i and n%i==0)
            {
                if((n/i)%2==0) ans++;
            }
        }

        cout<<ans<<endl;
    }
}
