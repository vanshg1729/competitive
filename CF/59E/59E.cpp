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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> adj[n+1] = {};
    set<tuple<int,int,int > > s = {};
    for(int i = 1;i<=m;i++)
    {
    	int a,b; cin>>a>>b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    for(int i = 1;i<=k;i++)
    {
    	int a,b,c ; cin>>a>>b>>c;
    	s.insert({a,b,c});
    }
    
    int ans = -1;
    pair<int,int> state = {1,0};
    bool seen[n+1][n+1] = {};
    int dis[n+1][n+1] = {};
    pair<int,int> par[n+1][n+1] = {};

    queue<pair<int,int> > q;
    q.push({1,0});
    seen[1][0] = true;
    while(!q.empty())
    {
    	auto b = q.front();
    	q.pop();

    	for(auto u : adj[b.fr])
    	{
    		if(seen[u][b.fr]) continue;
            
            if(s.count({b.sc,b.fr,u})) continue;

            seen[u][b.fr] = true;
            dis[u][b.fr] = dis[b.fr][b.sc]+1;
            par[u][b.fr] = b;
            q.push({u,b.fr});

            if(ans == -1 and u ==n)
            {
            	ans = dis[u][b.fr];
            	state = {u,b.fr};
            	continue;
            }

            if(dis[u][b.fr]<ans and u == n)
            {
            	ans = dis[u][b.fr];
            	state = {u,b.fr};
            }
    	}
    }

    cout<<ans<<"\n";
    vector<int> v;

    pair<int,int> ini = {1,0};
    while(state != ini)
    {
    	v.push_back(state.fr);
    	state = par[state.fr][state.sc];
    }

    if(ans!=-1) v.push_back(1);

    for(int i = v.size()-1;i>=0;i--)
    {
    	cout<<v[i]<<" ";
    }
}
