#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    ll step ; cin>>step;
    ll ans = 0;
    stack<ll> s;
    s.push(1);
    for(int i=1;i<=step;i++)
    {
        string str; cin>>str;
        if(str=="add") ans+=s.top();
        if(str=="for")
        {
            ll n ; cin>>n;
            ll a = n*s.top();
            s.push(min(a,(ll)pow(2,32) ) );
        }
        if(str=="end") s.pop();
    }

    if(ans>(ll)(pow(2,32)-1) ) cout<<"OVERFLOW!!!";
    else cout<<ans;
}   
   
