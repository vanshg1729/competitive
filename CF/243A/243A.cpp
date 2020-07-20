#include <bits/stdc++.h>
#include<set>
using namespace std;
#define ll long long

const int maxn = pow(10,6)+10;
ll p[maxn]={};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    int n; cin>>n;
    int a[n+10]={};
    for(int i=1;i<=n;i++) cin>>a[i];
    
    set<int> pre[n+1]={};
    set<int> ans ;

    for(int i=1;i<=n;i++)
    {
        for(auto x:pre[i-1])
        {
            int d = x;
            int c = d|a[i];
            ans.insert(c);
            pre[i].insert(c);
        }

        pre[i].insert(a[i]);
        ans.insert(a[i]);
    }

    cout<<ans.size();
}    
   
