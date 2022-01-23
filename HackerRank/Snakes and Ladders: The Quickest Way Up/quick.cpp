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
    int t; cin>>t;
    while(t--)
    {
        int maxn = 101;
        vector<int> adj[maxn] = {};
        
        int n; cin>>n;
        for(int i = 1;i<=n;i++)
        {
            int a,b; cin>>a>>b;
            adj[a].push_back(b);
        }
        
        int m ; cin>>m;

        for(int i = 1;i<=m;i++)
        {
            int a,b; cin>>a>>b;
            adj[a].push_back(b);
        }
        
        bool seen[maxn] = {};
        int dis[maxn] = {};

        queue<int> q;
        seen[1] = true;
        q.push(1);
        while(!q.empty())
        {
            int b = q.front();
            q.pop();

            for(auto u : adj[b])
            {
                if(seen[u]) continue;
                dis[u] = dis[b];
                seen[u] = true;
                q.push(u);
            }

            if(adj[b].size()>=1) continue;

            for(int i = 1;i<=6;i++)
            {
                if(i+b>100 or seen[i+b]) continue;
                seen[i+b] = true;
                dis[i+b] = dis[b]+1;
                q.push(i+b);
            }
        }

        if(seen[100]) cout<<dis[100]<<"\n";
        else cout<<-1<<"\n";
    }

}   
