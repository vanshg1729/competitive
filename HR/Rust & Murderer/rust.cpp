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
        int n,m; cin>>n>>m;
        
        vector<int> adj[n+1] = {};

        for(int i = 1;i<=m;i++)
        {
            int x,y; cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int s; cin>>s;

        bool seen[n+1] = {};

        int dis[n+1] = {};

        set<int> l1,l2;

        for(int i = 1;i<=n;i++)
        {
            if(i==s) continue;

            l1.insert(i);
        }
        
        seen[s] = true;
        queue<int> q; q.push(s);

        while(!q.empty())
        {
            int b = q.front(); q.pop();

            vector<int> v1 = {}, v2 = {};

            for(auto u : adj[b])
            {
                if(seen[u]) continue;

                l1.erase(u);
                l2.insert(u);
            }
    
            for(auto u : l1)
            {
                seen[u] = true;
                dis[u] = dis[b]+1;
                q.push(u);
            }
            
            for(auto u : l1)
            {
                v1.push_back(u);
            }

            for(auto u : v1) l1.erase(u);

            for(auto u : l2) v2.push_back(u);

            for(auto u : v2)
            {
                l1.insert(u);
                l2.erase(u);
            }
        }

        for(int i = 1;i<=n;i++)
        {
            if(i==s) continue;

            cout<<dis[i]<<" ";
        }     

        cout<<"\n";
    }
}
