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
       	 int a[n+1] = {};
       	 for(int i=1;i<=n;i++) cin>>a[i];
     
       	 int i = a[1];
       	 int j = a[2];
       	 int k = a[n];
       	 bool ans = false;
       	 if(i+j<=k) ans = true;
       	 else if(k-i>=j) ans = true;
     
       	 if(ans) 
       	 {
       	 	cout<<1<<" "<<2<<" "<<n<<"\n";
       	 }
       	 else
       	 {
       	 	 cout<<-1<<"\n";
       	 }
       }
    }
