    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
     
     
    int main()
    {
       cin.tie(0);
       cout.tie(0);
       //freopen("input.txt","r",stdin);
       //freopen("output.txt","w",stdout);
       int t; cin>>t;
       while(t--)
       {
         int n; cin>>n;
        
         string s; cin>>s;
         
         map<long long,long long> m;
     
         long long a[n+1]={};
         long long p[n+1]={};
     
         for(int i=1;i<=n;i++)
         {
     
           a[i] = s[i-1]-'0';
     
           p[i] = p[i-1]+a[i];
           m[p[i]-i]+=1;
         }
     
         long long ans = m[0];
     
         for(auto u:m)
         {
         	ans += ((u.second)*(u.second-1))/2;
         }
     
         cout<<ans<<"\n";
       }
    }
