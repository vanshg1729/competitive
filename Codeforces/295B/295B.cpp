#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const ll INF = 1e14;
const int maxn = 510;
ll dis[maxn][maxn] = {};
ll adj[maxn][maxn] = {};
vector<int> order = {};
vector<ll> ans = {};
int n;

void solve(){

    for(int k = n-1; k >= 0; k--){

        int a = order[k];
        for(int i = k; i < n; i++){
            int b = order[i];
            dis[a][b] = adj[a][b];
            dis[b][a] = adj[b][a];
        }

        for(int i = n-1; i > k; i--){
           int b = order[i];
            for(int j = n-1; j > k; j--){
                int c = order[j];
                dis[a][c] = min(dis[a][c],dis[a][b] + dis[b][c]);
                dis[c][a] = min(dis[c][a], dis[c][b] + dis[b][a]);
            }
        }

        ll sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j],dis[i][a] + dis[a][j]);
                if(dis[i][j] < INF) sum+=dis[i][j];
            }
        }

        ans.push_back(sum);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dis[i][j] = INF;
            cin>>adj[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        int a; cin>>a;
        order.push_back(a);
    }

    solve();

    for(int i = n-1; i >= 0; i--) cout<<ans[i]<<" ";
}
