#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = pow(10,5)+1;

vector<int> adj[maxn] = {};
bool seen[maxn][2] = {};
pair<int,int> parent[maxn][2] = {};
bool visiting[maxn][2] = {};
bool win = 0, draw = 0;
pair<int,int> last_node;

void dfs(int i, int par)
{

	if(seen[i][par]) return;
    
    if(visiting[i][par] or visiting[i][par^1])
    {
    	draw = true;
    }
    
    if(visiting[i][par]) return;
    if(win) return;

    visiting[i][par] = true;

    for(auto u:adj[i])
    {
       if(visiting[u][par^1])
       {
       	 draw = true; continue;
       }

       if(seen[u][par^1]) continue;
       parent[u][par^1] = {i,par};

       if(par^1==1 and adj[u].size()==0)
       {
       	  last_node = {u,1};
       	  win = true;
       	  return;
       }
       
       dfs(u,par^1);
    }
    
    visiting[i][par] = false; 
    seen[i][par] = true;
}

int main()
{
   cin.tie(0);
   cout.tie(0);
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n,m; cin>>n>>m;
   stack<int> path = {};

   for(int i=1;i<=n;i++)
   {
   	 cin>>m;
   	 for(int j = 1;j<=m;j++)
   	 {
   	 	int a; cin>>a;
   	 	adj[i].push_back(a);
   	 }
   }
   
   int node ; cin>>node;
   dfs(node,0);
   
   if(win)
   {
   	  int par = 1;
   	 pair<int,int> b = {node,0};
      while(last_node!= b)
      {
      	 path.push(last_node.first);
      	 last_node = parent[last_node.first][par];
      	 par^=1;
      }
      path.push(node);

      cout<<"Win"<<"\n";
      while(!path.empty())
      {
      	cout<<path.top()<<" ";
      	path.pop();
      }
   }
   else if(draw) cout<<"Draw"<<"\n";
   else cout<<"Lose"<<"\n";
  
}    
