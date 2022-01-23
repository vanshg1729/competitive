/* https://atcoder.jp/contests/abc131/tasks/abc131_d */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = 1e5 + 10;
vector<pair<int,int> > v = {};
int n;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;

    for(int i = 1; i <= n; i++){
        int a,b; cin>>a>>b;
        v.push_back({b,a});
    }

    sort(v.begin(),v.end());

    int t = 0;
    bool ans = true;
    for(int i = 0; i < n; i++){
        t+=v[i].sc;
        if(t > v[i].fr){
            ans = false;
            break;
        }
    }

    if(ans) cout<<"Yes";
    else cout<<"No";
}
