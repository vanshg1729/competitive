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

    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<ll> v;
        for(int i = 0; i < n; i++){
            ll a; cin>>a;
            v.push_back(a);
        }

        int ans = 0;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            if(i == n-1){
                ans++;
                continue;
            }

            if(sum + v[i] < v[i+1]){
                ans++;
                sum+=v[i];
            }
        }

        cout<<ans<<"\n";
    }
}
