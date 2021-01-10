#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double

struct data
{
    double fr,sc;
    int co;
};

bool comp(data a, data b){
    if(a.sc != b.sc) return a.sc < b.sc;
    return a.fr < b.fr;
}

bool overlap(data p1, data p2){
    if(p1.co == p2.co) return false;
    if(p1.fr < p2.sc and p1.sc >= p2.sc) return true;
    if(p2.fr < p1.sc and p2.sc >= p1.sc) return true;
    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,c; cin>>n>>c;
    vector<data> v = {};
    data end[40] = {};
    int ans = 0;

    for(int i = 1; i <= n; i++){
        db a,b; cin>>a>>b;
        a-= 0.5;
        int C; cin>>C;
        v.push_back({a,b,C});
    }

    sort(v.begin(),v.end(),comp);

    for(int i = 0; i < n; i++){
        data p1 = {v[i].fr,v[i].sc,v[i].co};

        for(int j = 1; j <= c; j++){
            if(end[j].sc == 0 or !overlap(p1,end[j])){
                end[j] = p1;
                ans = max(ans,j);
                break;
            }
        } 
    }

    cout<<ans;
}
