#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = 100010;
vector<int> adj[maxn] = {};

bool bus(int n,int m)
{
    if(m!=(n-1)) return false;
    int one = 0;
    for(int i = 1;i<=n;i++)
    {
        if(adj[i].size()>2) return false;
        if(adj[i].size()==1) one++;
    }

    if(one==2) return true;
    else return false;
}

bool ring(int n,int m)
{
    if(m!=n) return false;
    for(int i = 1;i<=n;i++)
    {
        if(adj[i].size()!=2)
        {
            return false;
        }
    }

    return true;
}

bool star(int n, int m)
{
    if(m!=(n-1)) return false;
    for(int i = 1;i<=n;i++)
    {
        if(adj[i].size()==m)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    int n,m; cin>>n>>m;

    for(int i = 1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(bus(n,m)) cout<<"bus topology";
    else if(ring(n,m)) cout<<"ring topology";
    else if(star(n,m)) cout<< "star topology";
    else cout<<"unknown topology";

}   

