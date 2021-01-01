#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second 


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n; cin>>n;
    vector<int> adj[2*n+10] = {};
    vector<pair<int,int>> v = {};
    int seen[2*n+10] = {};
    int p[2*n+10] = {};

    memset(seen,-1,sizeof(seen));
    for(int i = 1; i <= n; i++){
        int a,b; cin>>a>>b;
        p[a] = b,p[b] = a;
        v.push_back({a,b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= 2*n; i+=2){
        if(p[i] == i+1) continue;
        adj[i].push_back(i+1);
        adj[i+1].push_back(i);
    }

    for(int i = 1; i <= 2*n; i++){
        if(seen[i] != -1) continue;

        seen[i] = 0;
        stack<int> q;
        q.push(i);

        while(!q.empty()){
            auto b = q.top();
            q.pop();

            for(auto u : adj[b]){
                if(seen[u] == -1){
                    seen[u] = seen[b]^1;
                    q.push(u);
                }
            }
        }
    }

    for(auto u : v){
        cout<<seen[u.fr]+1<<" "<<seen[u.sc]+1<<"\n";
    }

}
