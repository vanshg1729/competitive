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

    int n,m; cin>>n>>m;
    vector<int> adj[n+1] = {};
    for(int i = 1;i<=m;i++)
    {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool state[n+1][n+1] = {};
    pair<int,int> par[n+1][n+1] ={};

    queue<pair<int,int> > q ;
    q.push({1,n});
    state[1][n] = true;

    par[1][n] = {0,0};

    while(!q.empty())
    {
        int x = q.front().fr; int y = q.front().sc;
        q.pop();

        for(auto a : adj[x])
        {
            for(auto b : adj[y])
            {
                if(a==b or state[a][b]) continue;

                state[a][b] = true;
                
                par[a][b] = {x,y};
                q.push({a,b});
            }
        }
    }

    if(!state[n][1])
    {
        cout<<-1 ;
        return 0 ;
    }

    vector<int> v1,v2;
    int x = n, y = 1;

    while(x or y)
    {
        v1.push_back(x);
        v2.push_back(y);
        int b = par[x][y].fr;
        y = par[x][y].sc;
        x = b;
    }

    cout<<v1.size()-1<<"\n";

    for(int i = v1.size()-1;i>=0;i--)
    {
        cout<<v1[i]<<" ";
    }

    cout<<"\n";

    for(int i = v2.size()-1;i>=0;i--)
    {
        cout<<v2[i]<<" ";
    }
}
