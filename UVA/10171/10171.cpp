#include <bits/stdc++.h>
using namespace std;
#define fr first
#define ll long long
#define sc second
#define pii pair<int,int>

const int maxn = 40;
const int INF = 1e9;

void solve(vector<pair<int,int>> v[],vector<int> & dis,int s){

    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push({0,s});
    dis[s] = 0;

    while(!q.empty()){
        auto b = q.top();
        q.pop();

        if(b.fr != dis[b.sc]) continue;

        for(auto u : v[b.sc]){
            int d = b.fr + u.sc;

            if( d < dis[u.fr]){
                dis[u.fr] = d;
                q.push({d,u.fr});
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

    int m;
    while(cin>>m){

        if(m == 0) break;
        vector<pair<int,int>> adj[40] = {};
        vector<pair<int,int>> mat[40] = {};
        vector<int> dis1(40,INF),dis2(40,INF);

        for(int i = 1; i <= m; i++){
            char age,dir,A,B;
            int cost;
            cin>>age>>dir>>A>>B>>cost;
            int a = A-'A'+1,b = B - 'A' +1;

            if(age == 'Y'){
                adj[a].push_back({b,cost});
                if(dir == 'B') adj[b].push_back({a,cost});
            }
            else
            {
                mat[a].push_back({b,cost});
                if(dir == 'B') mat[b].push_back({a,cost});
            }
        }

        char a,b; cin>>a>>b;
        int st = a - 'A' +1 , en = b - 'A' + 1;

        solve(adj,dis1,st);
        solve(mat,dis2,en);

        int ans = INF, place = -1;

        for(int i = 1; i <= 26; i++){
            if(dis1[i] == INF or dis2[i] == INF) continue;
            ans = min(ans,dis1[i] + dis2[i]);
        }

        vector<int> poss = {};
        for(int i = 1; i <= 26; i++){
            if(dis1[i] == INF or dis2[i] == INF) continue;
            if(ans == dis2[i] + dis1[i]) poss.push_back(i-1);
        }

        sort(poss.begin(),poss.end());

        if(ans == INF){
            cout<<"You will never meet."<<"\n";
        }
        else
        {
            cout<<ans<<" ";
            for(int i = 0; i < poss.size();i++){
                char c = 'A' + poss[i];
                cout<<c;
                if(i != poss.size()-1) cout<<" ";
            }
            cout<<"\n";
        }
    }
}
