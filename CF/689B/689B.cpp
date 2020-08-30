#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    int n; cin>>n;
    vector<int> adj[n+1] = {};
    
    for(int i = 1;i<=n;i++)
    {
        int a; cin>>a;
        if(i+1<=n) adj[i].push_back(i+1);
        if(i-1>=1) adj[i].push_back(i-1);
        if(a!=i+1 or a!=i-1) adj[i].push_back(a);
    }

    int dis[n+1] = {};
    bool seen[n+1] = {};

    seen[1] = true;

    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int b = q.front();
        q.pop();

        for(auto u : adj[b])
        {
            if(seen[u]) continue;

            seen[u] = true;
            q.push(u);
            dis[u] = dis[b]+1;
        }
    }

    for(int i = 1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
}
