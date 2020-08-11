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
    	int n,m; cin>>n>>m;
    	int ans = 0;
    	char a[n+10][m+10]={};
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=1;j<=m;j++)
    		{
    			cin>>a[i][j];
    			if(a[i][j]=='R')
    			{
    				if(j+1>m) ans++;
    			}
    			else if(a[i][j]=='D')
    			{
    				if(i+1>n) ans++;
    			}
    		}
    	}
 
    	cout<<ans<<endl;
    
    }
}   
