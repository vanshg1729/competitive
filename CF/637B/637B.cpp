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
    int n; cin>>n;
    stack<string> s;
    set<string> seen;
    for(int i=1;i<=n;i++)
    {
        string a; cin>>a;
        s.push(a);
    }

    while(!s.empty())
    {
        if(!seen.count(s.top()))
        {
            cout<<s.top()<<"\n";
            seen.insert(s.top());
        }
        s.pop();
    }
}   
