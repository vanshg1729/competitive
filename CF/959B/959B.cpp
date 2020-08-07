#include <bits/stdc++.h>
using namespace std;
int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n,k,m;
   cin>>n>>k>>m;

   map<string,int> word;
   long long price[n+2]={};
   long long cost[k+1]={};
   long long group[n+1]={};
   long long ans = 0;

   for(int i=1;i<=n;i++)
   {
       string a; cin>>a;
       word[a] = i;
   }

   for(int i=1;i<=n;i++) cin>>price[i];

   for(int i=1;i<=k;i++)
   {
   	  cost[i] = LLONG_MAX;
   	  long long size; cin>>size;
      long long num;

      for(int j=1;j<=size;j++)
      {
      	 cin>>num; 
      	 group[num] = i;
      	 cost[i] = min(cost[i],price[num]);
      }
   }

   for(int i=1;i<=m;i++)
   {
   	 string a; cin>>a;
   	 ans+=cost[group[word[a]]];
   }

   cout<<ans;

}	
