    #include<bits/stdc++.h>
    using namespace std;
     
    #define sc second;
    #define fr first;
    int main()
    {
       //freopen("input.txt","r",stdin);
       //freopen("output.txt","w",stdout);
       int n; cin>>n;
       int a[n+2]={};
       char c ;
       for(int i = 1;i<=n;i++) cin>>a[i];
     
       int p[n+1]={};
       for(int i=1;i<n;i++)
       {
          p[i]  = p[i-1];
          cin>>c;
          if(c=='0') p[i]++;
       }
       bool ans = true;
     
       for(int i=1;i<=n;i++)
       {
       	 if(a[i]>i)
       	 {
             if(p[a[i]-1]-p[i-1])
             {
             	 ans = false;
             	 break;
             }
       	 }
       }
     
       if(ans) cout<<"YES";
       else cout<<"NO";
    }
