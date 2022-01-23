#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    while(T--){
        ll k; cin>>k;
        ll a = k/2;
        ll b = a;
        if(k % 2)b++;
        cout<<a*b<<"\n";
    }
}
