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
        string s; cin>>s;
        int n = s.size();
        int a[n]={};
        for(int i=0;i<n;i++)
        {
            if(s[i]=='{') a[i]=1;
            if(s[i]=='}') a[i]=-1;
            if(s[i]=='(') a[i]=2;
            if(s[i]==')') a[i]=-2;
            if(s[i]=='[') a[i]=3;
            if(s[i]==']') a[i]=-3;
        }

        stack<int> q;
        q.push(0);
        bool b = true;
        for(int i =0;i<n;i++)
        {
           if(a[i]>0) q.push(a[i]);
           else if(a[i]+q.top()==0) q.pop();
           else
           {
             b = false; break;
           }
        }

        if(b and q.size()==1) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}  
   
