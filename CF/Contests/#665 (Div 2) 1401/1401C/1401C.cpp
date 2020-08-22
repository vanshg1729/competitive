    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define fr first
    #define sc second
     
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        //freopen("input.txt","r", stdin);
        //freopen("output.txt","w",stdout);
        int t;cin>>t;
        while(t--)
        {
            int n ; cin>>n;
            vector<ll> v1;
            vector<ll> v2;
            ll smol = INT_MAX;
            bool b = true;
            for(int i = 0;i<n;i++)
            {
                ll a; cin>>a;
                v1.push_back(a);
                v2.push_back(a);
                smol = min(smol,a);
            }
     
            sort(v2.begin(),v2.end());
     
            for(int i = n-1;i>=0;i--)
            {
                if(v2[i]==v1[i])
                {
                   continue;
                }
     
                if(v2[i]%smol or v1[i]%smol)
                {
                    b = false;
                    break;
                }
            }
     
            if(b)
            {
                cout<<"YES"<<"\n";
            }
            else
            {
                cout<<"NO"<<"\n";
            }
        }
       
     
    }   
