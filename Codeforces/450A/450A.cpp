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
    int n,m; cin>>n>>m;
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++)
    {
        int a ; cin>>a;
        q.push({a,i});
    }

    int l = 0;
    while(!q.empty())
    {
        auto b = q.front();
        if(b.first-m<=0)
        {
            q.pop();
            l = b.second;
        }
        else
        {
            q.pop();
            q.push({b.first-m,b.second});
        }
    }

    cout<<l;
}  
   



