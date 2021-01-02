#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

int n;

ll f(){
    ll ans = 0;
    priority_queue<ll,vector<ll>,greater<ll>> q;
    for(int i = 1; i <= n; i++){
        ll a; cin>>a;
        q.push(a);
    }

    while(q.size() > 1){
        auto b = q.top();q.pop();
        auto a = q.top();q.pop();

        ans+=a+b;
        q.push(a+b);
    }

    return ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while(cin>>n){
        if(n == 0) return 0;
        cout<<f()<<"\n";
    }
}
