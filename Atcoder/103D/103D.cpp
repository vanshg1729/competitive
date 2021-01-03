#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = 1e5 + 10;
vector<pair<int,int>> v = {};
int n,m;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;

    for(int i = 1; i <= m; i++){

        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end());
    pair<int,int> cur = v[0];

    int ans = 1;

    for(int i = 1; i < m; i++){

        if(v[i].fr >= cur.sc ){
            ans++;
            cur = v[i];
        }
        else{
            cur.fr = v[i].fr;
            cur.sc = min(cur.sc,v[i].sc);
        }
    }

    cout<<ans;
}
