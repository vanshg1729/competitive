#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc second
#define fr first

struct edge
{
    int a,b,cost;    
};
const int maxn = 110;
const int INF = INT_MAX;
vector<edge> adj = {},mat = {};
vector<int> dis(maxn,0);
int n ,m;

void solve(vector<edge> e){

    dis.assign(maxn,INF);
    dis[0] = 0;
    bool x = 1;

    for(int i = 1; i < n; i++){

        for(auto u : e){
            if(dis[u.a] == INF) continue;

            if(dis[u.a] + u.cost < dis[u.b]){
                dis[u.b] = max(-INF,dis[u.a] + u.cost);
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        adj.push_back({i,i+1,1});
        adj.push_back({i+1,i,0});
        mat.push_back({i,i+1,1});
        mat.push_back({i+1,i,0});
    }

    for(int i = 1; i <= m; i++){

        int a,b,c; cin>>a>>b>>c;
        int d = b-a+1-c;

        adj.push_back({a-1,b,c});
        adj.push_back({b,a-1,-c});
        mat.push_back({a-1,b,d});
        mat.push_back({b,a-1,-d});
    }

    solve(adj);
    int ma = dis[n];
    solve(mat);
    int mi = n - dis[n];

    cout<<mi<<" "<<ma;
}
