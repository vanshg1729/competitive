/* https://atcoder.jp/contests/abc131/tasks/abc131_f */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = 200010;
bool seen[maxn] = {};
vector<pair<int,int>> v;
vector<int> adj[maxn] = {};
int n;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    ll ans = 0;

    for(int i = 1; i <= n; i++){
        int a,b; cin>>a>>b;
        int c = 1e5 + b;
        adj[a].push_back(c);
        adj[c].push_back(a);
        v.push_back({a,c});
    }

    for(int i = 0; i < n; i++){
        if(seen[v[i].fr] == 1) continue;
        
        ll row = 0,col = 0;
        seen[v[i].fr] = 1;
        stack<int> q;
        q.push(v[i].fr);
        while(!q.empty()){
            auto b = q.top();
            q.pop();
            if(b <= 1e5) row++;
            else col++;

            for(auto u : adj[b]){

                if(seen[u]) continue;
                seen[u] = 1;
                q.push(u);
            }
        }

        ans += row*col; 
    }

    cout<<ans-(ll)n;
}
