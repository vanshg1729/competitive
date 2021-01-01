#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = 110;
vector<pair<int,int>> adj[maxn][maxn] = {};
vector<pair<int,int>> v = {};
int seen[maxn][maxn] = {};
int n,m;
bool bipap = true;

void edge(pair<int,int> p1, pair<int,int> p2){

    if(p1.fr == p2.fr or p1.sc == p2.sc) return;
    pair<int,int> p3;
    if(p1.fr > p2.fr){
        p3 = p2; p2 = p1;
        p1 = p3;
    }

    int d1 = p2.fr - p1.fr;
    int d2 = p1.sc - p1.fr;
    int d3 = p2.sc - p1.fr;

    if(d2 > d1 and d3 > d2){
        adj[p1.fr][p1.sc].push_back(p2);
        adj[p2.fr][p2.sc].push_back(p1);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;

    memset(seen,-1,sizeof(seen));
    for(int i = 1; i <=m ; i++){
        int a,b; cin>>a>>b;

        int c = min(a,b),d = max(a,b);
        v.push_back({c,d});
    }

    for(int i = 0; i <m; i++){
        for(int j = i+1; j <m; j++){
            edge(v[i],v[j]);
        }
    }

    for(auto u : v){

        if(seen[u.fr][u.sc] != -1) continue;
        seen[u.fr][u.sc] = 0;
        
        stack<pair<int,int> > q;
        q.push({u.fr,u.sc});

        while(!q.empty()){
            auto b = q.top();
            q.pop();

            for(auto j : adj[b.fr][b.sc]){

                if(seen[j.fr][j.sc] == -1){
                    seen[j.fr][j.sc] = seen[b.fr][b.sc]^1;
                    q.push(j);
                }
                else{
                    bipap &= (seen[j.fr][j.sc] != seen[b.fr][b.sc]); 
                }
            }
        }        
    }

    if(!bipap) cout<<"Impossible"<<"\n";
    else{
        for(auto u : v){
            if(seen[u.fr][u.sc] == 0) cout<<"o";
            else cout<<"i";
        }
    }
}
