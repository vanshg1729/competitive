#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc second
#define fr first

const ll INF = 1e14;
const int maxn = 310;
ll dis[maxn][maxn] = {};
int n,k;

ll solve(int a , int b , ll c){
    ll ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dis[i][j] = min(dis[i][j] , c +
                min(dis[i][a] + dis[b][j],dis[i][b] + dis[a][j]) );
            ans+= dis[i][j];
        }
    }
    ans/=2;
    return ans;
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
            cin>>dis[i][j];
        }
    }

    cin>>k; 

    for(int i = 1; i <= k ; i++){
        int a, b;
        ll c; cin>>a>>b>>c;

        cout<<solve(a,b,c)<<" ";
    }
}
