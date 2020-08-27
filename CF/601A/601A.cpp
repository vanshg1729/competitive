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
    int mat[n+1][n+1] = {};
    for(int i = 1;i<=m;i++)
    {
    	int a,b; cin>>a>>b;
    	mat[a][b] = 1;
    	mat[b][a] = 1;
    }

    int a = 0;
    if(mat[1][n] == 0) a = 1;

    bool seen[n+1] = {};
    int dis[n+1] = {};
    queue<int> q;
    seen[1] = true;
    q.push(1);
    while(!q.empty())
    {
    	int b = q.front();
    	q.pop();
        
        for(int i = 1;i<=n;i++)
        {
        	if(mat[b][i]!=a or seen[i]) continue;
        	seen[i] = true;
        	q.push(i);
        	dis[i] = dis[b]+1;

        }
    }

    if(seen[n]) cout<<dis[n];
    else cout<<-1;
}
