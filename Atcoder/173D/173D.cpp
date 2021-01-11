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

    int n; cin>>n;
    vector<int> v = {};
    for(int i = 1; i <= n; i++){
        int a; cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    ll ans = (ll)v[n-1];
    int k = 1;

    for(int i = n-2; i >= 0; i--){
        if(k == n-1) break;
        ans += (ll)v[i];
        k++;
        if(k == n-1) break;
        ans += (ll)v[i];
        k++;
    }

    cout<<ans;
}
