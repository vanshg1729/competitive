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
        int n,s; cin>>n>>s;
        if(n>=s)
        {
            cout<<s<<endl; continue;
        }

        long long a = s/n;
        long long b = s%n;
        long long ans = b*(a+1)*(a+1)+(n-b)*a*a;
        cout<<ans<<endl;
    }
}
