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
       	 string s ; cin>>s;
       	 int n = s.size();
       	 s+='0';
       	 int a[n+1]={};
       	 vector<int> v ={};
       	 if(s[0]=='1') a[0] = 1;
     
       	 for(int i =1;i<=n;i++ )
       	 {
       	 	 if(s[i]=='0')
       	 	 {
       	 	 	a[i] = 0;
       	 	 }
       	 	 else
       	 	 {
       	 	 	a[i] = 1;
       	 	 	if(s[i-1]=='1') a[i]+=a[i-1];
       	 	 }
     
       	 	 if(s[i]=='0' and s[i-1]=='1')
       	 	 {
                 v.push_back(a[i-1]);
       	 	 } 
       	 }
     
       	 sort(v.begin(),v.end());
     
       	 int ans = 0;
       	 for(int i=v.size()-1;i>=0;i-=2)
       	 {
             ans+=v[i];
       	 }
     
       	 cout<<ans<<"\n";
     
       	 
       }
    }
