#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll H;
ll f(ll h , ll count){
    if(h == 0) return 0;

    ll ans = count + f(h/2,2*count);
    return ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>H;
    cout<<f(H,(ll)1);
}
