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
    string s; cin>>s;
    int n = s.size();
    stack<char> q;
    q.push(s[0]);

    for(int i=1;i<n;i++)
    {
        char a = s[i];
        if(!q.empty())
        {
            if(q.top()==a)
            {
                q.pop();
            }
            else 
            {
                q.push(a);
            }
        }
        else
        {
            q.push(a);
        }
    }
    

    string ans = "";
    while(!q.empty())
    {
        ans+=q.top();
        q.pop();
    }

    reverse(ans.begin(),ans.end());
    cout<<ans;

    
}   
