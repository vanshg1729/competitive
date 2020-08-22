    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define fr first
    #define sc second
    ll mod = pow(10,9)+7;
     
     
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
            int n,m; cin>>n;
            vector<int> adj[n+1] = {};
            int par[n+1] = {};
     
            int dis[n+1] = {};
            vector<int> lvl[n+1] = {};
            ll child[n+1] = {};
     
            vector<ll> factor = {};
            vector<ll> edge= {};
            bool seen[n+1] = {};
     
            ll ans = 0;
     
            for(int i = 1;i<n;i++)
            {
                int a,b; cin>>a>>b;
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
     
            cin>>m;
            for(int i = 1;i<=m;i++) 
            {
                ll a; cin>>a;
                factor.push_back(a);
            }
     
            for(int i = m;i<n-1;i++)
            {
                factor.push_back(1);
            }
     
            sort(factor.begin(),factor.end());
     
            while(factor.size()>n-1)
            {
               ll b = factor.back();
               factor.pop_back();
               factor.back()*=b;
               factor.back()%=mod;
            }
            
            dis[1] = 0;
            lvl[0].push_back(1);
     
            stack<int> s; s.push(1);
            seen[1] = true;
     
            //dfs
     
            while(!s.empty())
            {
                int b = s.top();
                s.pop();
                
                for(auto u:adj[b])
                {
                    if(seen[u]) continue;
     
                    dis[u] = dis[b]+1;
                    par[u] = b;
                    s.push(u);
                    seen[u] = true;
                    lvl[dis[u]].push_back(u);
                }
            }
     
            //dfs
            
            for(int i = n-1;i>=1;i--)
            {
                for(auto u :lvl[i])
                {
                    child[u]++;
                    child[par[u]]+=child[u];
                    ll a = child[u]*(n-child[u]);
                    edge.push_back(a);
                }
            }
            
            sort(edge.begin(),edge.end());
            
            for(int i = 0;i<n-1;i++)
            {
               ll b = factor[i]*edge[i];
               b%=mod;
               ans+=b;
               ans%=mod;
            }
     
            cout<<ans<<endl;
        }
    }   
     
