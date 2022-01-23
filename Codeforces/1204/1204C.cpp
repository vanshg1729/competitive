#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define ll long long

const int INF = 1e9;
const int maxn = 110;
const int maxm = 1e6 + 10;
int dp[maxm] = {},p[maxm] = {},n;
int dis[maxn][maxn] = {},m;
vector<int> v = {};

void solve(){

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dis[i][k] == INF or dis[k][j] == INF) continue;
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
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

    cin>>n;
    for(int i = 1; i <= n; i++){   
        for(int j = 1; j <= n; j++){
            char c ; cin>>c;
            dis[i][j] = c - '0';
            if(!dis[i][j]) dis[i][j] = INF;
        }
    }

    solve();
    
    cin>>m;
    v.push_back(0);
    for(int i = 1; i <= m; i++){
        int a; cin>>a;
        v.push_back(a);
    }

    for(int i = 1; i <= m; i++) dp[i] = INF;
    dp[1] = 1; dp[0] = 0;

    for(int i = 2; i <= m; i++){
        for(int j = i-1; j > max(0,i-n-10); j--){
            
            if(dis[v[j]][v[i]] != i-j or v[i] == v[j]) continue;
            
            if(dp[j] + 1 < dp[i]){
                dp[i] = dp[j] + 1;
                p[i] = j;
            }
        }
    }

    vector<int> ans = {};
    int i = m;
    while(i){
        ans.push_back(v[i]);
        i = p[i];
    }

    cout<<ans.size()<<"\n";
    for(int i = ans.size()-1; i >= 0; i--) cout<<ans[i]<<" ";
}
