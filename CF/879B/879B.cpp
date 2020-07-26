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
    
    ll n,k; cin>>n>>k;
    queue<pair<ll,ll>> q;
    for(int i=0;i<n;i++)
    {
        ll p; cin>>p;
        q.push({p,0});
    }

    if(k>=n-1)
    {
        cout<<n;
        return 0;
    }

    ll pow = 0;
    while(pow==0)
    {
        auto a = q.front();
        q.pop();
        auto b = q.front();

        if(a.second==k) pow = a.first;

        if(b.first > a.first)
        {
            q.front().second++;
            q.push({a.first,0});
        }
        else
        {
            q.front() = {a.first,a.second+1};
            q.push(b);
        }
    }

    cout<<pow;  
}   
   



