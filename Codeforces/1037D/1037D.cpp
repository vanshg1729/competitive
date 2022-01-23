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
    set<int> adj[n+1] = {};
    for(int i =1;i<n;i++)
    {
    	int a ,b; cin>>a>>b;
    	adj[a].insert(b);
    	adj[b].insert(a);
    }

    int a[n+1] = {};
    for(int i = 1;i<=n;i++) cin>>a[i];

    int i = 2;
    bool ans = true;
    if(a[1]!=1) ans = false;
    queue<int> q;
    q.push(a[1]);
    while(!q.empty() and i<=n and ans)
    {
    	int b = q.front();
    	q.pop();

    	while(adj[b].count(a[i]))
    	{
           q.push(a[i]);
           adj[b].erase(a[i]);
           adj[a[i]].erase(b);
           i++;
    	}

    	if(adj[b].size()>0) ans = false;

    }

    if(ans) cout<<"Yes";
    else cout<<"No";
}
