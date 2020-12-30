#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int INF = 1e9;
int dis[15][15] = {};
int h,w;

void solve(){
    
    for(int k = 0; k <= 9; k++){
        for(int i = 0; i <= 9; i++){
            for(int j = 0; j <= 9; j++){
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

    cin>>h>>w;

    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            cin>>dis[i][j];
        }
    }

    solve();

    ll ans = 0;

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            int a ; cin>>a;

            if(a == -1) continue;
            ans += (ll)dis[a][1];
        }
    }

    cout<<ans;
}
