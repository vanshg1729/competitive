#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define ll long long


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int T; cin>>T;
    int t = T;
    while(T--){

        int n,d; cin>>n>>d;
        vector<pair<int,int>> v = {};
        v.push_back({0,0});

        for(int i = 1; i <= n; i++){
            char c; cin>>c;
            int type = 0;
            type = (c == 'S');
            cin>>c;
            int a; cin>>a;
            v.push_back({a,type});
        }

        v.push_back({d,0});
        
        int ans = 0;
        int curr = 0;
        vector<int> ba = {}; ba.push_back(0);

        for(int i = 1; i <= n+1; i++){

            if(v[curr].sc*v[i].sc and i - curr == 1){
                ba.push_back(v[i].fr);
            }
            else{
                ans = max(ans,v[i].fr - v[curr].fr);
                curr = i;
                if(v[i].sc == 0) ba.push_back(v[i].fr);
            }
        }

        for(int i = 1; i < ba.size(); i++){
            ans = max(ans,ba[i] - ba[i-1]);
        }

        cout<<"Case "<<t-T<<": "<<ans<<"\n";
    }
}
