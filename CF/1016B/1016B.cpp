#include <bits/stdc++.h>
using namespace std;
#define ll long long

string str(string s,int i,int j)
{
    string d ="";
    for(int k=i;k<j;k++) d+=s[k];

    return d;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    int n,m,q; cin>>n>>m>>q;
    string a ,b; cin>>a>>b;
    int dp[n+1]={};
    for(int i=0;i<n;i++)
    {
        if(i<m-1) dp[i]=0;
        else
        {
            if(i-1>=0) dp[i]=dp[i-1];
            string c = str(a,i-m+1,i+1);
            if(c==b)
            {
                dp[i]++; 
            }
        }
    }

    for(int i=0;i<q;i++)
    {
        int l ,r; cin>>l>>r;
        r--; l--;
        if(r-l+1<m) cout<<0<<endl;
        else if(l==0) cout<<dp[r]<<endl; 
        else cout<<dp[r]-dp[l+m-2]<<endl;
    } 
    
    
    //for(int i=0;i<n;i++) cout<<dp[i]<<" ";
}
