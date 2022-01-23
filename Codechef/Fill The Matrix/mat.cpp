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

    int T;
    cin>>T;
    while(T--){
        
        int n,q; cin>>n>>q;
        vector<pair<int,int>> adj[n+10] = {};
        int seen[n+10] = {};
        memset(seen,-1,sizeof(seen));
        bool check = true;

        for(int i = 1; i <= q; i++){
            int a,b,c; cin>>a>>b>>c;
            adj[a].push_back({b,c});
        }

        for(int i = 1; i <= n; i++){
            if(seen[i] != -1) continue;

            seen[i] = 0;
            stack<int> s; s.push(i);

            while(!s.empty()){
                int b = s.top();
                s.pop();

                for(auto u : adj[b]){
                    if(seen[u.fr] == -1){
                        seen[u.fr] = seen[b]^u.sc;
                        s.push(u.fr);
                    }
                    else{

                        if(seen[u.fr]^seen[b]^u.sc) check = false;
                    }
                }
            }
        }

        if(check) cout<<"yes"<<"\n";
        else cout<<"no"<<"\n";
    }

}
