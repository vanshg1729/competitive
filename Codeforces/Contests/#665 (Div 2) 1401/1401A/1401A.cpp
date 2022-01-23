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
            int n,k;
            cin>>n>>k;
            if(k>n) cout<<(k-n)<<"\n";
            else if((k+n)%2) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
    }
