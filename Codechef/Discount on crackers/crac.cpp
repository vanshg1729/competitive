#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = 40;
int dis[maxn][maxn] = {};
int m,p;

void solve(){

    int n = 26;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dis[i][j] |= dis[i][k] && dis[k][j];
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

    cin>>p;

    while(p--){

        string s,t;
        cin>>s>>t>>m;

        memset(dis,0,sizeof(dis));
        for(int i = 1; i <= m; i++){
            char a,gar,b;
            cin>>a>>gar>>gar>>b;

            int j = a-'a', k = b-'a';
            dis[j][k] = 1;
        }

        if(s.size() != t.size()){
            cout<<"NO"<<"\n";
            continue;
        }

        solve();

        bool ans = true;
        for(int i = 0; i < s.size(); i++){
            
            int j = s[i] - 'a';
            int k = t[i] - 'a';

            if(j == k) continue;
            if(dis[j][k] == 0){
                ans = false;
                break;
            }
        }

        if(ans) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}
