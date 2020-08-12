#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
   cin.tie(0);
   cout.tie(0);
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n,q,c; cin>>n>>q>>c;
   vector<int> a[110][110] = {};
   int p[c+10][110][110]={};
   for(int i = 1;i<=n;i++)
   {
   	 int x,y,s; cin>>x>>y>>s;
     a[x][y].push_back(s);
   }
 
   for(int k = 0;k<=c;k++)
   {
   	 for(int i=1;i<=100;i++)
   	 {
   	 	for(int j =1;j<=100;j++)
   	 	{
   	 		p[k][i][j] = p[k][i-1][j]+p[k][i][j-1] -p[k][i-1][j-1];
   	 		for(int l = 0;l<a[i][j].size();l++)
   	 		{
   	 			p[k][i][j]+= ((a[i][j][l]+k)%(c+1));
   	 		}
   	 	}
   	 }
   }
   
   for(int i = 1;i<=q;i++)
   {
   	  int t,x1,y1,x2,y2; 
   	  cin>>t>>x1>>y1>>x2>>y2;
   	  t%=(c+1);
   	  int ans = p[t][x2][y2] - p[t][x1-1][y2] - p[t][x2][y1-1] + p[t][x1-1][y1-1];
   	  cout<<ans<<"\n";
   } 
  
 
}    
