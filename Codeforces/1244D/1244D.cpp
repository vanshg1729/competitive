#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
int root = 0;
const int maxn = pow(10,5)+10;
vector<int> adj[maxn] = {};

bool nbus(int n)
{
	for(int i = 1;i<=n;i++)
	{
		if(adj[i].size()>2) 
		{
			return true;
		}

		if(adj[i].size()==1)
		{
			root = i;
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
     
     int n; cin>>n;
     int c = 4;
     long long color[n+1][4] = {};
     long long group[c][c] = {};

     for(int i = 0;i<3;i++)
     {
     	for(int j = 1;j<=n;j++)
     	{
     		cin>>color[j][i];
     	}

     }

     for(int i = 1;i<n;i++)
     {
     	int a,b; cin>>a>>b;
     	adj[a].push_back(b);
     	adj[b].push_back(a);
     }
     
     if(nbus(n))
     {
     	cout<<-1;
     	return 0 ;
     }

     int dis[n+1] = {};
     int seen[n+1] = {};

     seen[root] = 1;
     queue<int> q;
     q.push(root);

     while(!q.empty())
     {
     	int b = q.front();
     	q.pop();

     	group[dis[b]][0]+=color[b][0];
        group[dis[b]][1]+=color[b][1];
     	group[dis[b]][2]+=color[b][2];

     	for(auto u :adj[b])
     	{
     		if(seen[u]) continue;
     		q.push(u);
     		seen[u] = 1;
     		dis[u] = dis[b]+1;
     		dis[u]%=3;
     	}
     }

     vector<int> v = {0,1,2};
     long long ans = LLONG_MAX;
     int one = 0, two = 0, three = 0;

     do
     {
     	long long k = group[0][v[0]]+group[1][v[1]]+group[2][v[2]];
        if(k<ans)
        {
        	one = v[0];
        	two = v[1];
        	three = v[2];
        	ans = min(ans,k);
        }

     } while(next_permutation(v.begin(),v.end()));
      
     cout<<ans<<"\n";

     for(int i = 1;i<=n;i++)
     {
     	if(dis[i] == 0)
     	{
     		cout<<one+1<<" ";
     	}
     	else if(dis[i] == 1)
     	{
     		cout<<two+1<<" ";
     	}
     	else
     	{
     		cout<<three+1<<" ";
     	}
     }
 }   
