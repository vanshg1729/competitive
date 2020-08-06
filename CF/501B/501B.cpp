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
    int q ; cin>>q;
    map<string,string> m;
    string a,b; cin>>a>>b;
    m[a] = b;
    q--;

    while(q--)
    {
        cin>>a>>b;
        bool f = true;
        for(auto n:m)
        {
            if(n.second==a)
            {
                f = false;
                m[n.first] = b;
            }
        }

        if(f) m[a] = b;
    }

    cout<<m.size()<<"\n";
    for(auto n:m)
    {
        cout<<n.first<<" "<<n.second<<"\n";
    }
}   
