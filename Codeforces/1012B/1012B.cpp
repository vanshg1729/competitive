#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = 500000;
vector<int> adj[maxn] = {};
bool seen[maxn] = {};
int n,m,q;

void dfs(int s){
    seen[s] = true;
    for(auto u : adj[s]){
        if(seen[u]) continue;
        seen[u] = true;
        dfs(u);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>q;

    for(int i = 1; i <= q; i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(n+b);
        adj[n+b].push_back(a);
    }

    int ans = 0;
    for(int i = 1; i <= n+m; i++){
        if(seen[i]) continue;
        dfs(i);
        ans++;
    }

    cout<<ans-1;
}
