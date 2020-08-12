    #include<bits/stdc++.h>
    using namespace std;
     
    #define sc second;
    #define fr first;
    int main()
    {
       //freopen("input.txt","r",stdin);
       //freopen("output.txt","w",stdout);
       int n,m;
       cin>>n>>m;
       char a[n+1][m+1]={};
       int p[n+1][m+1]={};
       for(int i=1;i<=n;i++)
       {
     
       	 for(int j = 1;j<=m;j++)
       	 {
       	 	cin>>a[i][j];
       	 	p[i][j] = p[i-1][j]+p[i][j-1]-p[i-1][j-1]+(a[i][j]-'0');
       	 	//cout<<p[i][j]<<" ";
       	 }
     
       }
     
       int ans = 0;
       for(int x1 = 1;x1<=n;x1++)
       {
       	 for(int y1= 1;y1<=m;y1++)
       	 {
       	 	for(int x2 = x1;x2<=n;x2++)
       	 	{
       	 		for(int y2 = y1; y2<=m;y2++)
       	 		{
       	 			if(p[x2][y2]-p[x1-1][y2] - p[x2][y1-1]+p[x1-1][y1-1]==0)
       	 			{
       	 				ans = max(ans,2*(x2-x1+1)+2*(y2-y1+1));
       	 			}
       	 		}
       	 	}
       	 }
       }
     
       cout<<ans;
    }
